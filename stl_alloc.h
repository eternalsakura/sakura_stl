//
// Created by sakura on 2020/5/10.
//

#ifndef SAKURA_STL_STL_ALLOC_H
#define SAKURA_STL_STL_ALLOC_H

#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include "stl_config.h"
#include "stl_construct.h"

__STL_BEGIN_NAMESPACE
    template<int __inst>
    class __malloc_alloc_template {
    public:
        static void *allocate(size_t __n) {
            void *__result = malloc(__n);
            if (0 == __result) {
                fprintf(stderr, "out of memory\n");
                exit(1);
            }
            return __result;
        }

        static void deallocate(void *__p, size_t /* __n */) {
            free(__p);
        }

        static void *reallocate(void *__p, size_t/* old_sz */, size_t __new_sz) {
            void *__result = realloc(__p, __new_sz);
            if (0 == __result) {
                fprintf(stderr, "out of memory\n");
                exit(1);
            }
            return __result;
        }
    };

    typedef __malloc_alloc_template<0> malloc_alloc;

    template<class _Tp, class _Alloc>
    class simple_alloc {
    public:
        static _Tp *allocate(size_t __n) {
            return 0 == __n ? 0 : (_Tp *) _Alloc::allocate(__n * sizeof(_Tp));
        }

        static _Tp *allocate(void) {
            return (_Tp *) _Alloc::allocate(sizeof(_Tp));
        }

        static void deallocate(_Tp *__p, size_t __n) {
            if (0 != __n) {
                _Alloc::deallocate(__p, __n * sizeof(_Tp));
            }
        }

        static void deallocate(_Tp *__p) {
            _Alloc::deallocate(__p, sizeof(_Tp));
        }
    };

    typedef malloc_alloc alloc;

    template<class _Tp>
    class allocator {
        typedef alloc _Alloc;
    public:
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef _Tp *pointer;
        typedef const _Tp *const_pointer;
        typedef _Tp &reference;
        typedef const _Tp &const_reference;
        typedef _Tp value_type;
        template<class _Tp1>
        struct rebind {
            typedef allocator<_Tp1> other;
        };

        allocator() noexcept {}

        allocator(const allocator &) noexcept {}

        template<class _Tp1>
        allocator(const allocator<_Tp1> &) noexcept {}

        ~allocator() noexcept {}

        pointer address(reference __x) const {
            return &__x;
        }

        const_pointer address(const_reference &__x) const {
            return &__x;
        }

        _Tp *allocate(size_type __n, const void * = 0) {
            return __n != 0 ? static_cast<_Tp *>(_Alloc::allocate(__n * sizeof(_Tp))) : 0;
        }

        void deallocate(pointer __p, size_type __n) {
            _Alloc::deallocate(__p, __n * sizeof(_Tp));
        }

        size_type max_size() const noexcept {
            return size_t(-1) / sizeof(_Tp);
        }

        void construct(pointer __p, const _Tp &__val) { sakura_stl::construct(__p, __val); }

        void destroy(pointer __p) { sakura_stl::destroy(__p); }
    };

    template<>
    class allocator<void> {
    public:
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef void *pointer;
        typedef const void *const_pointer;
        typedef void value_type;

        template<class _Tp1>
        struct rebind {
            typedef allocator<_Tp1> other;
        };
    };
    // There are always two members: allocator_type, which is a standard-
    // conforming allocator type for allocating objects of type _Tp, and
    // _S_instanceless, a static const member of type bool.  If
    // _S_instanceless is true, this means that there is no difference
    // between any two instances of type allocator_type.  Furthermore, if
    // _S_instanceless is true, then _Alloc_traits has one additional
    // member: _Alloc_type.  This type encapsulates allocation and
    // deallocation of objects of type _Tp through a static interface; it
    // has two member functions, whose signatures are
    //    static _Tp* allocate(size_t)
    //    static void deallocate(_Tp*, size_t)

    // The fully general version.
    template<class _Tp, class _Allocator>
    struct _Alloc_traits {
        static const bool _S_instanceless = false;
        ////    调用模板类限定的模板函数时，即形如：A<typename_a>::member_function<typename_b>()这样的调用时;
        ////    必须使用关键字template进行说明，即改为：A<typename_a>:: template member_function<typename_b>();
        ////    Use 'template' keyword to treat 'rebind' as a dependent template name (fix available)
        //    typedef typename _Allocator::template rebind<_Tp>::other allocator_type;
        typedef typename _Allocator::template rebind<_Tp>::other
                allocator_type;
    };

    // The version for the default allocator.
    template<class _Tp, class _Tp1>
    struct _Alloc_traits<_Tp, allocator<_Tp1>> {
        static const bool _S_instanceless = true;
        typedef simple_alloc<_Tp, alloc> _Alloc_type;
        typedef allocator<_Tp> allocator_type;
    };
__STL_END_NAMESPACE
#endif //SAKURA_STL_STL_ALLOC_H
