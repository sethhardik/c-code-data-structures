#include<bits/stdc++.h>

using namespace std;

class node{                          // class of tree
	public:
		int data;
		node* left;
		node* right;
};

node* getnewnode(int data){            // create new node
	node* newnode=new node();
	newnode->data=data;
	newnode->right=NULL;
	newnode->left=NULL;
	return newnode;
}
node* insertion(node* root,int data){   // add new node according to the value
	if(root==NULL){
		root=getnewnode(data);
		return root;
	}
	else{
		if(data<=root->data){
			root->left=insertion(root->left,data);
//			root->left=cur;
		}
		else{
			root->right=insertion(root->right,data);
//			root->right=cur;
		}
	}
	return root;
}

void preorder(node* root){
	if(root==NULL) {
	return;
}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void postorder(node* root){
	if(root==NULL)  return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
void inorder(node* root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int height(node* root){ // no. of edges in the longest path from root to a leaf node
	// max depth of the node
	// depth is distance from the root 
	int leftheight=0,rightheight=0,max;
	if(root==NULL){
		return -1;
	}
	leftheight=height(root->left);
	rightheight=height(root->right);
	if(leftheight>rightheight){
		max=leftheight;
	}
	else max=rightheight;
	return max+1;
	
}

void left_shift(node* root){
        if(root==NULL){
            return;
        }
        left_shift(root->left);
        cout<<root->data<<" ";

    }

void right_shift(node* root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";
        right_shift(root->right);
    }

void topview(node * root) {
    left_shift(root);
    right_shift(root->right);
    }

int main()
{
	node* root=NULL;
	int no,data,high;
	cin>>no;
	while(no-->0){
		cin>>data;
		root=insertion(root,data);	
	}
	cout<<"preorder:"<<endl;
	preorder(root);
	cout<<endl<<"postorder:"<<endl;
	postorder(root);
	cout<<endl<<"inorder:"<<endl;
	inorder(root);
	cout<<endl<<"height:"<<endl;
	high=height(root);
	cout<<high;
	cout<<endl<<"topview:"<<endl;
	topview(root);
	return 0;
}


