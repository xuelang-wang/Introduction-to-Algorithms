/*
 * string_match.h
 *
 *  Created on: 2017��6��29��
 *      Author: xiaoquan
 */

#ifndef STRING_MATCH_H_
#define STRING_MATCH_H_

#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;

/*�����ַ���ƥ���㷨*/
vector<int> Naive_String_Matcher(string T,string P){
	int n = T.length();
	int m = P.length();
	vector<int> res;//��¼ƥ��ʱ��ƫ����
	for(int s = 0;s <= n - m;s++){
		if(T.substr(s,m) == P){
			cout << "Pattern occurs with shift " << s << "\n";
			res.push_back(s);
		}
	}
	if(res.empty())
		cout << "No match!!\n";
	return res;
}

/*Rabin-Karp�㷨*/
vector<int> Rabin_Karp_Matcher(string T,string P,int d,int q){
	vector<int> res;
	int n = T.length();
	int m = P.length();
	int h = int(pow(d,m-1))%q;
	int p = 0;
	int ts = 0;
	for(int i = 0;i < m;i++){
		p = (d*p+P[i]-'0')%q;
		ts = (d*ts + T[i] - '0')%q;
	}
	for(int s = 0;s <= n-m;s++){
		if(p == ts)
			if(P == T.substr(s,m)){
				res.push_back(s);
				cout << "Pattern occurs with " << s << "\n";
			}
		if(s < n - m)
			ts = (d*(ts-(T[s+1]-'0')*h)) + (int)(T[s+m+1]-'0')%q;
	}
	if(res.empty())
		cout << "No match!!!\n";
	return res;
}



/*KMP�㷨��Knuth-Morris-Pratt��*/
vector<int> Compute_Prefix_Function(string P){
	int m = P.length();
	vector<int> res(m+1,0);
	int k = 0;//��ǰƥ���ַ��ĸ���������������
	for(int q = 2;q <= m;q++){
		while(k > 0 && P[k] != P[q-1])//P[k]��ʾ���ǵ�k+1���ַ�����ͷ��ʼ�����ģ�
			k = res[k];//��k���ַ������ƥ�����
		if(P[k] == P[q-1])
			k++;
		res[q] = k;
	}
	return res;
}


vector<int> KMP_Matcher(string T,string P){
	int n = T.length();
	int m = P.length();
	vector<int> res;
	vector<int> next = Compute_Prefix_Function(P);
	int q = 0;			       	//number of characters matched
	for(int i = 0;i < n;i++){		//scan the text from left to right
		while(q > 0 && P[q] != T[i])
			q = next[q];		//next charchter does not match
		if(P[q] == T[i])
			q++;				//next character match
		if(q == m){				//is all of P matched?
			res.push_back(i - m + 1);
			cout << "Pattern occurs with shift " << i - m + 1 << "\n";
		}
//		q = next[q];			//look for the next match
	}
	if(res.empty())
		cout << "No match!!\n";
	return res;
}



#endif /* STRING_MATCH_H_ */
