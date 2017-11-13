/*
 * ASP.h
 *
 *  Created on: 2017年7月4日
 *      Author: xiaoquan
 */

#ifndef ASP_H_
#define ASP_H_
//所有节点对的最短路径问题（all pairs shortest path）
//这里面的图表示方法用邻接矩阵表示
#include<vector>
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

#define inf 0x3fffffff;
typedef vector<vector<int> > matrix;
class Graph_ASP {
private:
	matrix W;//邻接矩阵
public:
	Graph_ASP(int n);
	void addEdge(int u,int v,int w);

	matrix Extend_Shortest_Paths(matrix A,matrix B);

	matrix Slow_All_Pairs_Shortest_Paths();

	matrix Faster_All_Pairs_Shorest_Paths();

	matrix Floyd_Warshall();

	void Print_Matrix(matrix a);//测试用

	~Graph_ASP(){
		W.clear();
	}
};

#endif /* ASP_H_ */
