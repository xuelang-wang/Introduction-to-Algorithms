/*
 * SSP.cpp
 *
 *  Created on: 2017Äê7ÔÂ4ÈÕ
 *      Author: xiaoquan
 */

#include "SSP.h"

Graph_Ssp::Graph_Ssp(int v_num,int e_num){
	V.resize(v_num);
	for(int i = 1;i <= v_num;i++)
		V[i-1].num = i;
	Adj.resize(v_num);
}
void Graph_Ssp::addEdge(int u,int v,int w){
	Edge_Ssp *te = new Edge_Ssp(u,v,w);
	E.push_back(*te);
	Adj[u-1].push_back(*te);
}

void Graph_Ssp::Initialize_Single_Source(int s){
	for(int i = 0;i < V.size();i++){
		V[i].d = INT_MAX;
		V[i].pre = 0;//NIL = 0
	}
	V[s-1].d = 0;
}
void Graph_Ssp::Relax(int u,int v,int w){
	if(V[v - 1].d > V[u-1].d + w){
		V[v-1].d = V[u-1].d+w;
		V[v-1].pre = u;
	}
}
bool Graph_Ssp::Bellman_Ford(int s){
	Initialize_Single_Source(s);
	for(int i = 1;i < V.size();i++){
		for(int j = 0;j < E.size();j++){
			Relax(E[j].u,E[j].v,E[j].w);
		}
	}
	for(int j = 0;j < E.size();j++)
		if(V[E[j].u-1].d > V[E[j].v-1].d + E[j].w)
			return false;
	return true;
}

vector<Node_Ssp> Graph_Ssp::Dijkstra(int s){
	priority_queue<Node_Ssp*> Q;
	vector<Node_Ssp> S;
	Initialize_Single_Source(s);
	for(int i = 0;i < V.size();i++)
		Q.push(&V[i]);
	while(!Q.empty()){
		Node_Ssp *u = Q.top();
		Q.pop();
		S.push_back(*u);
		for(int i = 0;i < Adj[u->num-1].size();i++){
			Relax(u->num,Adj[u->num-1][i].v,Adj[u->num-1][i].w);
		}
	}
	return S;

}

void Graph_Ssp::SSP_Print_Path(int s,int r){
	if(s == r)
		cout << r;
	else if(V[r-1].pre == 0){
		cout << "No shortest path!!!\n";
	}else{
		SSP_Print_Path(s,V[r-1].pre);
		cout << "->" << r;
	}
}

