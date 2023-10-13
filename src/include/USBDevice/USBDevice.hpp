#ifndef __FLUTTER_NATIVE_LIBRARY_IMAGE__
#define __FLUTTER_NATIVE_LIBRARY_IMAGE__

#include <cstdint>
#ifdef _WIN32
#include <Windows.h>
#endif


namespace NativeLibrary 
{
    class USBDevice
    {
    public:
#ifdef _WIN32
        bool initialize(HWND handle);
#elif __ANDROID__
        bool initialize(void* handle);
#else
        bool initialize();
#endif

        void release();

#ifdef _WIN32
        int32_t handleMessage(UINT const message, WPARAM const wparam, LPARAM const lparam);
#endif
        bool detectConnection();
        void ignoreConnection();

        bool connect(int fd);
        void disconnect();
        bool activate();
        bool disactivate();
    };
}

#endif