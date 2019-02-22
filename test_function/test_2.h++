//
// Created by wangheng on 2/17/19.
//

#ifndef ALGORITHMUNLOCK_TEST_2_H
#define ALGORITHMUNLOCK_TEST_2_H

/**
 * Testing C++ stl algorithm.
 */

#include "../stl/stl_primary.h++"
#include "../interview/tencent.h++"

using namespace stl;

namespace t2{
    void test_where_is_marble(){
        where_is_the_marble();
    }

    void test_max_continues_sum(){
        auto* tencent = new Tencent();
        tencent->max_continues_sum();
    }

    void test_max_continues_sum_2(){
        auto* tencent = new Tencent();
        tencent->max_continues_sum_2();
    }

    void test_max_continues_sum_3(){
        auto* tencent = new Tencent();
        int a[10] = {1,-2,3,2,2,-3,-5,9,2,-2};
        int best = tencent->max_continues_sum_3(a, 0, 10);
        cout<<"the max continues value is:"<<best<<endl;
    }

    void test_merge_sort(){
        auto* tencent = new Tencent();
        int a[10] = {1,-2,3,2,2,-3,-5,9,2,-2};
        int* T = new int[10];
        tencent->merge_sort(a, 0, 10, T);
        for(int i = 0;i<10;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }

    void test_float_number(){
        auto* tenc = new Tencent();
        tenc->float_number();
    }
}

#endif //ALGORITHMUNLOCK_TEST_2_H
