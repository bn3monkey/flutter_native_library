#include "../../include/USBDevice/USBDevice.hpp"
#include <cstring>
#include <Log/Log.hpp>

using namespace NativeLibrary;

#ifdef _WIN32
int32_t USBDevice::initialize(HWND handle)
{
    Bn3Monkey::Log::D(__FUNCTION__, "USB Device(Windows) is initialized");
}
#elif __ANDROID__
int32_t USBDevice::initialize(void* handle)
{
    Bn3Monkey::Log::D(__FUNCTION__, "USB Device(Android) is initialized");
}
#else
int32_t USBDevice::initialize()
{
    Bn3Monkey::Log::D(__FUNCTION__, "USB Device(Linux) is initialized");
}
#endif

void USBDevice::release()
{
    Bn3Monkey::Log::D(__FUNCTION__, "USB Device is released");
}

#ifdef _WIN32
int32_t USBDevice::handleMessage(UINT const message, WPARAM const wparam, LPARAM const lparam)
{
    Bn3Monkey::Log::D(__FUNCTION__, "Handle Message");
}
#endif
bool USBDevice::detectConnection()
{
    Bn3Monkey::Log::D(__FUNCTION__, "detect Connection");
}
void USBDevice::ignoreConnection()
{
    Bn3Monkey::Log::D(__FUNCTION__, "ignoreConnection");
}
bool USBDevice::connect(int fd)
{
    Bn3Monkey::Log::D(__FUNCTION__, "connect");
}
void USBDevice::disconnect()
{
    Bn3Monkey::Log::D(__FUNCTION__, "disconnect");
}
bool USBDevice::activate()
{
    Bn3Monkey::Log::D(__FUNCTION__, "activate");
}
bool USBDevice::disactivate()
{
    Bn3Monkey::Log::D(__FUNCTION__, "disactivate");
}