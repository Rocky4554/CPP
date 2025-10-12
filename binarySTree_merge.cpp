#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int x){
        val=x;
        left=right=NULL;
    }
};

// Node* createNode(int data){// function to create a new node.
// Node* node = new Node();
// node->val=data;
// node->left=NULL;
// node->right=NULL;

// return node;
// }
void inorder(Node* root){
    if(root!=NULL){
       
        inorder(root->left);
         cout<<root->val<<" ";
        inorder(root->right);
    }
}


void merge(Node* root1,Node* root2){
    if(root1==NULL && root2 == NULL)
    return;
    if(root1==NULL){
    inorder(root2);
    return;
    }
    if(root2==NULL){
    inorder(root1);
    return;
    }
    
    Node* temp1=root1;//a temporary pointer to hold the value of root1;
    Node* parent1=NULL;//a temporay pointer to hold the parent of root1;

    while(temp1->left){
        parent1=temp1;
        temp1=temp1->left;
    }
    
    Node* temp2=root2;//a temporary pointer to hold the value of root12;
    Node* parent2=NULL;//a temporay pointer to hold the parent of root12;
    
    while(temp2->left){
        parent2=temp2;
        temp2=temp2->left;
    }

    if(temp1->val <= temp2->val){

        cout<<temp1->val<<" ";
        if(parent1=NULL){// it means if a root1 has no parent it means it is the root of the tree.
        merge(root1->right,root2);// right of the the root of the tree as  the root. 
        }
    else{
        parent1->left=temp1->right;
        merge(root1,root2);
        }
    }
    else{
        cout<<temp2->val<<" ";

        if(parent2==NULL){
            merge(root1,root2->right);
        }
        else{
            parent2->left=temp2->right;
            merge(root1,root2);
        }
    }

}


int main(){
    Node* root1=NULL;
    root1=new Node(24);
    root1->left=new Node(16);
    root1->right=new Node(30);
    root1->left->left=new Node(10);
    root1->left->right=new Node(16);
    root1->right->right=new Node(34);

    // cout<<"first tree\n";
    // inorder(root1);
    
    Node* root2=NULL;
    root2=new Node(26);
    root2->left=new Node(18);
    root2->right=new Node(25);
    root2->left->left=new Node(14);
    root2->right->left=new Node(23);

    // cout<<"\n Second tree\n";
    // inorder(root2);
    
    merge(root1, root2);

    return 0;
}