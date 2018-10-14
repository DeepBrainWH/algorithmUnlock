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


private:
    void swap(T* list, int first, int last){
        T a;
        a = list[last];
        list[last] = list[first];
        list[first] = a;
    }

};


#endif //ALGORITHMUNLOCK_SORTALGORITHM_H
