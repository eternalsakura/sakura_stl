//
// Created by sakura on 2020/5/18.
//

#ifndef SAKURA_STL_STL_HASHTABLE_H
#define SAKURA_STL_STL_HASHTABLE_H

#include "stl_config.h"
#include "stl_alloc.h"
#include "stl_iterator.h"
#include "stl_algo.h"
#include "stl_vector.h"

__STL_BEGIN_NAMESPACE
    template<class _Val>
    struct _Hashtable_node {
        _Hashtable_node *_M_next;
        _Val _M_val;
    };

    template<class _Val, class _Key, class _HashFcn, class _ExtractKey, class _EqualKey, class _Alloc = alloc>
    class hashtable;

    template<class _Val, class _Key, class _HashFcn,
            class _ExtractKey, class _EqualKey, class _Alloc>
    struct _Hashtable_iterator;

    template<class _Val, class _Key, class _HashFcn,
            class _ExtractKey, class _EqualKey, class _Alloc>
    struct _Hashtable_const_iterator;

    template<class _Val, class _Key, class _HashFcn,
            class _ExtractKey, class _EqualKey, class _Alloc>
    struct _Hashtable_iterator {
        typedef hashtable<_Val, _Key, _HashFcn, _ExtractKey, _EqualKey, _Alloc> _Hashtable;
        typedef _Hashtable_iterator<_Val, _Key, _HashFcn,
                _ExtractKey, _EqualKey, _Alloc> iterator;
        typedef _Hashtable_const_iterator<_Val, _Key, _HashFcn,
                _ExtractKey, _EqualKey, _Alloc> const_iterator;
        typedef _Hashtable_node<_Val> _Node;
        typedef forward_iterator_tag iterator_category;
        typedef _Val value_type;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;
        typedef _Val &reference;
        typedef _Val *pointer;

        _Node *_M_cur;
        _Hashtable *_M_ht;

        _Hashtable_iterator(_Node *__n, _Hashtable *__tab)
                : _M_cur(__n), _M_ht(__tab) {}

        _Hashtable_iterator() {}

        reference operator*() const { return _M_cur->_M_val; }

        pointer operator->() const { return &(operator*()); }

        iterator &operator++();

        iterator operator++(int);

        bool operator==(const iterator &__it) const { return _M_cur == __it._M_cur; }

        bool operator!=(const iterator &__it) const { return _M_cur != __it._M_cur; }
    };

    template<class _Val, class _Key, class _HashFcn,
            class _ExtractKey, class _EqualKey, class _Alloc>
    struct _Hashtable_const_iterator {
        typedef hashtable<_Val, _Key, _HashFcn, _ExtractKey, _EqualKey, _Alloc>
                _Hashtable;
        typedef _Hashtable_iterator<_Val, _Key, _HashFcn,
                _ExtractKey, _EqualKey, _Alloc>
                iterator;
        typedef _Hashtable_const_iterator<_Val, _Key, _HashFcn,
                _ExtractKey, _EqualKey, _Alloc>
                const_iterator;
        typedef _Hashtable_node<_Val> _Node;

        typedef forward_iterator_tag iterator_category;
        typedef _Val value_type;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;
        typedef const _Val &reference;
        typedef const _Val *pointer;

        const _Node *_M_cur;
        const _Hashtable *_M_ht;

        _Hashtable_const_iterator(const _Node *__n, const _Hashtable *__tab)
                : _M_cur(__n), _M_ht(__tab) {}

        _Hashtable_const_iterator() {}

        _Hashtable_const_iterator(const iterator &__it)
                : _M_cur(__it._M_cur), _M_ht(__it._M_ht) {}

        reference operator*() const { return _M_cur->_M_val; }

        pointer operator->() const { return &(operator*()); }

        const_iterator &operator++();

        const_iterator operator++(int);

        bool operator==(const const_iterator &__it) const { return _M_cur == __it._M_cur; }

        bool operator!=(const const_iterator &__it) const { return _M_cur != __it._M_cur; }
    };

    // Note: assumes long is at least 32 bits.
    enum {
        __stl_num_primes = 28
    };

    static const unsigned long __stl_prime_list[__stl_num_primes] =
            {
                    53ul, 97ul, 193ul, 389ul, 769ul,
                    1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
                    49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
                    1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
                    50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
                    1610612741ul, 3221225473ul, 4294967291ul
            };

    inline unsigned long __stl_next_prime(unsigned long __n) {
        const unsigned long *__first = __stl_prime_list;
        const unsigned long *__last = __stl_prime_list + (int) __stl_num_primes;
//        指向首个不小于 value 的元素的迭代器，或若找不到这种元素则为 last 。
        const unsigned long *pos = lower_bound(__first, __last, __n);
        return pos == __last ? *(__last - 1) : *pos;
    }

// Forward declaration of operator==.

    template<class _Val, class _Key, class _HF, class _Ex, class _Eq, class _All>
    class hashtable;

    template<class _Val, class _Key, class _HF, class _Ex, class _Eq, class _All>
    bool operator==(const hashtable<_Val, _Key, _HF, _Ex, _Eq, _All> &__ht1,
                    const hashtable<_Val, _Key, _HF, _Ex, _Eq, _All> &__ht2);

//    哈希表处理分配器的方式与其他容器有所不同。 如果我们使用的是符合标准的分配器，则哈希表无条件地拥有一
//    个成员变量来保存其分配器，即使这种情况发生在分配器类型的所有实例都相同的情况下。 这是因为，对于哈希
//    表，此额外的存储可以忽略不计。 另外，基类不能满足任何其他目的。 例如，它不会简化异常处理代码。
    template<class _Val, class _Key, class _HashFcn, class _ExtractKey, class _EqualKey, class _Alloc>
    class hashtable {
    public:
        typedef _Key key_type;
        typedef _Val value_type;
        typedef _HashFcn hasher;
        typedef _EqualKey key_equal;

        typedef size_t size_type;
        typedef ptrdiff_t difference_type;
        typedef value_type *pointer;
        typedef const value_type *const_pointer;
        typedef value_type &reference;
        typedef const value_type &const_reference;

    private:
        typedef _Hashtable_node<_Val> _Node;
        typedef _Alloc allocator_type;

        allocator_type get_allocator() const { return allocator_type(); }

    private:
        typedef simple_alloc<_Node, _Alloc> _M_node_allocator_type;

        _Node *_M_get_node() { return _M_node_allocator_type::allocate(1); }

        void _M_put_node(_Node *__p) { _M_node_allocator_type::deallocate(__p, 1); }

#define __HASH_ALLOC_INIT(__a)
    private:
        hasher _M_hash;
        key_equal _M_equals;
        _ExtractKey _M_get_key;
        vector<_Node *, _Alloc> _M_buckets;
        size_type _M_num_elements;
    public:
        typedef _Hashtable_iterator<_Val, _Key, _HashFcn, _ExtractKey, _EqualKey, _Alloc> iterator;
        typedef _Hashtable_const_iterator<_Val, _Key, _HashFcn, _ExtractKey, _EqualKey, _Alloc> const_iterator;
        friend struct
                _Hashtable_iterator<_Val, _Key, _HashFcn, _ExtractKey, _EqualKey, _Alloc>;
        friend struct
                _Hashtable_const_iterator<_Val, _Key, _HashFcn, _ExtractKey, _EqualKey, _Alloc>;
    public:
        hashtable(size_type __n, const _HashFcn &__hf, const _EqualKey &__eql, const _ExtractKey &__ext,
                  const allocator_type &__a = allocator_type())
                : __HASH_ALLOC_INIT(__a)
                  _M_hash(__hf),
                  _M_equals(__eql),
                  _M_get_key(__ext),
                  _M_buckets(__a),
                  _M_num_elements(0) {
            _M_initialize_buckets(__n);
        }

    private:
        size_type _M_next_size(size_type __n) const {
            return __stl_next_prime(__n);
        }

        void _M_initialize_buckets(size_type __n) {
            const size_type __n_buckets = _M_next_size(__n);
            _M_buckets.reserve(__n_buckets);
            _M_buckets.insert(_M_buckets.end(), __n_buckets, (_Node *) 0);
            _M_num_elements = 0;
        }


    };
__STL_END_NAMESPACE
#endif //SAKURA_STL_STL_HASHTABLE_H
