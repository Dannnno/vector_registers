I've been learning about vectorization and decided I wanted a nicer interface than the intrinsics, so I started writing a little wrapper library (nowhere near as fancy as [Agner Fog's][1], but a decent learning experience).  Eventually I at least want to provide wrappers for almost everything [here][2], but for now I have the following ([GitHub][3]):


registers.hpp

    #ifndef VECTOR_REGISTERS
    #define VECTOR_REGISTERS1
    
    #include <immintrin.h>
    #include <type_traits>
    #include "select.h"
    
    namespace registers {
    
        template <int width, typename T>
        struct vector_register {
        	using registerType = typename select::select<
        	    select::cond<width == 256 && std::is_same<T, double>::value, __m256d>,
        	    select::cond<width == 256 && std::is_same<T, float>::value, __m256>,
        	    select::cond<width == 128 && std::is_same<T, double>::value, __m128d>,
        	    select::cond<width == 128 && std::is_same<T, float>::value, __m128>>::type;
            using contentsType = T;
    
            vector_register();
        	vector_register(registerType register_);
            vector_register(const vector_register<width, T>& reg);
            vector_register(T* address);
            vector_register(T value);
    
            vector_register<width, T>& operator+=(const registerType register_);
            vector_register<width, T>& operator+=(const vector_register<width, T> rhs);
            vector_register<width, T>& operator+=(const T* address);
            vector_register<width, T>& operator+=(const T value);
        
        	registerType _register;
        };
    
        template <int width, typename T>
        vector_register<width, T> load_a(T* address);
    
        template <int width, typename T>
        vector_register<width, T> load(T* address);
    
        #include "registers-private.hpp"
    }
    
    #endif

registers-private.hpp

select.hpp

    #ifndef CONDITIONAL_SELECT
    #define CONDITIONAL_SELECT1
    
    #include <type_traits>
    
    namespace select {
        // Adapted from http://stackoverflow.com/a/32785263/3076272
        template<bool B, typename T>
        struct cond
        {
            static constexpr bool value = B;
            using type = T;
        };
    
        template<typename Head, typename... Tail>
        struct select
        {
            using type = std::conditional<Head::value, typename Head::type, typename select<Tail...>::type>;
        };
    
        template <typename T>
        struct select<T>
        {
            using type = T;
        };
    
        template <bool B, typename T>
        struct select<cond<B, T>>
        {
            using type = std::conditional<B, T, void>;
        };
    }
    
    #endif





  [1]: http://www.agner.org/optimize/vectorclass.pdf
  [2]: http://www3.in.tum.de/~finis/x86-intrin-cheatsheet-v2.1.pdf
  [3]: https://github.com/Dannnno/vector_registers