//
// Created by sakura on 2020/5/6.
//

#ifndef SAKURA_STL_TYPE_TRAITS_H
#define SAKURA_STL_TYPE_TRAITS_H
struct __true_type {
};
struct __false_type {
};
template<class _Tp>
struct __type_traits {
    typedef __true_type this_dummy_member_must_be_first;
    /* Do not remove this member. It informs a compiler which
       automatically specializes __type_traits that this
       __type_traits template is special. It just makes sure that
       things work if an implementation is using a template
       called __type_traits for something unrelated. */

    /* The following restrictions should be observed for the sake of
       compilers which automatically produce type specific specializations
       of this class:
           - You may reorder the members below if you wish
           - You may remove any of the members below if you wish
           - You must not rename members without making the corresponding
             name change in the compiler
           - Members you add will be treated like regular members unless
             you add the appropriate support in the compiler. */


    typedef __false_type has_trivial_default_constructor;
    typedef __false_type has_trivial_copy_constructor;
    typedef __false_type has_trivial_assignment_operator;
    typedef __false_type has_trivial_destructor;
    typedef __false_type is_POD_type;
};

template<class _Tp>
struct _Is_integer {
    typedef __false_type _Integral;
};

template<>
struct _Is_integer<int> {
    typedef __true_type _Integral;
};

template<>
struct _Is_integer<unsigned int> {
    typedef __true_type _Integral;
};

template<>
struct _Is_integer<bool> {
    typedef __true_type _Integral;
};

template<>
struct _Is_integer<char> {
    typedef __true_type _Integral;
};

template<>
struct _Is_integer<signed char> {
    typedef __true_type _Integral;
};

template<>
struct _Is_integer<unsigned char> {
    typedef __true_type _Integral;
};

template<>
struct _Is_integer<short> {
    typedef __true_type _Integral;
};

template<>
struct _Is_integer<unsigned short> {
    typedef __true_type _Integral;
};

template<>
struct _Is_integer<long> {
    typedef __true_type _Integral;
};


template<>
struct _Is_integer<unsigned long> {
    typedef __true_type _Integral;
};

#endif //SAKURA_STL_TYPE_TRAITS_H
