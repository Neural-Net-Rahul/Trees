#include<bits/stdc++.h>
#include<iostream>
using namespace std;
# define ll long long int 

/*
Input 
1 2 3 4 -1 -1 5 -1 6 7 -1 -1 -1 -1 -1

Output
1 M
1 -> 2 L
1 -> 3 R
2 -> 4 L
3 -> 5 R
4 -> 6 R
5 -> 7 L
preOrder
1 2 4 6 3 5 7 
inOrder
4 6 2 1 3 7 5 
postOrder
6 4 2 7 5 3 1 


*/

struct Node{
	int data;
	Node*left;
	Node*right;
public:
	Node(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

// take input in level order traversal
// i used queue to print level order traversal
// now let's use queue to take input as level order traversal
Node*createBinaryTree(){
	int data;
	cin>>data;
	if(data==-1){
		return NULL;
	}
	Node*root = new Node(data);
	queue<Node*>q;
	q.push(root);
	while(!q.empty()){
		Node*a = q.front();
		q.pop();
		int dataLeft;
		cin>>dataLeft;
		if(dataLeft!=-1){
			Node*node1 = new Node(dataLeft);
			a->left = node1;
			q.push(node1);
		}
		else{
			a->left = NULL;
		}
		int dataRight;
		cin>>dataRight;
		if(dataRight!=-1){
			Node*node2 = new Node(dataRight);
			a->right = node2;
			q.push(node2);
		}
		else{
			a->right = NULL;
		}
	}
	return root;
}

void printBinaryTree(Node*root){
	if(root==NULL){
		return;
	}
	queue<pair<pair<Node*,Node*>,char>>q;
	q.push({{root,NULL},'M'});
	while(!q.empty()){
		pair<pair<Node*,Node*>,char>p = q.front();
		q.pop();
		Node*child = p.first.first;
		Node*parent = p.first.second;
		char side = p.second;
		if(parent!=NULL){
			cout<<parent->data<<" -> "<<child->data<<" "<<side<<endl;
		}
		else{
			cout<<child->data<<" "<<side<<endl;
		}
		if(child->left!=NULL){
			q.push({{child->left,child},'L'});
		}
		if(child->right!=NULL){
			q.push({{child->right,child},'R'});
		}
	}
}

void preOrder(Node*root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(Node*root){
	if(root==NULL){
		return;
	}
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

void postOrder(Node*root){
	if(root==NULL){
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}

int main(){
	Node*root = createBinaryTree();
	printBinaryTree(root); // level order {{node,parent},side}

	// PreOrder
	// Root, Left, Right
	cout<<"preOrder"<<endl;
	preOrder(root);
	cout<<endl;

	// InOrder
	// Left, Root, Right
	cout<<"inOrder"<<endl;
	inOrder(root);
	cout<<endl;

	// PostOrder
	// Left, Right, Root
	cout<<"postOrder"<<endl;
	postOrder(root);
	cout<<endl;
}
