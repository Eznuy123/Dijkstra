//
// Created by yunze on 2024/7/7.
//
#include "Dijkstra.h"

Graph_DG::Graph_DG(int vexnum, int edge) {
    this->vexnum = vexnum;
    this->edge = edge;

    arc = new int *[this->vexnum];
    dis = new Dis[this->vexnum];

    for (int i = 0; i < this->vexnum; i++) {
        arc[i] = new int[this->vexnum];
        for (int j = 0; j < this->vexnum; j++) {
            arc[i][j] = INT_MAX;

        }
    }
}

Graph_DG::~Graph_DG() {
    delete[] dis;
    for (int i = 0; i < this->vexnum; ++i) {
        delete[] this->arc[i];

    }
    delete arc;
}

bool Graph_DG::check_edge_value(int start, int end, int weight) {
    if (start < 1 || end < 1 || start > vexnum || end > vexnum || weight < 0) {
        return false;
    }
    return true;
}

void Graph_DG::creatGraph() {
    cout << "������ÿ���ߵ������յ㣨�����Ŵ�1��ʼ���Լ���Ȩ��" << endl;
    int start;
    int end;
    int weight;
    int count = 0;
    while (count != this->edge) {
        cin >> start >> end >> weight;
        while (!this->check_edge_value(start, end, weight)) {
            cout << "����ıߵ���Ϣ���Ϸ�������������" << endl;
            cin >> start >> end >> weight;
        }
        arc[start - 1][end - 1] = weight;
        count++;
    }
}

void Graph_DG::print() {
    cout << "ͼ���ڽӾ���Ϊ��" << endl;
    int count_row = 0;
    int count_col = 0;
    while (count_row != this->vexnum) {
        count_col = 0;
        while (count_col != this->vexnum) {
            if (arc[count_row][count_col] == INT_MAX)
                cout << "��" << " ";
            else
                cout << arc[count_row][count_col] << " ";
            ++count_col;
        }
        cout << endl;
        ++count_row;
    }
}

void Graph_DG::Dijkstra(int begin) {
    for (int j = 0; j < this->vexnum; ++j) {
        dis[j].path = "v" + to_string(begin) + "-->v" + to_string(j + 1);
        dis[j].value = arc[begin - 1][j];
    }
    dis[begin - 1].value = 0;
    dis[begin - 1].visit = true;

    int count = 1;
    while (count != this->vexnum) {
        int temp = 0;
        int min = INT_MAX;
        for (int i = 0; i < this->vexnum; i++) {
            if (!dis[i].visit && dis[i].value < min) {
                min = dis[i].value;
                temp = i;
            }
        }
        dis[temp].visit = true;
        count++;
        for (int i = 0; i < this->vexnum; ++i) {
            if (!dis[i].visit && arc[temp][i] != INT_MAX && (dis[temp].value + arc[temp][i]) < dis[i].value) {
                //����µõ��ı߿���Ӱ������Ϊ���ʵĶ��㣬�Ǿ;͸����������·���ͳ���
                dis[i].value = dis[temp].value + arc[temp][i];
                dis[i].path = dis[temp].path + "-->v" + to_string(i + 1);
            }
        }

    }
}

void Graph_DG::print_path(int begin) {
    string str;
    str = "v" + to_string(begin);
    cout << "��" << str << "Ϊ����ͼ�����·��Ϊ��" << endl;
    for (int i = 0; i != this->vexnum; i++) {
        if (dis[i].value != INT_MAX)
            cout << dis[i].path << "=" << dis[i].value << endl;
        else {
            cout << dis[i].path << "�������·����" << endl;
        }
    }
}
