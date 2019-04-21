cmake_minimum_required(VERSION 3.10)
project(algorithmUnlock)

set(CMAKE_CXX_STANDARD 17)
include_directories("./lib/include")

add_executable(algorithmUnlock main.cpp algebra/SearchAlgorithm.h
        algebra/RecursiveAndOptimizer.h algebra/SortAlgorithm.h Utils.h
        algebra/heap.h++ graph/critical_path.h++ tree/binary_search_tree.h++
        algebra/tensor.h++ interview/tencent.h++ interview/microsoft.h++
        stl/stl_primary.h++ test_function/test_1.h++
        test_function/test_2.h++ structure/myCircleQueue.hpp)