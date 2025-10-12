#include<bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
};

static Node* root;// global root(making node constant)

    Node* insertNode(Node* root,int data){//creating BST using constant root.(static Node* root)
        if(root == NULL){
            Node* node= new Node();
            node->val=data;
            return node;
            
        }
        if(data<=root->val)
            root->left=insertNode(root->left,data);
        if(data>root->val)
            root->right=insertNode(root->right,data);    
        
        return root;
    }

void create(int data){//only global root can be passed here.
     root=insertNode(root,data);
}

void inorder(Node* root){
    if(root!=NULL){
       
        inorder(root->left);
         cout<<root->val<<" ";
        inorder(root->right);
    }
}
int minimum(Node* root){// finding inorder successor(minimum in right subtree)
    if(root->left!=NULL){
        return minimum(root->left);
        }
        else{
            return root->val;
        }
}

// int maximum(Node* node){// find inorder predecessor(maximium in left subtree)
//     if(node->right!=NULL){
//         return  maximum(node->right);
//     }
//     else{
//         return node->val;
//     }
// }

Node* deletion(Node* root,int data){
    if(root==NULL){
        return NULL;
    }
    if(data>root->val)// data is greater than root data.
        root->right=deletion(root->left,data);
    else if (data<root->val)//data is less than root data. 
        root->left=deletion(root->left,data);
        else//data match
        {
            if(root->left!=NULL && root->right!=NULL){// node having both child.
                int lmax=minimum(root->left);//finding min or max node to be replaced
                root->val=lmax;//
                root->left=deletion(root->left,lmax);//agan calling 
                return root;
            }
            else if(root->left!=NULL){//node having only left child.
                return root->left;
            }
            else if(root->right!=NULL){//node having only right child
                return root->right;
            }
            else{// no child.
                return NULL;
            }

        }
   return root;
}

void printrange(Node* root,int n1,int n2){//given a range n1 to n2.
    if(root==NULL){
        return;
    }
    if(root->val>n1 && root->val>n2 ){
    
     printrange(root->left,n1,n2);
    }
    else if(root->val< n1 && root->val< n2){
    printrange(root->right,n1,n2);
    }
    else{
        printrange(root->left,n1,n2);// printing in inorder(increasing)
        cout<<root->val<<" ";
        printrange(root->right,n1,n2);

    }
}

// void inorder(Node* root){
//     if(root!=NULL){
       
//         inorder(root->left);
//          cout<<root->val<<" ";
//         inorder(root->right);
//     }
// }

int main(){
    int ar[]={11,6,8,19,4,10,5,17,43,31};
    int n=sizeof(ar)/sizeof(ar[0]);
    //gudiya5799
    int i;
    for(i=0;i<n;i++){
    create(ar[i]);
    }
    cout<<"inorder traversal\n";// only global root can be passed in a main function
    inorder(root);

    cout<<deletion(root,5);
    cout<<" \ninorder traversal after deletion \n";
    inorder(root);
    
    cout<<"\n nodes in range are\n";
    printrange(root,7,48);


    return 0;
}