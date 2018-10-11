//
// Created by wangheng on 2018-10-11.
//

#ifndef ALGORITHMUNLOCK_SEARCHALGORITHM_H
#define ALGORITHMUNLOCK_SEARCHALGORITHM_H

#include <random>
#include <ctime>

class SearchAlgorithm {

public:

    SearchAlgorithm() = default;
    ~SearchAlgorithm() = default;

    /**
     * Linear search method
     * @param arr array that you want to search
     * @param len array's length
     * @param key key value
     * @return the key's index in arr
     */
    int liner_search(int* arr, int len, int key)
    {
        for(int i = 0; i < len;i++){
            if(arr[i] == key)
                return i;
            else
                return -1;
        }
        return -1;
    }

    /**
     * better search
     */
    int better_search(int * arr, int len, int key)
    {

        return -1;
    }

    /**
     * binary search no-recursive
     */
    int binary_search_no_recursive(const int* arr, int len, int key) {
        int low = 0;
        int high = len - 1;
        int mid;
        while (low <= high) {
            mid = (low + high) / 2;
            if (arr[mid] == key)
                return mid;
            else if (key > arr[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

    /**
     * binary search with recursive
     * @param arr: array
     * @param l: letf
     * @param r: right
     */
     int binary_search_recursive(int *arr, int l, int r, int key)
    {
         int mid = (l + r) / 2;
         if(r<l)
             return -1;
         if(arr[mid] < key)
             return binary_search_recursive(arr, mid + 1, r, key);
         else if(arr[mid] == key)
             return mid;
         else
             return binary_search_recursive(arr, l, mid - 1, key);
    }

    /**
     * sentinel linear search
     * @param arr
     * @param len
     * @param key
     * @return
     */
    int sentinel_linear_search(int* arr, int len, int key)
    {


        return -1;
    }

    int* get_sort_rand(int len){
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

    int* get_rand(int len){
        srand(static_cast<unsigned int>(time(nullptr)));
        int* a= new int[len];
        for(int i=0;i<len;i++){
            a[i] = rand() % 50;
        }
        return a;
    }


};


#endif //ALGORITHMUNLOCK_SEARCHALGORITHM_H
