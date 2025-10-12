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

void preorder(Node* root){
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

int main(){

    Node* root = createNode(1);// creating a node by calling the fuction createNode;
    // cout<<root->data<<endl;
    root->left=createNode(2);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    root->right=createNode(3);
    root->right->left=createNode(6);
    root->right->right=createNode(7);

    preorder(root);

    return 0;
}