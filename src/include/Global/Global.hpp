#ifndef __NATIVE_LIBRARY_GLOBAL__
#define __NATIVE_LIBRARY_GLOBAL__

#include <cstdint>

namespace NativeLibrary
{
    namespace Global
    {
        bool initialize(int32_t arg1, char* arg2, float arg3, int64_t arg4);
        void release();
        bool isInitialized();

        void registerOnError(void (*onError)(int err_num, const char* err_str));
        void registerOnLoading(void (*onLoading)(bool is_loading));
    }
}

#endif