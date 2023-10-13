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
    }
    
    return true;
}
void LibraryContext::release()
{
    {
        std::lock_guard<std::mutex> lock(global_mtx);
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