//
// Created by wangheng on 2/16/19.
//

#ifndef ALGORITHMUNLOCK_TENCENT_H
#define ALGORITHMUNLOCK_TENCENT_H

#include <iostream>
#include <string>

using namespace std;

class Tencent {
public:
    Tencent() = default;

    ~Tencent() = default;

    void print_matrix() {
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
                {3, 4, 5, 6, 5},
                {4, 5, 9, 8, 3},
                {8, 9, 0, 3, 2},
                {2, 5, 7, 4, 5},
                {3, 4, 2, 1, 9}
        };
        cout << "your input matrix is:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << "\t";
            }
            cout << "\n";
        }
        cout << endl;

        int start_row = 0;
        int end_row = rows - 1;
        int start_col = 0;
        int end_col = cols - 1;

        while (start_row <= end_row) {
            for (int j = start_col; j <= end_col; j++) {
                cout << mat[start_row][j] << " ";
            }
            for (int i = start_row + 1; i <= end_row; i++) {
                cout << mat[i][end_col] << " ";
            }
            for (int i = end_col - 1; i >= start_col; i--) {
                cout << mat[end_row][i] << " ";
            }
            for (int i = end_row - 1; i > start_row; i--) {
                cout << mat[i][start_col] << " ";
            }
            start_col++;
            start_row++;
            end_row--;
            end_col--;
        }
        cout << endl;
    }

    void max_continues_sum() {
        int tot = 0;//计算次数
        int n = 10;
        int a[n] = {1, -2, 3, 2, 2, -3, -5, 9, 2, -2};
        int best = a[0];
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = 0;
                for (int k = i; k < j; k++) {
                    sum += a[k];
                    tot++;
                }
                if (sum > best)best = sum;
            }
        }
        cout << "max continue sum value is :" << best << endl;
        cout << "calculate times is:" << tot << endl;
        //时间复杂度为:O(n^3)
    }

    void max_continues_sum_2() {
        //S_i = A_1+A_2+A_3+...+A_i则:A_i + A_(i+1) + A_(i+2) + A_j = S_j - S_i
        //利用以上算法公式推导求最大连续和.时间复杂度为O(n^2)
        int n = 10;
        int a[n] = {1, -2, 3, 2, 2, -3, -5, 9, 2, -2};
        int best = a[0];
        int S[n];
        S[0] = a[0];

        for (int i = 1; i < n; i++) {
            S[i] = S[i - 1] + a[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                best = max(best, S[j] - S[i]);
            }
        }
        cout << "max continue sum value is :" << best << endl;
    }

    int max_continues_sum_3(int *a, int x, int y) {//返回数组左开右闭区间[x, y)中的最大连续和
        //分治法求解
        //1.划分问题:把问题实例划分成子问题
        //2.递归求解:递归解决子问题
        //3.合并问题:合并子问题的解得到原问题的解
        if (y - x == 1) return a[x];
        int m = x + (y - x) / 2;//分治法第一步:划分成[x,m)和[m, y)
        int res_1 = max_continues_sum_3(a, x, m);
        int res_2 = max_continues_sum_3(a, m, y);
        int maxs = max(res_1, res_2);//分治法第二步:递归求解
        int v, L, R;
        v = 0;
        L = a[m - 1];
        for (int i = m - 1; i >= x; i--) {
            L = max(L, v += a[i]);
        }
        v = 0;
        R = a[m];
        for (int i = m; i < y; i++) {
            R = max(R, v += a[i]);
        }
        return max(maxs, L + R);
    }

    //分治法--merge sort
    void merge_sort(int *A, int l, int r, int *T) {
        if (r - l > 1) {
            int m = l + (r - l) / 2; //1.划分子问题
            this->merge_sort(A, l, m, T);//2.递归求解
            this->merge_sort(A, m, r, T);
            int p = l;
            int q = m;
            int i = l;
            while (p < m || q < r) {
                if (q >= r || (p < m && A[p] <= A[q])) T[i++] = A[p++];
                else {
                    T[i++] = A[q++];
                }
            }
            for (int j = l; j < r; j++) {
                A[j] = T[j];
            }
        }
    }

    void pascal_triangle() {
        int pas[5][5] = {
                {1, 0, 0, 0, 0},
                {1, 1, 0, 0, 0},
                {1, 2, 1, 0, 0},
                {1, 3, 3, 1, 0},
                {1, 4, 6, 4, 1}
        };
        cout << "row: " << 4 << " col: " << 3 << " is: " << this->pascal_angle_fun(4 - 1, 3 - 1) << endl;
    }

    int arrange(int m, int n) {
        //m个A, n个B组成多少个排列
        if (m == 0 or n == 0) return 1;
        return arrange(m - 1, n) + arrange(m, n - 1);
    }

    void all_arrange_of_one_number(int n, int *a, int start_position) {
        /**
         * n: 要分解的数
         * a: 数组，划分分解的数据。start_position开始分解数据的位置。
         */
        /* 6
         * 5+1
         * 4+2,4+1+1
         * 3+3,3+2+1,3+1+1
         * 2+2+2,2+2+1+1,2+1+1+1+1
         * 1+1+1+1+1+1
         * 打印一个数的所有划分
         */
        if (n <= 0) {
            for (int i = 0; i < start_position; i++) {
                cout << a[i];
                if (i + 1 < start_position) cout << "+";
            }
            cout << endl;
            return;
        }
        for (int i = n; i > 0; i--) {
            a[start_position] = i;
            if (start_position > 0 and a[start_position - 1] < i)continue;
            all_arrange_of_one_number(n - i, a, start_position + 1);
        }
    }

    /*某财务部门结账时发现总金额不对头，很可能是漏了一笔或几笔，如果已知明细账目清单，能通过
     * 编程找到漏掉的是哪一笔或者几笔吗？
     * 如果有多种可能，则输出所有可能的情况。
     * 我们规定：用户输入的第一行是有错的总金额
     * 接下来是n行整数，分别表示每笔账目金额。
     * 要求程序输出，所有可能漏掉的金额组合。每个情况1行金额按照从小到大排列，中间使用空客分开。
     * 比如：
     * 用户输入：
     * 6
     * 5
     * 3
     * 2
     * 4
     * 3
     * 1
     * 表明：有错的总金额是6：明细共有5笔。
     * 此时程序应输出：
     * 1 3 3
     * 1 2 4
     * 3 4*/
    /*暴力枚举算法。*/
    void example_one(){
        int err_sum = 6;
        int a[5] = {3,2,4,3,1};
        int k = 0;
        int curr_sum = 0;
        bool b[5] = {false, false, false, false,false};
        int length = 5;
        this->example_one_func(err_sum, a, k, curr_sum, b, 5);
    }
    int max(int a, int b) {
        if (a > b)return a;
        else return b;
    }

private:
    int pascal_angle_fun(int m, int n) {
        if (n == 0) return 1;
        if (m == n or m == 0) return 1;
        return (this->pascal_angle_fun(m - 1, n - 1) + this->pascal_angle_fun(m - 1, n));
    }

    void example_one_func(int err_sum, int a[], int k, int curr_sum, bool b[], int length){
        /*err_sum:有错的和
         * a:明细
         * k:当前处理的位置
         * curr_sum: 前面元素和
         * b:记录元素取舍
         * length: a长度
         * */
        if(curr_sum > err_sum) return;
        if(curr_sum == err_sum){
            for(int i =0;i<length;i++){
                if(b[i] == false) cout<<a[i]<<" ";
            }
            cout<<endl;
            return;
        }
        if(k>=length) return;

        b[k] = false;
        example_one_func(err_sum, a, k+1, curr_sum, b, length);
        b[k] = true;
        curr_sum += a[k];
        example_one_func(err_sum, a, k+1, curr_sum, b, length);
        b[k] = false;
    }

};

#endif //ALGORITHMUNLOCK_TENCENT_H
