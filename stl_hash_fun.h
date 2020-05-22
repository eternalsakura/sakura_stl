//
// Created by sakura on 2020/5/22.
//

#ifndef SAKURA_STL_STL_HASH_FUN_H
#define SAKURA_STL_STL_HASH_FUN_H

#include <cstddef>
#include "stl_config.h"
//template <class _Key> struct hash { };
__STL_BEGIN_NAMESPACE
    inline size_t __stl_hash_string(const char *__s) {
        unsigned long __h = 0;
        for (; *__s; ++__s) {
            __h = 5 * __h + *__s;
        }
        return size_t(__h);
    }

    template<class _Key>
    struct hash {
    };

    template<>
    struct hash<char *> {
        size_t operator()(const char *__s) const { return __stl_hash_string(__s); }
    };

    template<>
    struct hash<const char *> {
        size_t operator()(const char *__s) const { return __stl_hash_string(__s); }
    };

    template<>
    struct hash<char> {
        size_t operator()(char __x) const { return __x; }
    };

    template<>
    struct hash<unsigned char> {
        size_t operator()(unsigned char __x) const { return __x; }
    };

    template<>
    struct hash<signed char> {
        size_t operator()(unsigned char __x) const { return __x; }
    };

    template<>
    struct hash<short> {
        size_t operator()(short __x) const { return __x; }
    };

    template<>
    struct hash<unsigned short> {
        size_t operator()(unsigned short __x) const { return __x; }
    };

    template<>
    struct hash<int> {
        size_t operator()(int __x) const { return __x; }
    };

    template<>
    struct hash<unsigned int> {
        size_t operator()(unsigned int __x) const { return __x; }
    };

    template<>
    struct hash<long> {
        size_t operator()(long __x) const { return __x; }
    };

    template<>
    struct hash<unsigned long> {
        size_t operator()(unsigned long __x) const { return __x; }
    };
__STL_END_NAMESPACE
#endif //SAKURA_STL_STL_HASH_FUN_H
