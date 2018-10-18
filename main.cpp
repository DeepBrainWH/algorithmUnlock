#include <iostream>
#include "SearchAlgorithm.h"
#include "SortAlgorithm.h"
#include "RecursiveAndOptimizer.h"
#include "Utils.h"

using namespace std;

void test_search_function(){
    auto * algorithm = new SearchAlgorithm();
    int *a = algorithm->get_sort_rand(10, 50);
    for(int i = 0;i<10;i++){
        cout<<a[i]<<"   ";
    }
    cout<<endl;
    int index = algorithm->binary_search_no_recursive(a, 10, a[6]);
    cout<<"the value "<<a[6]<<" 's position in "<<index<<endl;

    int index2 = algorithm->binary_search_recursive(a, 0, 10, a[9]);
    cout<<index2<<endl;
}

void test_sentinel_linear_search(){
    auto* algorithm = new SearchAlgorithm();
    int* a = algorithm->get_rand(30, 50);
    for(int i = 0;i<30;i++){
        cout<<a[i]<<"  ";
    }
    cout<<endl;
    int index = algorithm->linear_search(a, 30, 51);
    cout<<"the value "<<51<<" 's position in "<<index<<endl;


}

void test_sort(){
    auto* sortAlgorithm = new SortAlgorithm<int>();
    int* a = utils::get_unsort_range(20, 500);
    for(int i = 0;i<20;i++){
        cout<<a[i]<<"  ";
    }
    cout<<"\n"<<"====================="<<endl;
    sortAlgorithm->selectSort(a, 20);
    for(int i = 0;i<20;i++){
        cout<<a[i]<<"  ";
    }
}

void test_quick_sort(){
    auto* sort = new SortAlgorithm<int>();
    int* list = utils::get_unsort_range(100, 500);
    sort->quick_sort(list, 0, 99);
    for(int i = 0;i<100;i++){
        cout<<list[i]<<"\t";
    }
    cout<<endl;
}

void test_quick_sort_method2(){
    auto* sort = new SortAlgorithm<int>();
    int* list = utils::get_unsort_range(100, 500);
    sort->quick_sort_method2(list, 0, 99);
    for(int i = 0;i<100;i++){
        cout<<list[i]<<"\t";
    }
    cout<<endl;
}

void test_fib(){
    auto* recursive = new RecursiveAndOptimizer();
    cout<<"fib: "<<recursive->fib(4)<<endl;
}

void test_factorial(){
    auto* recursive = new RecursiveAndOptimizer();
    cout<<"factorial:"<<recursive->factorial(4)<<endl;
}

void test_linear_search(){

}


int main() {
//    test_search_function();
//    test_sort();
//    test_quick_sort();
    test_sentinel_linear_search();
//    test_quick_sort_method2();
//    test_fib();
//    test_factorial();

    return 0;

}