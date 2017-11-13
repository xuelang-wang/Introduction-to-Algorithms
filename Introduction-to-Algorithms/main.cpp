/*
 * main.cpp
 *
 *  Created on: 2017年4月24日
 *      Author: xiaoquan
 */

#include<iostream>
#include<vector>
//#include"Sort.h"
////#include"BST.h"
//////#include"RBT.h"
////#include"OST.h"
////#include"DP.h"
////#include<cfloat>
//
//#include"Greedy.h"

#include"graph.h"
//#include"MST.h"
//#include"SSP.h"
//#include"ASP.h"
////#include"string_match.h"
//#include"num_theory.h"

//#include"CG.h"
using namespace std;
void PrintVec(vector<int> _A);

int main(){
	/*测试sort类方法*/
//	Sort s;
//	vector<int> A={2,8,7,9,3,5,2,4,4};
//	PrintVec(A);
//	s.ShellSort(A);
//	PrintVec(A);
//	s.HeapSort(A);
////	s.BubbleSort(A);
//	s.MergeSort(A,0,8);
////	s.InsertSort(A);
////	s.QucikSort(A,0,7);
////	s.RandomQucikSort(A,0,7);
////	vector<int> B;
////	s.CountSort(A,B,8);
////	PrintVec(B);
//	PrintVec(A);

//	/*测试BST类方法*/
//	BST bt;
//	TreeNode * root = new TreeNode(4);
//	root->left = new TreeNode(2);
//	root->left->parents = root;
//	root->left->left = new TreeNode(1);
//	root->left->right = new TreeNode(3);
//	root->left->left->parents = root->left;
//	root->left->right->parents = root->left;
//	root->right = new TreeNode(6);
//	root->right->parents = root;
//	root->right->left = new TreeNode(5);
//	root->right->right = new TreeNode(7);
//	root->right->left->parents = root->right;
//	root->right->right->parents = root->right;
//
//	bt.InorderTreeWark(root);
//	cout << endl;
//	bt.PreorderTreeWark(root);
//	cout << endl;
//	bt.PostorderTreeWark(root);
//	cout << endl;
//
//	cout << bt.TreeSearch(root,1) << "," << bt.TreeSearch(root,9) << endl;
//	cout << bt.ItearativeTreeSearch(root,1) << "," << bt.ItearativeTreeSearch(root,9) << endl;
//
//	cout << "Min: " << bt.TreeMinimun(root)->val << "Max: " << bt.TreeMaximun(root)->val << endl;
//
//	cout << "Successor: " << bt.TreeSuccessor(root)->val << "Predecessor: " << bt.TreePredecessor(root)->val << endl;
//
//	TreeNode * temp = new TreeNode(8);
//	bt.TreeInsert(root,temp);
//	bt.InorderTreeWark(root);
//	cout << endl;
//	bt.TreeDelete(root,temp);
//	bt.InorderTreeWark(root);
//	cout << endl;
//
//	bt.TreeDelete(root,root);
//	bt.InorderTreeWark(root);
//	cout << endl;

//	/*测试RBT类方法*/
//    RBT<int> rbtree;
//    rbtree.RBInsertKey(41);
//    rbtree.RBInsertKey(38);
//    rbtree.RBInsertKey(31);
//    rbtree.RBInsertKey(12);
//    rbtree.RBInsertKey(19);
//    rbtree.RBInsertKey(8);
//    cout<<"root is: " << (rbtree.GetRoot()->key) << endl;
//    cout << "Inorder walk red black tree:" << endl;
//    rbtree.InorderTreeWalk();
//    cout<<"minmum is: "<<rbtree.TreeMinimun(rbtree.GetRoot())->key <<endl;
//    cout<<"maxmum is: "<<rbtree.TreeMaximun(rbtree.GetRoot())->key <<endl;
//    const int t = 19;
//    cout<<"19 successor is: " << rbtree.TreeSuccessor(rbtree.TreeSearch(t))->key<<endl;
//    cout<<"19 predecessor is: "<<rbtree.TreePredecessor(rbtree.TreeSearch(t))->key<<endl;
//    if(rbtree.RBDeleteKey(38)==0)
//    	cout<<"delete 38 successfully"<<endl;
//    cout<<"root is: "<<rbtree.GetRoot()->key<<endl;
//    cout<<"Inorder walk red black tree:"<<endl;
//    rbtree.InorderTreeWalk();

//	/*测试RBT类方法*/
//	OST<int> ostree;
//	ostree.RBInsertKey(41);
//	ostree.RBInsertKey(38);
//	ostree.RBInsertKey(31);
//	ostree.RBInsertKey(12);
//	ostree.RBInsertKey(19);
//	ostree.RBInsertKey(8);
//	cout<<"root is: " << (ostree.GetRoot()->key) << endl;
//	cout << "Inorder walk red black tree:" << endl;
//	ostree.InorderTreeWalk();
//
//	cout << "3th order is:" << ostree.OS_Select(ostree.GetRoot(),3)->key << endl;
//	cout << "5th order is:" << ostree.OS_Select(ostree.GetRoot(),5)->key << endl;
//
//	cout << "root's order is: " << ostree.OS_Rank(ostree.GetRoot()) << endl;
//	cout<<"minmum is: "<<ostree.TreeMinimun(ostree.GetRoot())->key <<endl;
//	cout<<"maxmum is: "<<ostree.TreeMaximun(ostree.GetRoot())->key <<endl;
//	const int t = 19;
//	cout<<"19 successor is: " << ostree.TreeSuccessor(ostree.TreeSearch(t))->key<<endl;
//	cout<<"19 predecessor is: "<<ostree.TreePredecessor(ostree.TreeSearch(t))->key<<endl;
//	if(ostree.RBDeleteKey(38)==0)
//		cout<<"delete 38 successfully"<<endl;
//	cout<<"root is: "<<ostree.GetRoot()->key<<endl;
//	cout<<"Inorder walk red black tree:"<<endl;
//	ostree.InorderTreeWalk();

	/*测试DP.h*/
//	vector<int> p = {1,5,8,9,10,17,17,20,24,30};
//	for(int i = 1;i <= 10;i++){
//		cout << "自顶向下： " << endl;
//		cout << i << " 最大利润： " << Cut_Rod(p,i) << '\n';
//		cout << "带备忘的自顶向下： " << endl;
//		cout << i << " 最大利润： " << Memoized_Cut_Rod(p,i) << '\n';
//		cout << "自下向上： " << endl;
//		cout << i << " 最大利润： " << Bottom_Up_Cut_Rod(p,i) << '\n';
//	}
//
//	vector<int> s(11,0);
//	vector<int> r = Extended_Bottom_Up_Cut_Rod(p,10,s);
//	PrintVec(r);
//	PrintVec(s);
//	for(int i = 1;i <= 10;i++){
//		cout << i << ":";
//		Print_Cut_Rod_Solution(p,i);
//		cout << '\n';
//	}

//	vector<int> p = {30,35,15,5,10,20,25};
//	vector<vector<int> > s(6,vector<int>(7,0));
//	vector<vector<int> > m = Matrix_Chain_Order(p,s);
//	Print_Optimal_Parens(s,1,6);

//	string X("ABCBDAB");
//	string Y("BDCABA");
//	vector<vector<int> > b(8,vector<int>(7,0));
//	vector<vector<int> > c = LCS_Length(X,Y,b);
//	Print_LCS(b,X,X.length(),Y.length());

//	vector<double> p = {0.0,0.15,0.1,0.05,0.1,0.2};
//	vector<double> q = {0.05,0.1,0.05,0.05,0.05,0.1};
//	vector<vector<int> > root(6,vector<int>(6,0));
//	vector<vector<double> > m = Optimal_BST(p,q,5,root);
//
//    cout << "最优二叉树结构：" << '\n';
//    Construct_Optimal_BST(root,1,5,-1);

	/*测试Greedy.h*/
//	vector<int> s = {0,1,3,0,5,3,5,6,8,8,2,12};
//	vector<int> f= {0,4,5,6,7,9,9,10,11,12,14,16};
//	vector<int> RecurA = Recursive_Activity_Selector(s,f,0,11);
//	vector<int> GreedyA = Greedy_Activity_Selector(s,f);
//	PrintVec(RecurA);
//	PrintVec(GreedyA);

//    int n = 5;
//    int W = 17;
//    vector<int> weight = {3, 4, 7, 8, 9};
//    vector<int> v = {4, 5, 10, 11, 13};
//    vector<vector<int> > dps(n+1,vector<int>(W+1,0));
//
//    cout << Knapsack(v,weight,W,dps) << endl;
//    vector<int> xx = findPath(v,weight,W,dps);
//	PrintVec(xx);

	//Huffman
//	vector<Node *> C;
//	C.push_back(new Node('a',45));
//	C.push_back(new Node('b',13));
//	C.push_back(new Node('c',12));
//	C.push_back(new Node('d',16));
//	C.push_back(new Node('e',9));
//	C.push_back(new Node('f',5));
//	Node *head = HUFFMAN(C);
//


//测试graph.h

	Graph G(6,8);
	G.addEdge(1,2);
	G.addEdge(1,4);
	G.addEdge(2,5);
	G.addEdge(3,5);
	G.addEdge(3,6);
	G.addEdge(4,2);
	G.addEdge(5,4);
	G.addEdge(6,6);
//
//	G.BFS(1);
//	G.Print_Path(1,6);
//
//	G.DFS();

	//测试拓扑排序
	list<Node> res = G.TopologicalSort();

	for(auto tp:res){
		cout << "Node" << tp.num << " " << tp.d << "/" << tp.f << ",  ";
	}
//测试string_match.h
//	string T("bacbabaababacabab");
//	string P("ababaca");
//
//	cout << "Naive :\n";
//	vector<int> res1 = Naive_String_Matcher(T,P);
//
//	cout << "KMP : \n";
//	vector<int> res2 = KMP_Matcher(T,P);

//测试"MST.h"
//	Graph_Mst G(9,15);
//	G.addEdge(1,2,4);
//	G.addEdge(1,8,8);
//	G.addEdge(2,3,8);
//	G.addEdge(2,8,11);
//	G.addEdge(3,4,7);
//	G.addEdge(3,6,4);
//	G.addEdge(3,9,2);
//	G.addEdge(4,5,9);
//	G.addEdge(4,6,14);
//	G.addEdge(5,6,10);
//	G.addEdge(6,7,2);
//	G.addEdge(7,9,6);
//	G.addEdge(7,8,1);
//	G.addEdge(8,9,7);
//
//	vector<Node_Mst> res = G.MST_Prim(1);
//	G.MST_Print_Path(res);

////测试"SSP.h"
//	Graph_Ssp G(9,15);
//	G.addEdge(1,2,4);
//	G.addEdge(1,8,8);
//	G.addEdge(2,3,8);
//	G.addEdge(2,8,11);
//	G.addEdge(3,4,7);
//	G.addEdge(3,6,4);
//	G.addEdge(3,9,2);
//	G.addEdge(4,5,9);
//	G.addEdge(4,6,14);
//	G.addEdge(5,6,10);
//	G.addEdge(6,7,2);
//	G.addEdge(7,9,6);
//	G.addEdge(7,8,1);
//	G.addEdge(8,9,7);
//
//	bool res1 = G.Bellman_Ford(1);
//	G.SSP_Print_Path(1,5);
//
//	vector<Node_Ssp> res2 = G.Dijkstra(1);
//	cout << "\n";
//	G.SSP_Print_Path(1,5);

//	for(int i = 0;i < (int)res2.size();i++){
//		if(i+1 != res2.size())
//			cout << res2[i].num << "->";
//		else
//			cout << res2[i].num << "\n";
//	}

//	//测试"ASP.h"
//	Graph_ASP G(6);
//	G.addEdge(2,1,1);
//	G.addEdge(1,5,-1);
//	G.addEdge(4,1,-4);
//	G.addEdge(2,4,2);
//	G.addEdge(3,2,2);
//	G.addEdge(6,2,5);
//	G.addEdge(5,2,7);
//	G.addEdge(3,6,-8);
//	G.addEdge(6,3,10);
//	G.addEdge(4,5,3);
//
//
//	matrix res1 = G.Slow_All_Pairs_Shortest_Paths();
//	matrix res2 = G.Faster_All_Pairs_Shorest_Paths();
//	matrix res3 = G.Floyd_Warshall();
//	G.Print_Matrix(res1);
//	G.Print_Matrix(res2);
//	G.Print_Matrix(res3);

////测试"num_theory.h"
//	vector<int> s = Modular_Linear_Equation_Solver(14,30,100);
//    return 0;

//	测试CG.h(计算几何学)
//	point<int> p1,p2,p3,p4;
//	p1 = make_pair(1,1);
//	p2 = make_pair(2,2);
//	p3 = make_pair(1,2);
//	p4 = make_pair(2,1);
//	cout << "Segment:" <<
//			"point(" << p1.first << "," << p1.second << ") to " <<
//			"point(" << p2.first << "," << p2.second << ") and " <<
//			"Segment:" <<
//			"point(" << p1.first << "," << p1.second << ") to " <<
//			"point(" << p2.first << "," << p2.second << ") ";
//	cout << (Segments_Intersect(p1,p2,p3,p4)?"Intersect":"No Intersect") << "\n";
//	p3 = make_pair(1,2);
//	p4 = make_pair(2,3);
//	cout << "Segment:" <<
//			"point(" << p1.first << "," << p1.second << ") to " <<
//			"point(" << p2.first << "," << p2.second << ") and " <<
//			"Segment:" <<
//			"point(" << p3.first << "," << p3.second << ") to " <<
//			"point(" << p4.first << "," << p4.second << ") ";
//	cout << (Segments_Intersect(p1,p2,p3,p4)?"Intersect":"No Intersect") << "\n";
//
//	p3 = make_pair(1,2);
//	p4 = make_pair(2,2);
//	cout << "Segment:" <<
//			"point(" << p1.first << "," << p1.second << ") to " <<
//			"point(" << p2.first << "," << p2.second << ") and " <<
//			"Segment:" <<
//			"point(" << p3.first << "," << p3.second << ") to " <<
//			"point(" << p4.first << "," << p4.second << ") ";
//	cout << (Segments_Intersect(p1,p2,p3,p4)?"Intersect":"No Intersect") << "\n";




		return 0;

}


void PrintVec(vector<int> _A){
	for(unsigned int i = 0;i < _A.size();i++){
		cout << _A[i] << ", ";
	}
	cout << endl;
}
