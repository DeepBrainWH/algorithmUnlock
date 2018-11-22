//
// Created by wangheng on 2018-10-14.
//

#ifndef ALGORITHMUNLOCK_SORTALGORITHM_H
#define ALGORITHMUNLOCK_SORTALGORITHM_H

#include <iostream>
#include <string>

using namespace std;

template <class T>
class SortAlgorithm {
public:
    SortAlgorithm() = default;
    ~SortAlgorithm() = default;

    void selectSort(T *list, int len){
        int iMin;
        for(int i = 0;i< len-1;i++){
            iMin = i;
            for(int j = i+1;j<len;j++){
                if(list[j] < list[iMin]){
                    iMin = j;
                }
            }

            if(iMin != i)
                swap(list, i, iMin);
        }
    }

    void merge_sort(T* arr, int start, int end, T* result){
        if(end-start == 1){
            if(arr[start]>arr[end]){
                swap(arr, start, end);
            }
            return;
        } else if(end -start == 0){
            return;
        } else{
            merge_sort(arr, start, (end+start)/2, result);
            merge_sort(arr, (end+start)/2+1, end, result);
            merge(arr, start, end, result);
            for(int i = start; i<=end;i++){
                arr[i] = result[i];
            }
        }
    }

    /**
     * 快速排序 方法1
     * @param list
     * @param left
     * @param right
     */
    void quick_sort(T* list, int left, int right){
        int l = left;
        int r = right;
        T x = list[left];
        if(left >= right){
            return;
        }
        while (l < r){
            while (list[r] > x && l<r){
                r --;
            }
            if(l < r){
                list[l] = list[r];
                l++;
            }
            while (list[l] < x && l<r){
                l++;
            }
            if(l<r){
                list[r] = list[l];
                r--;
            }
        }
        list[l] = x;
        quick_sort(list, left, l-1);
        quick_sort(list, l+1, right);
    }

    /**
     * quick sort method two
     * @param arr
     * @param left
     * @param right
     */
    void quick_sort_method2(T* arr, int left, int right){
        T bin = arr[(left + right)/2];
        int i = left;
        int j = right;
        while (i<=j){
            while (arr[i]<bin && i<j)
                i++;
            while (arr[j]>bin && i<j)
                j--;
            if(i<=j){
                swap(arr, i, j);
                i++;
                j--;
            }
        }
        if(left<j)
            quick_sort_method2(arr, left, j);
        if(i<right)
            quick_sort_method2(arr, i, right);
    }

    /**
     * Quick sort. Book example.
     * @param arr
     * @param left
     * @param right
     */
    void quick_sort_book(T* arr, int left, int right){
        if(left>=right)
            return;
        int l = left;
        int r = right;
        int q;
        q = partition(arr, l, r);
        quick_sort_book(arr, l, q-1);
        quick_sort_book(arr, q+1, r);
    }

    /**
     * Insert sort.
     * @param arr
     * @param len
     */
    void insert_sort(T* arr, int len){
        int i = 1;
        int x;
        int j;
        while(i<len){
            x = arr[i];
            j = i-1;
            while (j>=0 && arr[j]>x){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = x;
            i++;
        }
    }
    /**
     * 对长度为5的单词进行字典排序
     * @param arr
     * @param arr_len
     * @param word_max_len
     */
    void world_count_sort(string* arr, int arr_len){
        char* a = new char[5]{'a', 'c', 'b', 'c', 'b'};
        this->count_sort(a, 5);
        for(int i = 0;i<5;i++){
            cout<<a[i]<<"\t";
        }

    }
private:
    void swap(T* list, int first, int last){
        T a;
        a = list[last];
        list[last] = list[first];
        list[first] = a;
    }

    T get_max_value(T* arr, int len){
        int max = arr[0];
        for(int i = 0;i<len;i++){
            if(arr[i]>max){
                max = arr[i];
            }
        }
        return max;
    }

    void merge(T* arr, int start, int end, T* result){
        int left_length = (end-start)/2 + 1;
        int left_index = start;
        int right_index = left_length + start;
        int result_index = start;
        while (left_index<start + left_length && right_index < end+1){
            if(arr[left_index] <= arr[right_index]){
                result[result_index] = arr[left_index];
                left_index++;
                result_index++;
            }else{
                result[result_index] = arr[right_index];
                result_index++;
                right_index++;
            }
        }
        while(left_index < start + left_length){
            result[result_index] = arr[left_index];
            left_index ++;
            result_index++;
        }
        while(right_index<end+1){
            result[result_index] = arr[right_index];
            result_index++;
            right_index++;
        }
    }

    /**
     * Count sort
     */
     void count_sort(char* arr, int len, int k=26){
         int* tmp = new int[k];
         //初始化临时数组
         for(int i = 0;i<k;i++){
             tmp[i] = 0;
         }
         //进行数值统计
         for(int i = 0;i<len;i++){
             tmp[(int)arr[i]-97] += 1;
         }
         int index = 0;
         for(int i = 0;i<26;i++){
             int f = tmp[i];
             while(tmp[i]>0){
                 arr[index] = (char)(i+97);
                 char ff = arr[index];
                 tmp[i]--;
                 index++;
             }
         }
         delete[] tmp;
     };

    /**
     * partition
     */
     int partition(T* arr, int l, int r){
         int flag = l;
         T tmp;
         for (int i = l;i<r;i++){
             if(arr[i]<arr[r]){
                 tmp = arr[flag];
                 arr[flag] = arr[i];
                 arr[i] = tmp;
                 flag++;
             }
         }
         tmp = arr[r];
         arr[r] = arr[flag];
         arr[flag] = tmp;
         return flag;

     }


};


#endif //ALGORITHMUNLOCK_SORTALGORITHM_H
