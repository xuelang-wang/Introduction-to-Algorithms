#ifndef SORT_H_
#define SORT_H_

#include<vector>
#include<cstdlib>
#include<climits>
using namespace std;
class Sort {
public:
	Sort();
	//≤Â»Î≈≈–Ú
	void InsertSort(vector<int> &A);
	//œ£∂˚≈≈–Ú
	void ShellSort(vector<int> &A);

	//πÈ≤¢≈≈–Ú
	void MergeSort(vector<int> & A,int p,int r);
	void Merge(vector<int> &A,int p,int q,int r);

	//øÏ≈≈
	void QucikSort(vector<int> &A,int q,int r);
	//ÀÊª˙øÏ≈≈
	void RandomQucikSort(vector<int> &A,int q,int r);
	//º∆ ˝≈≈–Ú
	void CountSort(vector<int> &A,vector<int> &B,int k);
	//√∞≈›≈≈–Ú
	void BubbleSort(vector<int> & A);

	//∂—≈≈–Ú£®◊Ó¥Û∂—£©
	int Parent(int i);
	int Left(int i);
	int Right(int i);
	void MaxHeapify(vector<int> &A,int i,int size);//Œ¨ª§∂—
	void BuildMaxHeap(vector<int> &A);//Ω®∂—
	void HeapSort(vector<int> &A);//∂—≈≈–Ú

	virtual ~Sort();
};

#endif /* SORT_H_ */
