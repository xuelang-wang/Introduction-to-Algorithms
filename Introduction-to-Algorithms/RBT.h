/*
 * RBT.h
 *
 *  Created on: 2017��5��13��
 *      Author: xiaoquan
 */

#ifndef RBT_H_
#define RBT_H_
#include <iostream>
#include<stack>
using namespace std;

static const int RED = 0;
static const int BLACK = 1;

/*���������ڵ�*/
template <class T>
struct RBTreeNode{
public:
    T key;
    int color;
    RBTreeNode<T>* parents;
    RBTreeNode<T>* left;
    RBTreeNode<T>* right;
	RBTreeNode():key(T()),color(BLACK),parents(NULL),left(NULL),right(NULL){}
};
/*����������*/
template <class T>
class RBT
{
private:
    RBTreeNode<T>* root;
    static  RBTreeNode<T> *NIL;
public:
    RBT();
    void LeftRotate(RBTreeNode<T> *x);
    void RightRotate(RBTreeNode<T> *x);

    void RBInsert(RBTreeNode<T> * z);
    void RBInsertFixup(RBTreeNode<T> * z);
    void RBInsertKey(const T& k);

    int RBDelete(RBTreeNode<T> * z);
    void RBDeleteFixup(RBTreeNode<T> * z);
    int RBDeleteKey(const T& k);

	void InorderTreeWalk() const;//�������

	/*����ָ��������ָ��͹ؼ���k,����TreeSearch����ָ������ؼ���k�Ľڵ㣨������ڵĻ���
	 * ָ��;���򷵻ؿ�ָ��NULL*/
	RBTreeNode<T> * TreeSearch(const T& k);

	//���غ�ڶ������о�����С�ؼ��ֵ�Ԫ�ؽڵ�ָ��
	RBTreeNode<T> * TreeMinimun(RBTreeNode<T> * pnode);

	//���غ�ڶ������о������ؼ��ֵ�Ԫ�ؽڵ�ָ��
	RBTreeNode<T> * TreeMaximun(RBTreeNode<T> * pnode);

	//���غ�ڶ������е�ǰ�ڵ��̽ڵ�ָ��
	RBTreeNode<T> * TreeSuccessor(RBTreeNode<T> * pnode);

	//���غ�ڶ������е�ǰ�ڵ�ǰ�̽ڵ�ָ��
	RBTreeNode<T> * TreePredecessor(RBTreeNode<T> * pnode);

    RBTreeNode<T>* GetRoot() const;
    void MakeEmpty(RBTreeNode<T>* root);
    ~RBT();
};


//����
template<class T>
RBTreeNode<T> *RBT<T>::NIL = new RBTreeNode<T>;


template<class T>
RBT<T>::RBT(){
	root = NULL;
}

template<class T>
void RBT<T>::LeftRotate(RBTreeNode<T> *x){
	RBTreeNode<T> * y = x->right;		//set y
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
}


template<class T>
void RBT<T>::RightRotate(RBTreeNode<T> *x){
	RBTreeNode<T> * y = x->left;		//set y
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
}
template<class T>
void RBT<T>::RBInsert(RBTreeNode<T> * z){
	if(NULL == root)
		root = z;
	else{
		RBTreeNode<T> * y = NIL;
		RBTreeNode<T> * x = root;
		while(x != NIL){
			y = x;
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
void RBT<T>::RBInsertFixup(RBTreeNode<T> * z){
	while(z->parents->color == RED){
		if(z->parents == z->parents->parents->left){
			RBTreeNode<T> * y = z->parents->parents->right;
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
			RBTreeNode<T> * y = z->parents->parents->left;
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
void RBT<T>::RBInsertKey(const T& k){
	RBTreeNode<T> *NewNode = new RBTreeNode<T>;
	NewNode->key = k;
	NewNode->color = RED;
	NewNode->left = NIL;
	NewNode->right = NIL;
	NewNode->parents = NIL;
	RBInsert(NewNode);
}
template<class T>
int RBT<T>::RBDelete(RBTreeNode<T> * z){
    RBTreeNode<T>* pnode = TreeSearch(z->key);
    if(NIL != pnode)
    {
        RBTreeNode<T>* qnode,*tnode;
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
void RBT<T>::RBDeleteFixup(RBTreeNode<T> * z){
	while(z != root && z->color == BLACK){
	        RBTreeNode<T> *w;
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
int RBT<T>::RBDeleteKey(const T& k){
	RBTreeNode<T> * newNode = new RBTreeNode<T>;
	newNode->key = k;
	return RBDelete(newNode);
}



template<class T>
void RBT<T>::InorderTreeWalk() const{
	   if(NULL != root)
	    {
	        stack<RBTreeNode<T>* > s;
	        RBTreeNode<T> *ptmpnode;
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
RBTreeNode<T> * RBT<T>::TreeSearch(const T& k){
    RBTreeNode<T>* pnode = root;
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
RBTreeNode<T> * RBT<T>::TreeMinimun(RBTreeNode<T> * pnode){
	if(pnode != NIL)
		while(pnode->left != NIL)
			pnode = pnode->left;
	return pnode;
}
//���ز��Ҷ������о������ؼ��ֵ�Ԫ�ؽڵ�ָ��
template<class T>
RBTreeNode<T> * RBT<T>::TreeMaximun(RBTreeNode<T> * pnode){
	if(pnode != NIL)
		while(pnode->right != NIL)
			pnode = pnode->right;
	return pnode;
}

template<class T>
RBTreeNode<T> * RBT<T>::TreeSuccessor(RBTreeNode<T> * pnode){
	if(pnode->right != NIL)
		return TreeMinimun(pnode->right);
	RBTreeNode<T> * p = pnode->parents;
	while(p != NIL && pnode == p->right){
		pnode = p;
		p = p->parents;
	}
	return p;
}

template<class T>
RBTreeNode<T> * RBT<T>::TreePredecessor(RBTreeNode<T> * pnode){
	if(pnode->left != NIL)
		return TreeMaximun(pnode->left);
	RBTreeNode<T> * p = pnode->parents;
	while(p != NIL && pnode == p->left){
		pnode = p;
		p = p->parents;
	}
	return p;
}

template<class T>
RBTreeNode<T>* RBT<T>::GetRoot() const{
	return root;
}

template<class T>
void RBT<T>::MakeEmpty(RBTreeNode<T>* root){
	if(NULL != root){
		RBTreeNode<T>* left = root->left;
		RBTreeNode<T>* right = root->right;
		delete root;
		if(NIL != left)
			MakeEmpty(left);
		if(NIL != right)
			MakeEmpty(right);
	}
}

template<class T>
RBT<T>::~RBT(){
	MakeEmpty(root);
}
#endif /* RBT_H_ */
