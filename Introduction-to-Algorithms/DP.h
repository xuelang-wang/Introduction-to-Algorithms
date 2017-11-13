/*
 * DP.hpp
 *
 *  Created on: 2017��6��11��
 *      Author: xiaoquan
 */

#ifndef DP_H_
#define DP_H_
#include<vector>
#include<string>
#include<climits>
#include<cfloat>
using namespace std;

//�����и�
//�Զ����µݹ�ʵ��
int Cut_Rod(vector<int> &p,int n){
	if(n == 0)
		return 0;
	int q = INT_MIN;
	for(int i = 0;i<n;i++)
		q = max(q,p[i] + Cut_Rod(p,n-i-1));
	return q;
}

//���������Զ����·�
int Memoized_Cut_Rod(vector<int> &p,int n,vector<int> &r){
	if(r[n] >= 0)
		return r[n];
	int q;
	if(n == 0)
		q = 0;
	else{
		q = INT_MIN;
		for(int i = 1; i <= n;i++){
			q = max(q,p[i-1]+Memoized_Cut_Rod(p,n-i,r));
		}
	}
	r[n] = q;
	return q;
}

int Memoized_Cut_Rod(vector<int> & p,int n){
	vector<int> r(n+1,INT_MIN);
	return Memoized_Cut_Rod(p,n,r);
}

//�Ե����ϰ汾
int Bottom_Up_Cut_Rod(vector<int> &p,int n){
	vector<int> r(n+1,INT_MIN);
	r[0] = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= i;j++)
			r[i] = max(r[i],p[j-1]+r[i-j]);
	}
	return r[n];
}


//�Ե����ϰ汾����չ��

vector<int> Extended_Bottom_Up_Cut_Rod(vector<int> &p,int n,vector<int> &s){
	vector<int> r(n+1,INT_MIN);
	r[0] = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= i;j++){
			if(r[i] < p[j-1] + r[i-j]){
				r[i] = p[j-1] + r[i-j];
				s[i] = j;
			}
		}
	}
	return r;
}

/*��ӡ�и���*/

void Print_Cut_Rod_Solution(vector<int> &p,int n){
	vector<int> s(n+1,0);
	vector<int> r = Extended_Bottom_Up_Cut_Rod(p,n,s);
	while(n > 0){
		cout << s[n] << ", ";
		n = n - s[n];
	}
}

//-------------------------------------------------------------------
//�������˷�

vector<vector<int> > Matrix_Chain_Order(vector<int> &p,vector<vector<int> > &s){
	//p�ǿ�
	int n = p.size() - 1;
	vector<vector<int> > m(n+1,vector<int>(n+1,0));
	for(int l = 2;l <= n;l++){
		for(int i = 1;i <= n - l + 1;i++){
			int j = i + l - 1;
			m[i][j] = INT_MAX;
			for(int k = i;k < j;k++){
				int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(m[i][j] > q){
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	return m;
}

void Print_Optimal_Parens(vector<vector<int> > &s,int i,int j){
	if(i == j)
		cout << "A" << i;
	else{
		cout << "(";
		Print_Optimal_Parens(s,i,s[i][j]);
		Print_Optimal_Parens(s,s[i][j] +1,j);
		cout << ")";
	}
}

/*��������У�LCS��*/

vector<vector<int> > LCS_Length(string X,string Y,vector<vector<int> > &b){
	/*"���ϼ�ͷ--1�����ϼ�ͷ--2�������ͷ--3"*/
	int n = X.length();
	int m = Y.length();
	vector<vector<int> > c(n+1,vector<int>(m+1,0));
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(X[i-1] == Y[j-1]){
				c[i][j] = c[i-1][j-1]+1;
				b[i][j] = 1;
			}else{
				if(c[i-1][j] >= c[i][j-1]){

					c[i][j] = c[i-1][j];
					b[i][j] = 2;
				}else{
					c[i][j] = c[i][j-1];
					b[i][j] = 3;
				}
			}
		}
	}
	return c;
}


void Print_LCS(vector<vector<int> > &b,string X,int i,int j){
	if(0 == i ||0 == j)
		return;
	if(1 == b[i][j]){
		Print_LCS(b,X,i-1,j-1);
		cout << X[i-1];
	}else if(2 == b[i][j])
		Print_LCS(b,X,i-1,j);
	else
		Print_LCS(b,X,i,j-1);
}


/*���Ŷ���������*/
vector<vector<double> > Optimal_BST(vector<double> &p,vector<double> &q,int n,vector<vector<int> > &root){
	//p ��1-n��Χ����Ч   �ؼ��ָ���
	//q ��0-n��Χ����Ч   α�ؼ��ָ���

	vector<vector<double> > e(n+2,vector<double>(n+1,0.0));
	vector<vector<double> > w(n+2,vector<double>(n+1,0.0));
	for(int i = 1;i <= n+1;i++){
		e[i][i-1] = q[i-1];//ֻ��α�ؼ���
		w[i][i-1] = q[i-1];
	}
	for(int l = 1;l <= n;l++){
		for(int i = 1;i <= n - l + 1;i++){
			int j = i + l - 1;
			e[i][j] = DBL_MAX;
			w[i][j] = w[i][j-1] + p[j] + q[j];
			for(int r = i;r <= j;r++){
				double t = e[i][r-1] + e[r+1][j] + w[i][j];
				if(e[i][j] > t){
					e[i][j] = t;
					root[i][j] = r;
				}
			}
		}
	}
	return e;
}

void Construct_Optimal_BST(vector<vector<int> > & root,int i,int j,int parents){
	int n = root.size() - 1;//�ؼ�����Ŀ���ڵ�����
	if(j < i - 1)
		return;
	else if(j == i-1){
		if(j < parents)
			cout << "d" << j << "��k" << parents << "������" << '\n';
		else
			cout << "d" << j << "��k" << parents << "���Һ���" << '\n';
		return;
	}else{
		int temp = root[i][j];
		if(temp == root[1][n]){
			cout << "k" << temp << "Ϊ��\n";
		}else{
			if(temp < parents)
				cout << "k" << temp << "��k" << parents << "������" << '\n';
			else
				cout << "k" << temp << "��k" << parents << "���Һ���" << '\n';
		}
		Construct_Optimal_BST(root,i,temp - 1,temp);
		Construct_Optimal_BST(root,temp+1,j,temp);
	}
}

#endif /* DP_H_ */
