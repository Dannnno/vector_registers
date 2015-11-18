#ifndef REGISTER_HELPER
#define REGISTER_HELPER 1

#include <immintrin.h>
#include <type_traits>
#include "select.hpp"

namespace registers {

    template <int width, typename T>
    class vector_register {
    public:
        using registerType = typename selector::select<
            selector::cond<width == 256 && std::is_same<T, double>::value, __m256d>,
            selector::cond<width == 256 && std::is_same<T, float>::value, __m256>,
            selector::cond<width == 128 && std::is_same<T, double>::value, __m128d>,
            selector::cond<width == 128 && std::is_same<T, float>::value, __m128>>::type;

        vector_register();
        vector_register(const registers::vector_register<width, T>& other);
        vector_register(registerType reg);
        vector_register(T* address);
        vector_register(T value);

        // vector_register<width, T>& operator+=(const vector_register<width, T> rhs);
        // vector_register<width, T>& operator+=(const registerType rhs);
        // vector_register<width, T>& operator+=(const T* address);
        // vector_register<width, T>& operator+=(const T value);

    private:
        registerType _register;
    };

    // template <int width, typename T>
    // vector_register<width, T> load_a(T* address);

    // template <int width, typename T>
    // vector_register<width, T> load(T* address);

    template <int width, typename T>
    vector_register<width, T> set1(T value);

    template <int width, typename T>
    vector_register<width, T> setZero();

    #include "registers-private.hpp"
}

#endif