/*
 * greedy.h
 *
 *  Created on: 2017��6��17��
 *      Author: xiaoquan
 */

#ifndef GREEDY_H_
#define GREEDY_H_

#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
/*16�� ̰���㷨*/

//�ѡ������

//�ݹ���ʽ
vector<int> Recursive_Activity_Selector(vector<int> s,vector<int> f,int k,int n){
	int m = k+1;
	while(m <= n && s[m] < f[k])
		m++;
	vector<int> AK;
	if(m <= n){
		AK = Recursive_Activity_Selector(s,f,m,n);
		AK.push_back(m);
		sort(AK.begin(),AK.end());
	}
	return AK;
}

//������ʽ
vector<int> Greedy_Activity_Selector(vector<int> s,vector<int> f){
	vector<int> A;
	A.push_back(1);
	int k = 1;
	int n = s.size() - 1;
	for(int i = 2;i <= n;i++){
		if(s[i] >= f[k]){
			A.push_back(i);
			k = i;
		}
	}
	return A;
}

//0-1�滮��DP��

int Knapsack(vector<int> v,vector<int> weight,int W,vector<vector<int> > &dp){
	int n = v.size();
//	vector<vector<int> > dp(n+1,vector<int>(W+1,0));
	//dp[i][w]  ��i����Ʒ ��������Ϊwʱ������ֵ
	for(int i = 1;i <= n;i++){
		for(int w = 1;w <= W;w++){
			if(weight[i-1] > w)
				dp[i][w] = dp[i-1][w];
			else{
				dp[i][w] = max(dp[i-1][w - weight[i-1]]+v[i-1],dp[i-1][w]);
			}
		}
	}
	return dp[n][W];
}
vector<int> findPath(vector<int> v,vector<int> weight,int W,vector<vector<int> > &dp)
{
    int n = v.size();
	int w = W;
	vector<int> x(n);
    for (int i = n; i >= 2; i--)
    {
        if (dp[i][w] == dp[i-1][w])
        {
            x[i-1] = 0;
        }
        else
        {
            x[i-1] = 1;
            w = w - weight[i-1];
        }
    }
    if (dp[1][w] == 0)
        x[0] = 0;
    else
        x[0] = 1;
    return x;
}

//�շ�������

typedef struct node{
	char c;//�ַ�
	int freq;//����Ƶ��
	node * left;
	node * right;
	node():c(0),freq(0),left(NULL),right(NULL){}
	node(char ch,int f):c(ch),freq(f),left(NULL),right(NULL){}

}Node;

class mycomparison{
	bool reverse;
public:
	mycomparison(const bool & revparm = false){
		reverse = revparm;
	}
	bool operator()(const Node * lhs,const Node * rhs) const{
		if(reverse)
			return lhs->freq > rhs->freq;
		else
			return lhs->freq < rhs->freq;
	}
};//�Զ������ȶ��жԱ���


Node * HUFFMAN(vector<Node *> &C){
	int n = C.size();
	priority_queue<Node *,vector<Node *>,mycomparison> Q(C.begin(),C.end(),mycomparison(true));//��С��

	for(int i = 0;i < n-1;i++){
		Node *z = new Node;
		z->left = Q.top();
		Q.pop();
		z->right = Q.top();
		Q.pop();
		z->freq = z->left->freq + z->right->freq;
		Q.push(z);
	}
	return Q.top();
}


#endif /* GREEDY_H_ */
