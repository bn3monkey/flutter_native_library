#include "../../include/Image/Image.hpp"
#include <cstring>
#include <Log/Log.hpp>

using namespace NativeLibrary;

bool Image::initialize()
{
    Bn3Monkey::Log::D(__FUNCTION__, "Image is initialized");
    _is_initialized = true;
}
void Image::release()
{
    if (_buffer) {
        delete[] _buffer;
        _buffer = nullptr;
    }
    _is_initialized = false;

    Bn3Monkey::Log::D(__FUNCTION__, "Image is released");
}

void Image::resize(size_t width, size_t height)
{
    Bn3Monkey::Log::D(__FUNCTION__, "Image resized (%d, %d)", width, height);
    if (_width != width || _height != height) {
        _width = width;
        _height = height;
        if (_buffer) {
            delete[] _buffer;
        }
        _buffer = new char[_width * _height * 4];
    }
    
}
bool Image::render(char* buffer, size_t length)
{
    Bn3Monkey::Log::D(__FUNCTION__, "Image is rendered (%d)", length);
    char diff = static_cast<char>(0xff / _height);
    for (size_t i = 0; i< _height; i++) {
        const char color = (char)(i * diff);
        char temp[4] {color, color, color, color};
        for (size_t i=0; i< _width; i++) {
            memcpy(buffer + 4*i, temp, 4);            
        }        
    }
    memcpy(buffer, _buffer, length);
    return true;
}
