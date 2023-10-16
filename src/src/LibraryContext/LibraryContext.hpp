#ifndef __NATIVE_LIBRARY_LIBRARY_CONTEXT__
#define __NATIVE_LIBRARY_LIBRARY_CONTEXT__

#include <functional>
#include <thread>
#include <mutex>
#include <queue>
#include "../../include/Result/Result.hpp"


namespace NativeLibrary
{
    class LibraryContext
    {
    public:
        static bool create(bool is_initialized);
        static void release();
        static bool isInitialized();

        static LibraryContext& get();

        std::function<void(int, const char*)> _onError;
        std::function<void(bool)> _onLoading; 

        void runAsync(const std::function<NativeLibrary::Result()>& task);

    private:
        LibraryContext();
        virtual ~LibraryContext();
        
        void routine();

        std::thread _worker;
        std::atomic_bool _is_running;
        std::mutex _task_mtx;
        std::condition_variable _task_cv;
        std::queue<std::function<void()>> _tasks;
    };
}
#endif
