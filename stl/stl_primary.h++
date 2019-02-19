//
// Created by wangheng on 2/17/19.
//

#ifndef ALGORITHMUNLOCK_STL_PRIMARY_H
#define ALGORITHMUNLOCK_STL_PRIMARY_H

#include <cstdio>
#include <algorithm>

namespace stl{
    void where_is_the_marble(){
        //In this question, now there are N marbles, each marbles are wrote an integer(this integer number more than 0),
        //first we need to sort these numbers
        const int maxn = 1000;
        int n, q, x, a[maxn], kase=0;
        while (scanf("%d%d", &n, &q)==2 and n){
            printf("CASE# %d\n", ++kase);
            printf("PLEASE INPUT THE %d NUMBERS\n", n);
            for(int i = 0;i<n;i++){
                scanf("%d", &a[i]);
            }
            sort(a, a+n);
            while (q--){
                scanf("%d", &x);
                int p = lower_bound(a, a+n, x) - a;
                if(a[p] == x){
                    if(p==0){
                        printf("%d found at %d\n", x, p+n);
                    } else{
                        printf("%d found at %d\n", x, p);
                    }

                }
                else printf("%d not found!\n", x);
                printf("end the %d times question\n", q);
            }
            printf("CASE END! COME IN THE SECOND CASE!\n");
        }
    }
}
#endif //ALGORITHMUNLOCK_STL_PRIMARY_H
