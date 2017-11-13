/*
 * ASP.cpp
 *
 *  Created on: 2017Äê7ÔÂ4ÈÕ
 *      Author: xiaoquan
 */

#include "ASP.h"

Graph_ASP::Graph_ASP(int n){
	W.resize(n);
	for(int i = 0;i < n;i++){
		W[i].resize(n);
		for(int j = 0;j < n;j++){
			if(i == j)
				W[i][j] = 0;
			else
				W[i][j] = inf;
		}
	}
}
void Graph_ASP::addEdge(int u,int v,int w){
	W[u-1][v-1] = w;
}

matrix Graph_ASP::Extend_Shortest_Paths(matrix A,matrix B){
	int n = A.size();
	matrix Ltp(n,vector<int>(n));
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			Ltp[i][j] = inf;
			for(int k = 0;k < n;k++){
				Ltp[i][j] = min(Ltp[i][j],A[i][k]+B[k][j]);
			}
		}
	}
	return Ltp;
}

matrix Graph_ASP::Slow_All_Pairs_Shortest_Paths(){
	int n = W.size();
	matrix L = W;
	for(int m = 2;m <= n-1;m++){
		L = Extend_Shortest_Paths(L,W);
	}
	return L;
}

matrix Graph_ASP::Faster_All_Pairs_Shorest_Paths(){
	int n = W.size();
	matrix L = W;
	int m = 1;
	while(m < n-1){
		L = Extend_Shortest_Paths(L,L);
		m *= 2;
	}
	return L;
}


void Graph_ASP::Print_Matrix(matrix a){
	int n = a.size();
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if(j != n-1)
				cout << a[i][j] << " ";
			else
				cout << a[i][j] << "\n";
		}
	}
}

matrix Graph_ASP::Floyd_Warshall(){
	int n = W.size();
	matrix D = W;
	for(int k = 0;k < n;k++){
		matrix Dtp(n,vector<int>(n));
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				Dtp[i][j] = min(D[i][j],D[i][k]+D[k][j]);
			}
		}
		D = Dtp;
	}
	return D;
}
