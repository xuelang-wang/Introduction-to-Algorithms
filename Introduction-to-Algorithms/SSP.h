/*
 * SSP.h
 *
 *  Created on: 2017��7��4��
 *      Author: xiaoquan
 */

#ifndef SSP_H_
#define SSP_H_
//24�� ��Դ���·��
#include<iostream>
#include<queue>
#include<climits>
using namespace std;

struct Node_Ssp{
	friend bool operator < (Node_Ssp n1,Node_Ssp n2){
		return n1.d < n2.d;
	}
	int d;//s��v�����·������
	int pre;
	int num;//��¼�ڵ���������
	Node_Ssp():d(0),pre(0),num(0){}
	Node_Ssp(int k,int p,int n):d(k),pre(p),num(n){}
};//����ڵ�

struct Edge_Ssp{
	int u;
	int v;
	int w;
	Edge_Ssp():u(0),v(0),w(0){}
	Edge_Ssp(int start,int end,int weight = 0):u(start),v(end),w(weight){}
};//�����



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

	//Bellman Ford �㷨
	/*ʹ���ڲ��� �Ǹ���������ͼ������ͼ��*/
	bool Bellman_Ford(int s);

	/*Dijkstra�㷨
	 * ���ò����и�Ȩ������ͼ*/
	vector<Node_Ssp>  Dijkstra(int s);

	void SSP_Print_Path(int s,int r);
	//rΪ�յ�
};

#endif /* SSP_H_ */
