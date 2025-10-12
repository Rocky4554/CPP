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

void inorder(Node* root){
    Node* ptr=root;
    stack<Node*> st;
    while(true){
        while(ptr!=NULL){
            st.push(ptr);
            ptr=ptr->left;
        }

        if(st.empty()){
            break;
        }
        ptr=st.top();
        st.pop();
        cout<<ptr->data<<" ";
        ptr=ptr->right;
    }
}

void preorder(Node* root){
    Node* ptr=root;
    stack<Node*> st;
    while(true){
        while(ptr!=NULL){
             cout<<ptr->data<<" ";
            st.push(ptr);
            ptr=ptr->left;
        }

        if(st.empty()){
            break;
        } 
        ptr=st.top();
        st.pop();
       
        ptr=ptr->right;
    }
}

void postorder(Node* root){
    Node* ptr= root;
    stack<Node*> st;
    while(true){
        if(ptr!=NULL){
            st.push(ptr);
            ptr=ptr->left;
        }
    else{
        if(st.empty()){
            break;
        }
            else{
            // ptr=st.top();
                if(st.top()->right==NULL){
                ptr=st.top();
                st.pop();
                cout<<ptr->data<<" ";
            
            while(ptr==st.top()->right){
                ptr=st.top();
                st.pop();
                cout<<ptr->data<<" ";
            }
         }
            if(!st.empty()){
             ptr=st.top()->right;
                }
            else{
             ptr=NULL;
                }
        }
    }
    }
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

int main(){

    Node* root = createNode(1);// creating a node by calling the fuction createNode;
    // cout<<root->data<<endl;
    root->left=createNode(2);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    root->right=createNode(3);
    root->right->left=createNode(6);
    root->right->right=createNode(7);

    inorder(root);
    cout<<"\n Preorder Traversal\n";
    preorder(root);
    cout<<"\n Postorder Traversal\n";
     postorder(root);

      cout<<"\n total nodes \n";
        cout<<totalnodes_recurssive(root);

    return 0;
}