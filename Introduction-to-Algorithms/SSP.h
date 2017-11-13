/*
 * SSP.h
 *
 *  Created on: 2017年7月4日
 *      Author: xiaoquan
 */

#ifndef SSP_H_
#define SSP_H_
//24章 单源最短路径
#include<iostream>
#include<queue>
#include<climits>
using namespace std;

struct Node_Ssp{
	friend bool operator < (Node_Ssp n1,Node_Ssp n2){
		return n1.d < n2.d;
	}
	int d;//s到v的最短路径估计
	int pre;
	int num;//记录节点自身的序号
	Node_Ssp():d(0),pre(0),num(0){}
	Node_Ssp(int k,int p,int n):d(k),pre(p),num(n){}
};//定义节点

struct Edge_Ssp{
	int u;
	int v;
	int w;
	Edge_Ssp():u(0),v(0),w(0){}
	Edge_Ssp(int start,int end,int weight = 0):u(start),v(end),w(weight){}
};//定义边



class Graph_Ssp{
private:
	vector<Node_Ssp> V;
	vector<Edge_Ssp> E;
	vector<vector<Edge_Ssp> >Adj;
public:

	Graph_Ssp(int v_num,int e_num);
	void addEdge(int u,int v,int w = 0);

	void Initialize_Single_Source(int s);
	void Relax(int u,int v,int w);

	//Bellman Ford 算法
	/*使用于不含 非负环的有向图（无向图）*/
	bool Bellman_Ford(int s);

	/*Dijkstra算法
	 * 适用不含有负权的有向图*/
	vector<Node_Ssp>  Dijkstra(int s);

	void SSP_Print_Path(int s,int r);
	//r为终点
};

#endif /* SSP_H_ */
