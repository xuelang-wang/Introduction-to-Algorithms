/*
 * ASP.h
 *
 *  Created on: 2017��7��4��
 *      Author: xiaoquan
 */

#ifndef ASP_H_
#define ASP_H_
//���нڵ�Ե����·�����⣨all pairs shortest path��
//�������ͼ��ʾ�������ڽӾ����ʾ
#include<vector>
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

#define inf 0x3fffffff;
typedef vector<vector<int> > matrix;
class Graph_ASP {
private:
	matrix W;//�ڽӾ���
public:
	Graph_ASP(int n);
	void addEdge(int u,int v,int w);

	matrix Extend_Shortest_Paths(matrix A,matrix B);

	matrix Slow_All_Pairs_Shortest_Paths();

	matrix Faster_All_Pairs_Shorest_Paths();

	matrix Floyd_Warshall();

	void Print_Matrix(matrix a);//������

	~Graph_ASP(){
		W.clear();
	}
};

#endif /* ASP_H_ */
