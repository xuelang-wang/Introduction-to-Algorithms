/*
 * MST.cpp
 *
 *  Created on: 2017年7月1日
 *      Author: xiaoquan
 */

#include"MST.h"
#include<algorithm>
#include<iostream>
using namespace std;

Graph_Mst::Graph_Mst(int v_num,int e_num){
	V.resize(v_num);
	for(int i = 1;i <= v_num;i++)
		V[i-1].num = i;
	Adj.resize(v_num);
}

void Graph_Mst::addEdge(int u,int v,int w){
	Edge_Mst *te = new Edge_Mst(u,v,w);
	E.push_back(*te);
	Adj[u-1].push_back(*te);

	//无向图(有向图需舍去)
	Edge_Mst *te1 = new Edge_Mst(v,u,w);
	E.push_back(*te1);
	Adj[v-1].push_back(*te1);
}

vector<Node_Mst> Graph_Mst::MST_Prim(int r){
	vector<Node_Mst> A;
	for(int i = 0;i < V.size();i++){
		V[i].vis = false;
		V[i].key = INT_MAX;
		V[i].pre = 0;
	}
	V[r-1].key = 0;
	priority_queue<Node_Mst,vector<Node_Mst>,less<Node_Mst> > Q(V.begin(),V.end());
	while(!Q.empty()){
		int u = Q.top().num;
		Q.pop();
		V[u-1].vis = true;
		A.push_back(V[u-1]);
		for(int i = 0;i < Adj[u-1].size();i++){//感觉使用最小堆会好点
			int v = Adj[u-1][i].v;
			if(!V[v-1].vis && Adj[u-1][i].w < V[v-1].key){
				V[v-1].pre = u;
				V[v-1].key = Adj[u-1][i].w;
			}
			while(!Q.empty())//使用优先队列不能随机访问，改变不了队列里面的key值，只能暴力重新构造队列了
				Q.pop();
			for(int j = 0;j < V.size();j++){
				if(!V[j].vis)
					Q.push(V[j]);
			}
		}
	}
	return A;
}


void Graph_Mst::MST_Print_Path(vector<Node_Mst> res){
	if(!res.empty()){
		cout << "start Node: " << res[0].num << "\n";
		for(int i = 1;i < res.size();i++){
			cout << "next Node: " << res[i].num << "It's previous Node: " << res[i].pre << "\n";
		}
	}
	return;
}
