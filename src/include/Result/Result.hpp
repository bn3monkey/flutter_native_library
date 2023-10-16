#ifndef __NATIVE_LIBRARY_RESULT__
#define __NATIVE_LIBRARY_RESULT__

#include <cstdint>
#include <cstring>

namespace NativeLibrary
{
    class Result
    {
    public:
        enum class Cause : int32_t
        {
            SUCCESS,
            ARG1_WRONG,
            ARG2_WRONG,
            ARG3_WRONG,
            ARG4_WRONG,

            LENGTH,
        };

        static inline int32_t getErrorNo(const Result::Cause& cause) {
            return static_cast<int32_t>(cause);
        }
        Result(int32_t num) : num(static_cast<Cause>(num)), msg(messages[num]) {

        }

        
        const Cause num;
        const char* msg;

    private:
        static inline char* messages[static_cast<size_t>(Cause::LENGTH)] {
            "SUCCESS",

        };
    };
}
#endif