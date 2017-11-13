/*
 * OSTreeNode.h
 *
 *  Created on: 2017��6��5��
 *      Author: xiaoquan
 */

#ifndef OST_H_
#define OST_H_

#include <iostream>
#include<stack>
using namespace std;

static const int RED = 0;
static const int BLACK = 1;

/*����˳��ͳ��������������ڵ�*/
template <class T>
struct OSTreeNode{
public:
    T key;
    int color;
    int size;
    OSTreeNode<T>* parents;
    OSTreeNode<T>* left;
    OSTreeNode<T>* right;
	OSTreeNode():key(T()),color(BLACK),size(0),parents(NULL),left(NULL),right(NULL){}
};
/*����������*/
template <class T>
class OST
{
private:
    OSTreeNode<T>* root;
    static  OSTreeNode<T> *NIL;
public:
    OST();
    void LeftRotate(OSTreeNode<T> *x);
    void RightRotate(OSTreeNode<T> *x);

    void RBInsert(OSTreeNode<T> * z);
    void RBInsertFixup(OSTreeNode<T> * z);
    void RBInsertKey(const T& k);

    int RBDelete(OSTreeNode<T> * z);
    void RBDeleteFixup(OSTreeNode<T> * z);
    int RBDeleteKey(const T& k);

	void InorderTreeWalk() const;//�������

	/*����ָ��������ָ��͹ؼ���k,����TreeSearch����ָ������ؼ���k�Ľڵ㣨������ڵĻ���
	 * ָ��;���򷵻ؿ�ָ��NULL*/
	OSTreeNode<T> * TreeSearch(const T& k);

	//���غ�ڶ������о�����С�ؼ��ֵ�Ԫ�ؽڵ�ָ��
	OSTreeNode<T> * TreeMinimun(OSTreeNode<T> * pnode);

	//���غ�ڶ������о������ؼ��ֵ�Ԫ�ؽڵ�ָ��
	OSTreeNode<T> * TreeMaximun(OSTreeNode<T> * pnode);

	//���غ�ڶ������е�ǰ�ڵ��̽ڵ�ָ��
	OSTreeNode<T> * TreeSuccessor(OSTreeNode<T> * pnode);

	//���غ�ڶ������е�ǰ�ڵ�ǰ�̽ڵ�ָ��
	OSTreeNode<T> * TreePredecessor(OSTreeNode<T> * pnode);

    OSTreeNode<T>* GetRoot() const;
    void MakeEmpty(OSTreeNode<T>* root);

    OSTreeNode<T>* OS_Select(OSTreeNode<T> * x,int i);
    /*�����Խڵ�xΪ���ĵ�iС�ؼ��ֵĽڵ�*/

    int OS_Rank(OSTreeNode<T> *x);
    /*���ؽڵ�x��˳��ͳ�����е��ȣ����������Ӧ���������е�λ�ã�*/

    ~OST();
};

//����
template<class T>
OSTreeNode<T> *OST<T>::NIL = new OSTreeNode<T>;


template<class T>
OST<T>::OST(){
	root = NULL;
}

template<class T>
void OST<T>::LeftRotate(OSTreeNode<T> *x){
	OSTreeNode<T> * y = x->right;		//set y
	x->right = y->left;
	if(y->left != NIL)
		y->left->parents = x;
	y->parents = x->parents;			//link x's parents to y
	if(x->parents == NIL)
		root = y;
	else if(x == x->parents->left)
		x->parents->left = y;
	else
		x->parents->right = y;
	y->left = x;					//put x on y's left
	x->parents = y;

	y->size = x->size;				//updata size
	x->size = x->left->size + x->right->size + 1;
}


template<class T>
void OST<T>::RightRotate(OSTreeNode<T> *x){
	OSTreeNode<T> * y = x->left;		//set y
	x->left = y->right;
	if(y->right != NIL)
		y->right->parents = x;
	y->parents = x->parents;			//link x's parents to y
	if(x->parents == NIL)
		root = y;
	else if(x == x->parents->left)
		x->parents->left = y;
	else
		x->parents->right = y;
	y->right = x;					//put x on y's right
	x->parents = y;

	y->size = x->size;				//updata size
	x->size = x->left->size + x->right->size + 1;
}
template<class T>
void OST<T>::RBInsert(OSTreeNode<T> * z){
	if(NULL == root)
		root = z;
	else{
		OSTreeNode<T> * y = NIL;
		OSTreeNode<T> * x = root;
		while(x != NIL){
			y = x;

			y->size += 1;
			if(z->key < x->key)
				x = x->left;
			else
				x = x->right;
		}
		z->parents = y;
		if(z->key < y->key)
			y->left = z;
		else
			y->right = z;
	}
	RBInsertFixup(z);
}

template<class T>
void OST<T>::RBInsertFixup(OSTreeNode<T> * z){
	while(z->parents->color == RED){
		if(z->parents == z->parents->parents->left){
			OSTreeNode<T> * y = z->parents->parents->right;
			if(y->color == RED){
				z->parents->color = BLACK;
				y->color = BLACK;
				z->parents->parents->color = RED;
				z = z->parents->parents;
			}else{
				if(z == z->parents->right){
					z = z->parents;
					LeftRotate(z);
				}
				z->parents->color = BLACK;
				z->parents->parents->color = RED;
				RightRotate(z->parents->parents);
			}
		}else{
			OSTreeNode<T> * y = z->parents->parents->left;
			if(y->color == RED){
				z->parents->color = BLACK;
				y->color = BLACK;
				z->parents->parents->color = RED;
				z = z->parents->parents;
			}else{
				if(z == z->parents->left){
					z = z->parents;
					RightRotate(z);
				}
				z->parents->color = BLACK;
				z->parents->parents->color = RED;
				LeftRotate(z->parents->parents);
			}
		}
	}
	root->color = BLACK;
}

template<class T>
void OST<T>::RBInsertKey(const T& k){
	OSTreeNode<T> *NewNode = new OSTreeNode<T>;
	NewNode->key = k;
	NewNode->color = RED;
	NewNode->size = 1;
	NewNode->left = NIL;
	NewNode->right = NIL;
	NewNode->parents = NIL;
	RBInsert(NewNode);
}
template<class T>
int OST<T>::RBDelete(OSTreeNode<T> * z){
    OSTreeNode<T>* pnode = TreeSearch(z->key);
    if(NIL != pnode)
    {
        OSTreeNode<T>* qnode,*tnode;
        if(pnode->left == NIL || pnode->right == NIL)
            qnode = pnode;
        else
            qnode = TreeSuccessor(pnode);
        if(qnode->left != NIL)
            tnode = qnode->left;
        else
            tnode = qnode->right;
        tnode->parents = qnode->parents;
        if(qnode->parents == NIL)
            root = tnode;
        else if(qnode == qnode->parents->left)
            qnode->parents->left = tnode;
        else
            qnode->parents->right = tnode;
        if(qnode != pnode)
            pnode->key = qnode->key;
        if(qnode->color == BLACK)
            RBDeleteFixup(tnode);
        delete qnode;
        return 0;
    }
    return -1;
}

template<class T>
void OST<T>::RBDeleteFixup(OSTreeNode<T> * z){
	while(z != root && z->color == BLACK){
	        OSTreeNode<T> *w;
	        if(z == z->parents->left){
	            w = z->parents->right;
	            if(w->color == RED){
	                w->color = BLACK;
	                z->parents->color = RED;
	                LeftRotate(z->parents);
	                w = z->parents->right;
	            }
	            if(w->left->color == BLACK && w->right->color == BLACK){
	                w->color = RED;
	                z = z->parents;
	            }
	            else{
	                if(w->right->color == BLACK){
	                	w->left->color = BLACK;
	                	w->color = RED;
	                	RightRotate(w);
	                	w = z->parents->right;
	                }
	                w->color = z->parents->color;
	                z->parents->color = BLACK;
	                w->right->color = BLACK;
	                LeftRotate(z->parents);
	                z = root;
	            }
	        }else{
	            w = z->parents->left;
	            if(w->color == RED){
	                w->color = BLACK;
	                z->parents->color = RED;
	                RightRotate(z->parents);
	                w = z->parents->left;
	            }
	            if(w->right->color == BLACK && w->left->color == BLACK){
	                w->color = RED;
	                z = z->parents;
	            }
	            else{
	                if(w->left->color == BLACK){
	                	w->right->color = BLACK;
	                	w->color = RED;
	                	LeftRotate(w);
	                	w = z->parents->left;
	                }
	                w->color = z->parents->color;
	                z->parents->color = BLACK;
	                w->left->color = BLACK;
	                RightRotate(z->parents);
	                z = root;
	            }
	        }
	    }
	    z->color = BLACK;
}

template<class T>
int OST<T>::RBDeleteKey(const T& k){
	OSTreeNode<T> * newNode = new OSTreeNode<T>;
	newNode->key = k;
	return RBDelete(newNode);
}



template<class T>
void OST<T>::InorderTreeWalk() const{
	   if(NULL != root)
	    {
	        stack<OSTreeNode<T>* > s;
	        OSTreeNode<T> *ptmpnode;
	        ptmpnode = root;
	        while(NIL != ptmpnode || !s.empty())
	        {
	            if(NIL != ptmpnode)
	            {
	                s.push(ptmpnode);
	                ptmpnode = ptmpnode->left;
	            }
	            else
	            {
	                ptmpnode = s.top();
	                s.pop();
	                cout<<ptmpnode->key<<":";
	                if(ptmpnode->color == BLACK)
	                    cout<<"Black"<<endl;
	                else
	                    cout<<"Red"<<endl;
	                ptmpnode = ptmpnode->right;
	            }
	        }
	    }
}


template<class T>
OSTreeNode<T> * OST<T>::TreeSearch(const T& k){
    OSTreeNode<T>* pnode = root;
    while(pnode != NIL)
    {
        if(pnode->key == k)
            break;
        else if(pnode->key > k)
            pnode = pnode->left;
        else
            pnode = pnode->right;
    }
    return pnode;
}


//���ز��Ҷ������о�����С�ؼ��ֵ�Ԫ�ؽڵ�ָ��
template<class T>
OSTreeNode<T> * OST<T>::TreeMinimun(OSTreeNode<T> * pnode){
	if(pnode != NIL)
		while(pnode->left != NIL)
			pnode = pnode->left;
	return pnode;
}
//���ز��Ҷ������о������ؼ��ֵ�Ԫ�ؽڵ�ָ��
template<class T>
OSTreeNode<T> * OST<T>::TreeMaximun(OSTreeNode<T> * pnode){
	if(pnode != NIL)
		while(pnode->right != NIL)
			pnode = pnode->right;
	return pnode;
}

template<class T>
OSTreeNode<T> * OST<T>::TreeSuccessor(OSTreeNode<T> * pnode){
	if(pnode->right != NIL)
		return TreeMinimun(pnode->right);
	OSTreeNode<T> * p = pnode->parents;
	while(p != NIL && pnode == p->right){
		pnode = p;
		p = p->parents;
	}
	return p;
}

template<class T>
OSTreeNode<T> * OST<T>::TreePredecessor(OSTreeNode<T> * pnode){
	if(pnode->left != NIL)
		return TreeMaximun(pnode->left);
	OSTreeNode<T> * p = pnode->parents;
	while(p != NIL && pnode == p->left){
		pnode = p;
		p = p->parents;
	}
	return p;
}

template<class T>
OSTreeNode<T>* OST<T>::GetRoot() const{
	return root;
}

template<class T>
void OST<T>::MakeEmpty(OSTreeNode<T>* root){
	if(NULL != root){
		OSTreeNode<T>* left = root->left;
		OSTreeNode<T>* right = root->right;
		delete root;
		if(NIL != left)
			MakeEmpty(left);
		if(NIL != right)
			MakeEmpty(right);
	}
}

template<class T>
OST<T>::~OST(){
	MakeEmpty(root);
}

template<class T>
OSTreeNode<T>* OST<T>::OS_Select(OSTreeNode<T> * x,int i){
	int r = x->left->size + 1;
	if(r == i)
		return x;
	else if(i < r)
		return OS_Select(x->left,i);
	else
		return OS_Select(x->right,r - i);
}

template<class T>
int OST<T>::OS_Rank(OSTreeNode<T> *x){
	int r = x->left->size + 1;
	OSTreeNode<T> *y = x;
	while(y != root){
		if(y == y->parents->right)
			r = r + y->parents->left->size + 1;
		y = y->parents;
	}
	return r;
}


#endif /* OST_H_ */
