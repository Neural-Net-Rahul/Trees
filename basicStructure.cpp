#include<bits/stdc++.h>
#include<iostream>
using namespace std;
# define ll long long int 

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

int main(){
	Node*root = new Node(1);
	Node*node1 = new Node(2);
	Node*node2 = new Node(3);
	root->left = node1;
	root->right = node2;
	cout<<root->data<<endl;
	cout<<root->left->data<<endl;
	cout<<root->right->data<<endl;
}
