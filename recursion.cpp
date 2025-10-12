#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int val){// function to create a new node.
Node* node = new Node();
node->data=val;
node->left=NULL;
node->right=NULL;

return node;
}

int totalnodes_recurssive(Node* root){
        int l=0,r=0;
        if(!root)
        return 0;
        else{
            l=totalnodes_recurssive(root->left);
            r=totalnodes_recurssive(root->right);

            return l+r+1;
        }
    }

int  main(){
    
    Node* root = createNode(1);// creating a node by calling the fuction createNode;
    // cout<<root->data<<endl;
    root->left=createNode(2);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    root->right=createNode(3);
    root->right->left=createNode(6);
    root->right->right=createNode(7);

    cout<<" total nodes \n";
    cout<<totalnodes_recurssive(root);

    return 0;
}