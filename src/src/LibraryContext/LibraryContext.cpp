#include "LibraryContext.hpp"
#include <Log/Log.hpp>
#include <mutex>
#include <cassert>

using namespace NativeLibrary;

std::mutex global_mtx;
static LibraryContext* context;

LibraryContext::LibraryContext() {
    Bn3Monkey::Log::D(__FUNCTION__, "Library Context Created");
}
LibraryContext::~LibraryContext() {
    Bn3Monkey::Log::D(__FUNCTION__, "Library Context Removed");
}

bool LibraryContext::create(bool is_initialized)
{
    if (is_initialized) {
        std::lock_guard<std::mutex> lock(global_mtx);
        if (context) {
            delete context;
        }
        context = new LibraryContext();
        if (context == nullptr) {
            Bn3Monkey::Log::E(__FUNCTION__, "Library Context Allocation fail");
            return false;
        }

        context->_worker = std::thread {&LibraryContext::routine, context};
    }
    
    return true;
}
void LibraryContext::release()
{
    {
        std::lock_guard<std::mutex> lock(global_mtx);

        context->_worker.join();
        if (context) {
            delete context;
            context = nullptr;
        }
    }
}
bool LibraryContext::isInitialized()
{
    bool is_initialized {false};
    {
        std::lock_guard<std::mutex> lock(global_mtx);
        is_initialized = context != nullptr;
    }
    return is_initialized;
}

LibraryContext& LibraryContext::get()
{
    assert(LibraryContext::isInitialized());

    return *context;
}

void LibraryContext::routine()
{
    while(_is_running) {
        std::function<void()> task;
        {
            std::unique_lock<std::mutex> lock(_task_mtx);
            _task_cv.wait(lock, [&]() {
                return !_is_running || !_tasks.empty();
            });
            task = std::move(_tasks.front());
            _tasks.pop();
        }

        task();
    }
}

void convertedTask(const std::function<void(bool)>& onLoading, const std::function<void(int32_t, const char*)> onError, const std::function<NativeLibrary::Result()>& task)
{
    onLoading(true);
    
    auto ret = task();
    
    onLoading(false);
    
    if (ret.num != Result::Cause::SUCCESS)
    {
        onError(Result::getErrorNo(ret.num), ret.msg);
    }
}

void LibraryContext::runAsync(const std::function<NativeLibrary::Result()>& task)
{
    {
        std::unique_lock<std::mutex> lock(_task_mtx);
        auto asyncTask = std::bind(convertedTask, _onLoading, _onError, task);
        _tasks.push(asyncTask);
    }
    _task_cv.notify_all();
}