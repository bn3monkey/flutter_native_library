#ifndef __FLUTTER_NATIVE_LIBRARY_IMAGE__
#define __FLUTTER_NATIVE_LIBRARY_IMAGE__

#include <cstdint>

namespace NativeLibrary 
{
    class Image
    {
        bool initialize();
        void release();

        void resize(size_t width, size_t height);
        bool render(char* buffer, size_t length);

    private:
        bool _is_initialized {false};
        char* _buffer {nullptr};
        size_t _width{0};
        size_t _height{0};
    }
}

#endif 