#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

struct Node* createNode(int val){
    struct Node* node=new Node();
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

  Node* mirrorTree(Node* root){//printing mirror image of a tree.
      Node* temp=new Node();
      if(root){
          mirrorTree(root->left);
          mirrorTree(root->right);

          temp=root->left;//swaping pointers on each recurssive call of left and right subtree.Which will create the new mirror tree.
          root->left=root->right;
          root->right=temp;
      }
    return root;
 }

bool mirror(Node* p,Node* q)// checking if trees are mirror or not.
{
     if(p==NULL && q==NULL)
     return true;
     if(p==NULL || q==NULL )
     return false;
     if(p->data == q->data){
         return mirror(p->left,q->right) && mirror(p->right,q->left);// here we are checking right of tree1 with left of tree2
        //  and vice versa.
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

     Node* root2 = createNode(1);//creation of second tree.
    root2->left=createNode(3);
    root2->left->left=createNode(7);
    root2->left->right=createNode(6);
    root2->right=createNode(2);
    root2->right->left=createNode(3);
    root2->right->right=createNode(4);


    cout<<"Preordre traversal\n ";
    preorder(root);

    cout<<" \nPreordre traversal of second tree \n ";
    preorder(root2);

    root=mirrorTree(root);
    cout<<"\n Mirror tree traversal\n ";
    preorder(root);

    if(mirror(root,root2)){// passing tree1 and tree2.
        cout<<"\n Tree is mirror \n";
    }
    else{
        cout<<"\nTree is not mirror\n";
    }

return 0;
}