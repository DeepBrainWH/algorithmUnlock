//
// Created by wangheng on 2018-11-25.
//
#ifndef ALGORITHMUNLOCK_CRITICALPATH_H
#define ALGORITHMUNLOCK_CRITICALPATH_H
#pragma once

#include <iostream>
#include <stack>
#include <string>
using namespace std;

//邻接表节点
struct ArcNode{
    int start; //弧头顶点下表
    int end; //弧尾顶点下标
    int weight;//弧的权重
    ArcNode* next;//下一条弧
};
//头节点
struct VNode{
    ArcNode* firstarc;//第一条依附在该顶点的弧
    string data;
};

class CriticalPath {
private:
    int vexnum; //顶点个数
    int edge; //边的条数
    VNode* arc; //邻接表
    int* indegree; //各个顶点的入度情况
    stack<int> List; //拓扑序列中各个边的情况
    int * ve; //记录每个顶点的最早发生时间
    int * vl; //记录每个顶点最迟发生时间
public:
    CriticalPath(int vexnum, int edge);
    ~CriticalPath();//析构函数
    bool check_edge_value(int, int, int); //检查边的信息是否合法
    void createGraph();//创建一个新的图
    void print();//打印图的邻接表
    bool topological_sort();
    bool criticalPath();
};


#endif //ALGORITHMUNLOCK_CRITICALPATH_H
