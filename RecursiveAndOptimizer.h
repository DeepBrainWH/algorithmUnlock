//
// Created by wangheng on 2018-10-11.
//

#ifndef ALGORITHMUNLOCK_RECURSIVEANDOPTIMIZER_H
#define ALGORITHMUNLOCK_RECURSIVEANDOPTIMIZER_H


class RecursiveAndOptimizer {

public:

    /**
     * Using recursive method implement factorial(n!)
     */
    long factorial(long n){
        if(n>1)
            return n*factorial(n-1);
        else
            return 1;
    }

    /**
     * 使用递归方法求解斐波那契数列第n项的值
     * Using recursive method to get the value of Nth term in the Fibonacci sequence.
     */
    long fib(int n){
        //fib = [1,1,2,3,5,...,]
        //fib(n) = fib(n-2) + fib(n-1)
        if(n == 1 || n==2)
            return 1;
        return fib(n-1) + fib(n-2);
    }

    long fib(int num, long* result){
        if(num == 1 || num == 2){
            return 1;
        }
        if(result[num-1] != 0){
            return result[num-1];
        }
        result[num-1] = fib(num-1, result) + fib(num - 2, result);
        return result[num-1];
    }

};


#endif //ALGORITHMUNLOCK_RECURSIVEANDOPTIMIZER_H
