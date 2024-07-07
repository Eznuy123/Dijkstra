//
// Created by yunze on 2024/7/7.
//

#ifndef UNTITLED_DIJKSTRA_H
#define UNTITLED_DIJKSTRA_H
#pragma once

#include <iostream>
#include <string>

using namespace std;

struct Dis {
    string path;
    int value;
    bool visit;

    Dis() {
        visit = false;
        value = 0;
        path = "";
    }
};

class Graph_DG {
private:
    int vexnum;
    int edge;
    int **arc;
    Dis *dis;

public:
    Graph_DG(int vexnum, int edge);

    ~Graph_DG();

    bool check_edge_value(int start, int end, int weight);

    void creatGraph();

    void print();

    void Dijkstra(int begin);

    void print_path(int);
};

#endif //UNTITLED_DIJKSTRA_H
