#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

struct Node* createNode(int val){
    Node* node=new Node();
    node->data=val;
    node->left=NULL;   
    node->right=NULL;

    return node;
}

void preorder(Node* root){
    if(root){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void remove_node(Node* root,Node* temp2){
    queue<Node*> q2;
    q2.push(root);
    Node* temp;

    while(!q2.empty()){
        temp=q2.front();
        q2.pop();
        if(temp == temp2){
            temp=NULL;
            delete(temp2);
            return;
        }
        if(temp->right){
            if(temp->right==temp2){
                temp->right==NULL;
                delete(temp2);
                return;
            }
            else{
                q2.push(temp->right);
            }
        }
        if(temp->left){
            if(temp->left==temp2){
                temp->left==NULL;
                delete(temp2);
                return;
            }
            else{
                q2.push(temp->left);
            }
        }
     
    }
 
}

Node* find_node(Node* root,int key){
    if(root==NULL)
        return NULL;
    if(root->left==NULL && root->right==NULL){
        if(root->data==key)
            return NULL;
            else
            return root;
        
        return root;
    }
        queue<Node*> q;
        q.push(root);
        Node* temp;
        Node* res=NULL;
    
        while(!q.empty()){
            temp=q.front();
            q.pop();
           
            if(temp->data ==key)
                res=temp;
            
            if(root->left)
            q.push(root->left);
            if(root->right)
            q.push(root->right);

        }
    
        if(res!=NULL){
        int x=temp->data;
            remove_node(root,temp);//deleting that node.
            res->data=x;
        }
        return root;
}

int main(){

    Node* root = createNode(1);
    root->left =createNode(2);
    root->right =createNode(3);
    root->left->left =createNode(4);
    root->left->right =createNode(5);
   root->right->left =createNode(6);
    root->right->right=createNode(7);
    root->left->right->left=createNode(8);
    root->right->right->left =createNode(9);
    root->right->right->right =createNode(10);

    cout<<"Preordre traversal\n ";
    preorder(root);

    int key=6;
    root = find_node(root,key); 
    cout<<" \n Our tree after deletion \n";
    preorder(root);

return 0;
}