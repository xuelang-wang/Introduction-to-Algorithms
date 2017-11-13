#include "Sort.h"


Sort::Sort() {
	// TODO Auto-generated constructor stub

}

Sort::~Sort() {
	// TODO Auto-generated destructor stub
}

void Sort::InsertSort(vector<int> &A){
	for(unsigned int i = 1;i < A.size();i++){
		int key = A[i];
		int j = i -1;
		while(j >= 0 && A[j] > key){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = key;
	}
}

//希尔排序
void Sort::ShellSort(vector<int> &A){
	int h,i,j,temp;
	int n = A.size();

	for(h = n/2;h > 0;h /= 2){//控制增量
		for(i = h;i < n; i += h){
			temp = A[i];
			for(j = i - h;j >= 0 && temp < A[j];j -= h)
				A[j+h] = A[j];
			A[j+h] = temp;
		}
	}
}



void Sort::MergeSort(vector<int> & A,int p,int r){
	if(p < r){
		int q = (p + r)/2;
		MergeSort(A,p,q);
		MergeSort(A,q+1,r);
		Merge(A,p,q,r);
	}
}
void Sort::Merge(vector<int> &A,int p,int q,int r){
	vector<int> L(&A[p],&A[q+1]);
	vector<int> R(&A[q+1],&A[r+1]);
	L.push_back(INT_MAX);
	R.push_back(INT_MAX);

	int i = 0;
	int j = 0;
	for(int k = p;k <= r;k++){
		if(L[i] <= R[j]){
			A[k] = L[i];
			i++;
		}else{
			A[k] = R[j];
			j++;
		}
	}
}

void Sort::QucikSort(vector<int> &A,int q,int r){
	if(q < r){
		int x = A[r];//选取主元
		int p = q - 1;//记录主元位置(主元素最后所在位置的前一个)
		for(int i = q;i < r;i++){
			if(A[i] < x){
				p++;
				swap(A[p],A[i]);
			}
		}
		swap(A[++p],A[r]);

		QucikSort(A,q,p-1);
		QucikSort(A,p+1,r);
	}
}

void Sort::RandomQucikSort(vector<int> &A,int q,int r){
	if(q < r){

		swap(A[rand()%(r - q + 1)+q],A[r]);//随机产生
		int x = A[r];//选取主元
		int p = q - 1;//记录主元位置(主元素最后所在位置的前一个)
		for(int i = q;i < r;i++){
			if(A[i] < x){
				p++;
				swap(A[p],A[i]);
			}
		}

		swap(A[++p],A[r]);

		RandomQucikSort(A,q,p-1);
		RandomQucikSort(A,p+1,r);
	}
}


void Sort::CountSort(vector<int> &A,vector<int> &B,int k){
	vector<int> C(k+1,0);//存储数组A中比数A[i]小的个数(只用下标1-k的位置)
	for(unsigned int i = 0;i < A.size();i++)
		C[A[i]]++;
	for(int i = 1;i < k+1;i++)
		C[i] += C[i-1];
	B.resize(A.size(),0);
	for(unsigned int i = 0;i < A.size();i++){
		B[C[A[i]] - 1] = A[i];
		C[A[i]]--;
	}
}


void Sort::BubbleSort(vector<int> & A){
	for(unsigned int i = 0;i < A.size();i++){
		for(unsigned int j = A.size() - 1;j > i;j--){
			if(A[j] < A[j - 1])
				swap(A[j],A[j - 1]);
		}
	}
}

int Sort::Parent(int i){
	//数组中下标从0开始，堆中下标从1开始
	return (i+1)/2 - 1;
}
int Sort::Left(int i){
	return 2*(i+1) - 1;
}
int Sort::Right(int i){
	return 2*(i+1);
}

void Sort::MaxHeapify(vector<int> &A,int i,int size){
	int l = Left(i);
	int r = Right(i);
	int largest;
	if(l < size && A[l] > A[i])
		largest = l;
	else
		largest = i;
	if(r < size && A[r] > A[largest])
		largest = r;
	if(largest != i){
		swap(A[i],A[largest]);
		MaxHeapify(A,largest,size);
	}
	return;
}

void Sort::BuildMaxHeap(vector<int> &A){
	for(int i = (A.size()/2 - 1) ;i>= 0;i--)
		MaxHeapify(A,i,(int)A.size());
	return;
}

void Sort::HeapSort(vector<int> &A){
	int size = A.size();//用于标记当前堆大小
	BuildMaxHeap(A);
	for(int i = A.size() - 1;i > 0;i--){
		swap(A[i],A[0]);
		size--;
		MaxHeapify(A,0,size);
	}
	return;
}



