#include "../../include/Global/Global.hpp"
#include "../LibraryContext/LibraryContext.hpp"

#include <Log/Log.hpp>


using namespace NativeLibrary;


bool Global::initialize(int32_t arg1, char* arg2, float arg3, int64_t arg4)
{
    Bn3Monkey::Log::D(__FUNCTION__, "Library is initialized");
    bool is_initalized = false;
    do
    {
        if (arg1 != 4)
        {
            Bn3Monkey::Log::E(__FUNCTION__, "arg1(%d) must be 4", arg1);
            break;
        }

        if (arg2[0] != 'a')
        {
            Bn3Monkey::Log::E(__FUNCTION__, "arg2[0](%c) must be 'a'", arg2[0]);
            break;
        }   

        if (arg2[1] != 'b')
        {
            Bn3Monkey::Log::E(__FUNCTION__, "arg2[1](%c) must be 'b'", arg2[1]);
            break;
        }   
        
        if (arg2[2] != 'c')
        {
            Bn3Monkey::Log::E(__FUNCTION__, "arg2[2](%c) must be 'c'", arg2[2]);
            break;
        }
        
        if (arg2[3] != 'd')
        {
            Bn3Monkey::Log::E(__FUNCTION__, "arg2[3](%c) must be 'd'", arg2[3]);
            break;
        }

        if (3.0 > arg3 || arg3 >= 4.0)
        {
            Bn3Monkey::Log::E(__FUNCTION__, "arg3 must be at least 3 but less than 4.", arg1);
            break;
        }
        
        if (arg4 != 4)
        {
            Bn3Monkey::Log::E(__FUNCTION__, "arg4 must be 4");
            break;
        }

        is_initalized = true;
    }
    while (false);

    return LibraryContext::create(is_initalized);
}

void Global::release()
{
    Bn3Monkey::Log::D(__FUNCTION__, "Library is released");
    LibraryContext::release();
}

bool Global::isInitialized()
{
    return LibraryContext::isInitialized();
}

void Global::registerOnError(void (*onError)(int err_num, const char* err_str))
{
    LibraryContext::get()._onError = onError;
}
void Global::registerOnLoading(void (*onLoading)(bool is_loading))
{
    LibraryContext::get()._onLoading = onLoading;
}