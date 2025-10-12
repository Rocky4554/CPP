#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
};

static Node* node;

// Node* createNode(int val){
//      Node* node=new Node();
//     node->data=val;
//     node->left=NULL;   
//     node->right=NULL;

//     return node;
// }

    Node* insertNode(Node* node,int data){
        if(node == NULL){
            node= new Node();
            node->val=data;
            
        }
        if(data<node->val)
            node->left=insertNode(node->left,data);
        if(data>node->val)
            node->right=insertNode(node->right,data);    
        

        return node;
    }
void create(int data){
     node=insertNode(node,data);
}

void inorder(Node* node){
    if(node){
       
        inorder(node->left);
         cout<<node->val<<" ";
        inorder(node->right);
    }
}

int main(){
    int ar[]={};
    int n=sizeof(ar)/sizeof(ar[0]);
    //gudiya5799
    int i;
    for(i=0;i<n;i++){
    create(ar[i]);
    }
    
    inorder(node);

    return 0;
}