//
// Created by wangheng on 2018-10-14.
//

#ifndef ALGORITHMUNLOCK_SORTALGORITHM_H
#define ALGORITHMUNLOCK_SORTALGORITHM_H

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

    void merge_sort(T* list, int len){

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
            while (arr[i]<bin)
                i++;
            while (arr[j]>bin)
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
        T tmp = arr[r];
        while (l<r){
            while (arr[l]<tmp && l<r)
                l++;
            if(l<r){
                arr[r] = arr[l];
                r--;
            }
            while (arr[r]>tmp && l<r){
                r--;
            }
            if(l<r){
                arr[l] = arr[r];
                l++;
            }
        }
        arr[r] = tmp;
        quick_sort_book(arr, left, l-1);
        quick_sort_book(arr, r+1, right);
    }
    void insert_sort(int* arr, int len){
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



private:
    void swap(T* list, int first, int last){
        T a;
        a = list[last];
        list[last] = list[first];
        list[first] = a;
    }

};


#endif //ALGORITHMUNLOCK_SORTALGORITHM_H
