#ifndef CONDITIONAL_SELECT
#define CONDITIONAL_SELECT 1

#include <type_traits>

namespace selector {
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