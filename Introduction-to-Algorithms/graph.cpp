/*
 * graph.cpp
 *
 *  Created on: 2017��6��25��
 *      Author: xiaoquan
 */

#include"graph.h"

//��ʼ��ͼ
Graph::Graph(int v_num,int e_num){
	V.resize(v_num);
	Adj.resize(v_num);
}

//���������u->v(w)û��Ȩ�ص�Ĭ��Ϊ1������
void Graph::addEdge(int u,int v,int w){
	Edge *te = new Edge(u,v,w);
	E.push_back(*te);
	Adj[u-1].push_back(*te);
}

//������ȱ���
void Graph::BFS(int s){
	for(int i = 0;i < V.size();i++){
		V[i].color = WHITE;
		V[i].d = inf;
		V[i].pre = NIL;
		V[i].num = i;
	}
	V[s-1].color = GRAY;
	queue<int> Q;
	Q.push(s);
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		for(int i = 0;i < Adj[u-1].size();i++){
			int v = Adj[u-1][i].v;
			if(V[v-1].color == WHITE){
				V[v-1].color = GRAY;
				V[v-1].d += Adj[u-1][i].w;
				V[v-1].pre = u;
				Q.push(v);

//				cout << u << "->" << v << "\n";//������
			}
		}
		V[u-1].color = BLACK;
	}
}

//��ӡ�ؼ�·��
void Graph::Print_Path(int s,int v){
	if(v == s)
		cout << s;
	else if(V[v-1].pre == 0){
		cout << "No path from " << s << " to " << v << "\n";
	}else{
		Print_Path(s,V[v-1].pre);
		cout << "->" << v;
	}
}

//ȫ���ڵ�������ȱ���
void Graph::DFS(){
	for(int i = 0;i < V.size();i++){
		V[i].color = WHITE;
		V[i].pre = NIL;
		V[i].num = i;
	}

	time = 0;
	for(int u = 1;u <= V.size();u++){
		if(V[u-1].color == WHITE)
			DFS_Visit(u);
	}
}

//�����ڵ�������ȱ���
void Graph::DFS_Visit(int u){
	time++;
	V[u-1].d = time;
	V[u-1].color = GRAY;
	for(int i = 0;i < Adj[u-1].size();i++){
		int v = Adj[u-1][i].v;
		if(V[v-1].color == WHITE){
//			cout << u << "->" << v << "\n";//������

			V[v-1].pre = u;
			DFS_Visit(v);
		}
	}
	V[u-1].color = BLACK;
	time++;
	V[u-1].f = time;
}


//��������
list<Node> Graph::TopologicalSort(){
	DFS();
	list<Node> result;
	//�����нڵ㰴����ʱ��f��������
	for(int i = 0;i < V.size();i++){
		Node temp(V[i]);
		list<Node>::iterator iter = result.begin();
		while(iter != result.end() && iter->f > temp.f){
			iter++;
		}
		result.insert(iter,temp);
	}
	return result;
}


