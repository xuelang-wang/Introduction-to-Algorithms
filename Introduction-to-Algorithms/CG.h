/*
 * CG.h
 *
 *  Created on: 2017��8��22��
 *      Author: xiaoquan
 */
//��33�� ���㼸��ѧ��Computational Geometry��
#ifndef CG_H_
#define CG_H_

#include<cmath>
using namespace std;

template<class T>
using point = pair<T,T>;//�����ṹ

//�������
template<class T>
T Direction(point<T> pi,point<T> pj, point<T> pk){
	T x1 = pk.first - pi.first;
	T y1 = pk.second - pi.second;
	T x2= pj.first - pi.first;
	T y2 = pj.second - pi.second;
	return x1*y2-x2*y1;
}

//�жϵ�pk�Ƿ����߶�pi->pj��
template<class T>
bool OnSegment(point<T> pi,point<T> pj,point<T> pk){
	if(min(pi.first,pj.first) <= pk.first && pk.first <= max(pi.first,pj.first)&&
			min(pi.second,pj.second) <= pk.second && pk.second <= max(pi.second,pj.second))
		return true;
	return false;
}

template<class T>
bool Segments_Intersect(point<T> p1,point<T> p2,point<T> p3,point<T> p4){
	T d1 = Direction(p3,p4,p1);
	T d2 = Direction(p3,p4,p2);
	T d3 = Direction(p1,p2,p3);
	T d4 = Direction(p1,p2,p4);
	if(d1*d2 < 0 && d3*d4 < 0)
		return true;
	else if(abs(d1) <= 1e-6 && OnSegment(p3,p4,p1))
		return true;
	else if(abs(d2) <= 1e-6 && OnSegment(p3,p4,p2))
		return true;
	else if(abs(d3) <= 1e-6 && OnSegment(p1,p2,p3))
		return true;
	else if(abs(d4) <= 1e-6 && OnSegment(p1,p2,p4))
		return true;
	else
		return false;
}

#endif /* CG_H_ */
