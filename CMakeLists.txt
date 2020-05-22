cmake_minimum_required(VERSION 3.8)
project(sakura_stl)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp stl_config.h stl_construct.h type_traits.h stl_iterator_base.h stl_iterator.h stl_uninitialized.h stl_algobase.h stl_vector.h stl_alloc.h stl_list.h stl_hashtable.h stl_algo.h stl_pair.h stl_tree.h stl_hash_map.h stl_hash_fun.h stl_function.h stl_hash_set.h stl_map.h)

add_executable(sakura_stl ${SOURCE_FILES})