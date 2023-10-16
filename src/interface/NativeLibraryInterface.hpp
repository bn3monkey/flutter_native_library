#ifndef __NATIVE_LIBRARY_INTERFACE__
#define __NATIVE_LIBRARY_INTERFACE__

#include <stdint.h>

#if _WIN32
#include <windows.h>
#else
#include <pthread.h>
#include <unistd.h>
#endif

#if _WIN32
#define FFI_PLUGIN_EXPORT __declspec(dllexport)
#else
#define FFI_PLUGIN_EXPORT
#endif

FFI_PLUGIN_EXPORT int NativeLibrary_Global_initialize(int32_t arg1, char* arg2, float arg3, int64_t arg4);
FFI_PLUGIN_EXPORT void NativeLibrary_Global_release();
FFI_PLUGIN_EXPORT bool NativeLibrary_Global_isInitialized();
FFI_PLUGIN_EXPORT const char* NativeLibrary_Global_getNativeLibraryErrorInformation(int32_t err_no);
FFI_PLUGIN_EXPORT void NativeLibrary_Global_registerOnError(void (*onError)(int err_num, const char* err_str));
FFI_PLUGIN_EXPORT void NativeLibrary_Global_registerOnLoading(void (*onLoading)(bool is_loading));
FFI_PLUGIN_EXPORT void NativeLibrary_Global_runAsyncTask(int32_t millisecond, int32_t err_no);

FFI_PLUGIN_EXPORT int NativeLibrary_Image_initialize();
FFI_PLUGIN_EXPORT void NativeLibrary_Image_release();
FFI_PLUGIN_EXPORT void NativeLibrary_Image_resize(size_t width, size_t height);
FFI_PLUGIN_EXPORT bool NativeLibrary_Image_render(char* buffer, size_t length);

#endif