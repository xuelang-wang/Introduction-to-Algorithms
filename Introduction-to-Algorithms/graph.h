/*
 * graph.h
 *	第22章 基本的图算法
 *	广度优先搜索
 *	深度优先搜索
 *  Created on: 2017年6月25日
 *      Author: xiaoquan
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include<vector>
#include<queue>
#include<list>
#include<iostream>
#include<cmath>

using namespace std;

enum Color{
	WHITE,
	GRAY,
	BLACK
};

const int inf = 0x3fffffff;
const int NIL = 0;
struct Node{
	Color color;
	int d;//(广度优先记录从源节点s到该节点的距离)(深度优先时记录访问时间,用于拓扑排序)
	int pre;//记录前一节点（前继）
	int f;//针对深度优先记录结束时间,用于拓扑排序
	int num;//记录节点编号
	Node():color(WHITE),d(0),pre(0),f(0),num(0){}
	Node(const Node & t):color(t.color),d(t.d),pre(t.pre),f(t.f),num(t.num){}
};//定义节点

struct Edge{
	int u;//起点
	int v;//终点
	int w;//权重
	Edge():u(0),v(0),w(0){}
	Edge(int start,int end,int weight = 0):u(start),v(end),w(weight){}
};



class Graph{
private:
	vector<Node> V;//顶点
	vector<Edge> E;//边
	vector<vector<Edge> >Adj;//邻接表
public:
	//针对深度优先，用来记录时间戳
	int time;

	//初始化图
	Graph(int v_num,int e_num);

	//增加有向边u->v(w)没有权重的默认为1即边数
	void addEdge(int u,int v,int w = 1);

	//广度优先遍历
	void BFS(int s);

	//全部节点深度优先遍历
	void DFS();
	//单个节点深度优先遍历
	void DFS_Visit(int u);

	//拓扑排序
	list<Node> TopologicalSort();

	//打印关键路径
	void Print_Path(int s,int v);
};

#endif /* GRAPH_H_ */
