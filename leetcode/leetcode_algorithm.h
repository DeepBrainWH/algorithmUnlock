//
// Created by wangheng on 4/8/19.
//

#ifndef ALGORITHMUNLOCK_LEETCODE_ALGORITHM_H
#define ALGORITHMUNLOCK_LEETCODE_ALGORITHM_H

#include "mla.h++"

void get_the_dumplication_number(){
    int number[5] = {3,3,0,1,2};
    mla* m = new mla();
    m->get_duplication_number(number, 5);
}

#endif //ALGORITHMUNLOCK_LEETCODE_ALGORITHM_H
