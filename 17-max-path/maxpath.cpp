#include <stddef.h>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

struct Node{
	int data;
	Node *left, *right;
};

Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

int maxPathSum(struct Node *root);

void insert(Node *root, int a1,int a2, char lr){
	if(root==NULL)
		return ;
	if(root->data==a1){
		switch(lr){
			case 'L':root->left=newNode(a2);
					break;
			case 'R':root->right=newNode(a2);
					break;
		}
	}
	insert(root->left,a1,a2,lr);
	insert(root->right,a1,a2,lr);
}

void inorder(Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		Node *root=NULL;
		while(n--){
			int a1,a2;
			char lr;
			cin>>a1>>a2>>lr;
			if(root==NULL){
				root=newNode(a1);
				switch(lr){
					case 'L':root->left=newNode(a2);
							break;
					case 'R':root->right=newNode(a2);
							break;
				}
			}
			else
				insert(root,a1,a2,lr);
		}
		//inorder(root);
		//cout<<endl;
		cout<<maxPathSum(root)<<endl;		
	}
}


pair<int,int> maxPathSumRec(struct Node * node) {
    if (node->left == NULL && node->right == NULL) {
        pair<int,int> p;
        p.first = node->data;
        p.second = node->data;
        return p;
    }

    pair<int,int> leftPair, rightPair;
    if (node->left == NULL) {
        rightPair = maxPathSumRec(node->right);
        rightPair.first += node->data;
        return rightPair;
    }

    if (node->right == NULL) {
        leftPair = maxPathSumRec(node->left);
        leftPair.first += node->data;
        return leftPair;
    }

    leftPair = maxPathSumRec(node->left);
    rightPair = maxPathSumRec(node->right);

    int bridge = leftPair.first + rightPair.first + node->data;

    if (bridge > leftPair.second && bridge > rightPair.second) {
        pair<int,int> newPair;
        newPair.second = bridge;
        newPair.first = max(leftPair.first, rightPair.first) + node->data;
        return newPair;
    }

    if (leftPair.second > rightPair.second) {
        leftPair.first += node->data;
        return leftPair;
    } else {
        rightPair.first += node->data;
        return rightPair;
    }
}


int maxPathSum(struct Node *root) {
    return maxPathSumRec(root).second;
}
