//
// Created by wangheng on 2018-10-14.
//

#ifndef ALGORITHMUNLOCK_UTILS_H
#define ALGORITHMUNLOCK_UTILS_H
#include <random>
#include <ctime>

namespace utils{
    static int* get_unsort_range(int len){
        srand(static_cast<unsigned int>(time(nullptr)));
        int* a= new int[len];
        for(int i=0;i<len;i++){
            a[i] = rand() % 500;
        }
        return a;
    }

    static int* get_sort_range(int len){
        srand(static_cast<unsigned int>(time(nullptr)));
        int *a = new int[len];
        for(int i = 0;i<len;i++){
            if(i > 0){
                a[i] = a[i-1] + rand() % 15;
            } else{
                a[i] = rand() % 15;
            }
        }
        return a;
    }
}

#endif //ALGORITHMUNLOCK_UTILS_H
