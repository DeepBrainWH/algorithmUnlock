cmake_minimum_required(VERSION 3.10)
project(algorithmUnlock)

set(CMAKE_CXX_STANDARD 17)

add_executable(algorithmUnlock main.cpp SearchAlgorithm.h
        RecursiveAndOptimizer.h SortAlgorithm.h Utils.h
        heap.h++ graph/critical_path.h++ tree/binary_search_tree.h++
        algebra/tensor.h++ interview/tencent.h++ interview/microsoft.h++
        stl/stl_primary.h++ test_function/test_1.h++
        test_function/test_2.h++)