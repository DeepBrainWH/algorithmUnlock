//
// Created by wangheng on 2/13/19.
//

#ifndef ALGORITHMUNLOCK_TENSOR_H
#define ALGORITHMUNLOCK_TENSOR_H

#include <iostream>
template <class T>
class tensor {
public:
    int rows;
    int cols;
    T data[rows][cols];

    tensor(int rows, int cols, T data[rows][cols]){

    }

    tensor(int rows, int cols, T** data){

    }

    ~tensor(){
        delete data;
    }

    tensor<T> operator *(tensor<T> t){
        if(this->cols != t.rows){
            throw "the tensor1's rows must equal the tensor2's cols";
        }
        T data[this->rows][t.cols];
        tensor<T> result = new tensor<T>(this->rows, t.cols, data);
        for(int i = 0;i<this->rows;i++){
            for(int j = 0;j<this->cols;j++){

            }
        }
    }

};


#endif //ALGORITHMUNLOCK_TENSOR_H
