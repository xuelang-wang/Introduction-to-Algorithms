/*
 * MST.h
 *
 *  Created on: 2017年7月1日
 *      Author: xiaoquan
 */

#ifndef MST_H_
#define MST_H_

#include<queue>
#include<climits>
using namespace std;

struct Node_Mst{
	friend bool operator < (Node_Mst n1,Node_Mst n2){//相当于greater作用
		return n1.key > n2.key;
	}

	bool vis;//用于记录是否在优先队列里
	int key;
	int pre;
	int num;//记录节点自身的序号
	Node_Mst():vis(false),key(INT_MAX),pre(0),num(0){}
	Node_Mst(bool vi,int k,int p,int n):vis(vi),key(k),pre(p),num(n){}
};//定义节点

struct Edge_Mst{
	int u;
	int v;
	int w;
	Edge_Mst():u(0),v(0),w(0){}
	Edge_Mst(int start,int end,int weight = 0):u(start),v(end),w(weight){}
};



class Graph_Mst{
private:
	vector<Node_Mst> V;
	vector<Edge_Mst> E;
	vector<vector<Edge_Mst> >Adj;
public:

	Graph_Mst(int v_num,int e_num);
	void addEdge(int u,int v,int w = 0);

	vector<Node_Mst> MST_Prim(int r);
	void MST_Print_Path(vector<Node_Mst> res);
};



#endif /* MST_H_ */
