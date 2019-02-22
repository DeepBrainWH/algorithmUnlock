//
// Created by wangheng on 2/16/19.
//

#ifndef ALGORITHMUNLOCK_TENCENT_H
#define ALGORITHMUNLOCK_TENCENT_H

#include <iostream>
using namespace std;

class Tencent{
public:
    Tencent() = default;
    ~Tencent() = default;

    void print_matrix(){
        /**
         * 3    4   5   6
         * 4    5   9   8
         * 8    9   0   3
         * 2    5   7   4
         *
         * print: 3 4 5 6 8 3 4 7 5 2 8 4 5 9 0 9
         */
        int rows = 5;
        int cols = 5;
        int mat[rows][cols] = {
                {3,4,5,6,5},
                {4,5,9,8,3},
                {8,9,0,3,2},
                {2,5,7,4,5},
                {3,4,2,1,9}
        };
        cout<<"your input matrix is:\n";
        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                cout<<mat[i][j]<<"\t";
            }
            cout<<"\n";
        }
        cout<<endl;

        int start_row = 0;
        int end_row = rows-1;
        int start_col = 0;
        int end_col = cols-1;

        while (start_row <= end_row){
            for(int j = start_col;j<=end_col;j++){
                cout<<mat[start_row][j]<<" ";
            }
            for(int i = start_row+1;i<=end_row;i++){
                cout<<mat[i][end_col]<<" ";
            }
            for(int i = end_col-1;i>=start_col;i--){
                cout<<mat[end_row][i]<<" ";
            }
            for(int i = end_row-1;i>start_row;i--){
                cout<<mat[i][start_col]<<" ";
            }
            start_col ++;
            start_row ++;
            end_row --;
            end_col --;
        }
        cout<<endl;
    }

    void max_continues_sum(){
        int tot = 0;//计算次数
        int n = 10;
        int a[n] = {1,-2,3,2,2,-3,-5,9,2,-2};
        int best = a[0];
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                int sum = 0;
                for(int k = i;k<j;k++){sum += a[k];tot ++;}
                if(sum>best)best = sum;
            }
        }
        cout<<"max continue sum value is :"<<best<<endl;
        cout<<"calculate times is:"<<tot<<endl;
        //时间复杂度为:O(n^3)
    }

    void max_continues_sum_2(){
        //S_i = A_1+A_2+A_3+...+A_i则:A_i + A_(i+1) + A_(i+2) + A_j = S_j - S_i
        //利用以上算法公式推导求最大连续和.时间复杂度为O(n^2)
        int n = 10;
        int a[n] = {1,-2,3,2,2,-3,-5,9,2,-2};
        int best = a[0];
        int S[n];
        S[0] = a[0];

        for(int i = 1;i<n;i++){
            S[i] = S[i-1] + a[i];
        }

        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                best = max(best, S[j]-S[i]);
            }
        }
        cout<<"max continue sum value is :"<<best<<endl;
    }

    int max_continues_sum_3(int* a, int x, int y){//返回数组左开右闭区间[x, y)中的最大连续和
        //分治法求解
        //1.划分问题:把问题实例划分成子问题
        //2.递归求解:递归解决子问题
        //3.合并问题:合并子问题的解得到原问题的解
        if(y-x==1) return a[x];
        int m = x + (y-x)/2;//分治法第一步:划分成[x,m)和[m, y)
        int res_1 = max_continues_sum_3(a, x, m);
        int res_2 = max_continues_sum_3(a, m, y);
        int maxs = max(res_1, res_2);//分治法第二步:递归求解
        int v, L, R;
        v = 0;L = a[m-1];
        for(int i = m-1;i>=x;i--){
            L = max(L, v+=a[i]);
        }
        v = 0;R = a[m];
        for(int i = m;i<y;i++){
            R = max(R, v+=a[i]);
        }
        return max(maxs, L+R);
    }

    //分治法--merge sort
    void merge_sort(int* A, int l, int r, int* T){
        if(r-l>1){
            int m = l + (r-l)/2; //1.划分子问题
            this->merge_sort(A, l, m, T);//2.递归求解
            this->merge_sort(A, m, r, T);
            int p = l;
            int q = m;
            int i = l;
            while (p<m || q<r){
                if(q>=r || (p<m && A[p]<=A[q])) T[i++] = A[p++];
                else{
                    T[i++] = A[q++];
                }
            }
            for(int j = l;j<r;j++){
                A[j] = T[j];
            }
        }
    }

    int max(int a, int b){
        if (a>b)return a;
        else return b;
    }



};
#endif //ALGORITHMUNLOCK_TENCENT_H
