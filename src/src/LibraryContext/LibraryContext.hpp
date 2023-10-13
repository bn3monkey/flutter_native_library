#ifndef __NATIVE_LIBRARY_LIBRARY_CONTEXT__
#define __NATIVE_LIBRARY_LIBRARY_CONTEXT__

#include <functional>

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

    private:
        LibraryContext();
        virtual ~LibraryContext();

    };
}
#endif
