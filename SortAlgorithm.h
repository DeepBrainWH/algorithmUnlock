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

    void quick_sort(T* list, int left, int right){
        int l = left;
        int r = right;
        T x = list[left];
        if(left >= right){
            return;
        }
        while (l < r){
            while (list[r] < x && l<r){
                r --;
            }
            if(l < r){
                list[l] = list[r];
                l++;
            }
            while (list[l] > x && l<r){
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


private:
    void swap(T* list, int first, int last){
        T a;
        a = list[last];
        list[last] = list[first];
        list[first] = a;
    }

};


#endif //ALGORITHMUNLOCK_SORTALGORITHM_H
