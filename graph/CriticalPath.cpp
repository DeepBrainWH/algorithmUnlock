//
// Created by wangheng on 2018-11-25.
//

#include "CriticalPath.h"

CriticalPath::CriticalPath(int vexnum, int edge) {
    /*
    初始化一些基本的信息，
    包括边和顶点个数，各个顶点入度数组，邻接表的等
    */
    this->vexnum = vexnum;
    this->edge = edge;
    this->arc = new VNode[this->vexnum];
    this->indegree = new int[this->vexnum];
    this->ve = new int[this->vexnum];
    this->vl = new int[this->vexnum];
    for (int i = 0; i < this->vexnum; i++) {
        this->indegree[i] = 0;
        this->ve[i] = 0;
        this->arc[i].firstarc = nullptr;
        this->arc[i].data = "v" + to_string(i + 1);
    }
}

CriticalPath::~CriticalPath() = default;

bool CriticalPath::check_edge_value(int, int, int) {
    return false;
}

void CriticalPath::createGraph() {

}

void CriticalPath::print() {

}

bool CriticalPath::topological_sort() {
    return false;
}

bool CriticalPath::criticalPath() {
    return false;
}
