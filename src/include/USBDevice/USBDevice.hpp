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
        int initialize(void* handle);
        void release();

        int32_t handleMessage(UINT const message, WPARAM const wparam, LPARAM const lparam);

        bool detectConnection();
        void ignoreConnection();

        bool connect(int fd);
        void disconnect();
        bool activate();
        bool disactivate();
    };
}

#endif