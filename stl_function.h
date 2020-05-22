//
// Created by sakura on 2020/5/22.
//

#ifndef SAKURA_STL_STL_FUNCTION_H
#define SAKURA_STL_STL_FUNCTION_H

#include "stl_config.h"

__STL_BEGIN_NAMESPACE

    template<class _Arg, class _Result>
    struct unary_function {
        typedef _Arg argument_type;   ///< @c argument_type is the type of the
        ///     argument (no surprises here)

        typedef _Result result_type;  ///< @c result_type is the return type
    };
    template<class _Arg1, class _Arg2, class _Result>
    struct binary_function {
        typedef _Arg1 first_argument_type;   ///< the type of the first argument
        ///  (no surprises here)

        typedef _Arg2 second_argument_type;  ///< the type of the second argument
        typedef _Result result_type;         ///< type of the return type
    };

    template<class _Tp>
    struct equal_to : public binary_function<_Tp, _Tp, bool> {
        bool operator()(const _Tp &__x, const _Tp &__y) const { return __x == __y; }
    };

    // select1st and select2nd are extensions: they are not part of the standard.
    template<class _Pair>
    struct _Select1st : public unary_function<_Pair, typename _Pair::first_type> {
        const typename _Pair::first_type &operator()(const _Pair &__x) const {
            return __x.first;
        }
    };

    template<class _Pair>
    struct _Select2nd : public unary_function<_Pair, typename _Pair::second_type> {
        const typename _Pair::second_type &operator()(const _Pair &__x) const {
            return __x.second;
        }
    };

    template<class _Tp>
    struct _Identity : public unary_function<_Tp, _Tp> {
        const _Tp &operator()(const _Tp &__x) const { return __x; }
    };


__STL_END_NAMESPACE
#endif //SAKURA_STL_STL_FUNCTION_H
