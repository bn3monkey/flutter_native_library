#ifndef __FLUTTER_NATIVE_LIBRARY_USBDEVICE__
#define __FLUTTER_NATIVE_LIBRARY_USBDEVICE__

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
        int initialize(HWND handle);
#elif __ANDROID__
        int initialize(void* handle);
#else
        int initialize();
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