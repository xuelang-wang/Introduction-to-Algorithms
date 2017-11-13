/*
 * num_theory.h
 *
 *  Created on: 2017��7��1��
 *      Author: xiaoquan
 */

#ifndef NUM_THEORY_H_
#define NUM_THEORY_H_
#include<iostream>
#include<vector>
using namespace std;

struct triple{
	int d;
	int x;
	int y;
	triple(int dt,int xt,int yt):d(dt),x(xt),y(yt){}
};

//ŷ������㷨�����Լ����
int Euclid(int a,int b){
	if(b == 0)
		return a;
	else
		return Euclid(b,a%b);
}

//��չŷ������㷨
triple Extended_Euclid(int a,int b){
	if(b == 0)
		return triple(a,1,0);
	else{
		triple tp = Extended_Euclid(b,a%b);
		return triple(tp.d,tp.y,tp.x-a/b*tp.y);
	}
}


//���ģ���Է���   ax==b(mod n)

vector<int> Modular_Linear_Equation_Solver(int a,int b,int n){
	vector<int> res;
	triple tp = Extended_Euclid(a,n);
	if(b%tp.d == 0){
		int x0 = tp.x*(b/tp.d)%n;
		if(x0 < 0)
			x0 += n;
		for(int i = 0;i < tp.d;i++){
			res.push_back((x0+i*(n/tp.d))%n);
			cout << (x0+i*(n/tp.d))%n << endl;
		}
	}else
		cout << "No solution!!!\n";
	return res;
}



#endif /* NUM_THEORY_H_ */
