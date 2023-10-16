#ifndef __NATIVE_LIBRARY_GLOBAL__
#define __NATIVE_LIBRARY_GLOBAL__

#include <cstdint>

namespace NativeLibrary
{
    namespace Global
    {
        int initialize(int32_t arg1, char* arg2, float arg3, int64_t arg4);
        void release();
        bool isInitialized();

        const char* getNativeLibraryErrorInformation(int32_t_err_no);

        void registerOnError(void (*onError)(int err_num, const char* err_str));
        void registerOnLoading(void (*onLoading)(bool is_loading));
        void runAsyncTask(int32_t millisecond, int32_t err_no);
    }
}

#endif