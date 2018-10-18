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
    int linear_search(const int* arr, int len, int key)
    {
        int index = -1;
        for(int i = 0; i < len;i++){
            if(arr[i] == key){
                index = i;
            }

        }
        return index;
    }

    /**
     * better search
     */
    int better_linear_search(const int * arr, int len, int key)
    {
        for(int i = 0;i<len; i++){
            if(arr[i] == key)
                return i;
        }


        return -1;
    }

    /**
     * sentinel-linear-search
     */
     int sentinel_linear_search(int* arr, int len, int key){
         int last = arr[len-1];
         arr[len-1] = key;
         int i = 0;
         while (arr[i] != key){
             i++;
         }
         arr[len-1] = last;
         if(i<len-1 || arr[len-1] == key)
             return i;
         else
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


    int* get_sort_rand(int len, int upbound){
        srand(static_cast<unsigned int>(time(nullptr)));
        int *a = new int[len];
        for(int i = 0;i<len;i++){
            if(i > 0){
                a[i] = a[i-1] + rand() % upbound;
            } else{
                a[i] = rand() % upbound;
            }
        }
        return a;
    }

    int* get_rand(int len, int upbound){
        srand(static_cast<unsigned int>(time(nullptr)));
        int* a= new int[len];
        for(int i=0;i<len;i++){
            a[i] = rand() % upbound;
        }
        return a;
    }


};


#endif //ALGORITHMUNLOCK_SEARCHALGORITHM_H
