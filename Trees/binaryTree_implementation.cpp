#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

Node* createNode(int val){// function to create a new node.
Node* node = new Node();
node->data=val;
node->left=NULL;
node->right=NULL;

return node;
}

// Node* search(Node* root,int val){
//     if(root == NULL){
//         return NULL;
//     }
//     queue<Node*> q;
//     q.push(root);
//     while(!q.empty()){
//         int temp=q.front();
//         q.pop();
//     }
// }
 void inorder(Node* root){
     if(root){
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
     }
}

void preorder(Node* root){
    if(root){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);

    }
}

void postorder(Node* root){
    if(root){
     preorder(root->left);
        preorder(root->right);
         cout<<root->data<<" ";
    }
}

void insertion(Node* root,int val){
    Node* temp=new Node();
    Node* new_node=createNode(val);
    queue<Node*> q;
    if(root!=NULL){
        q.push(root);
    }
    while(!q.empty()){
        temp=q.front();
        q.pop();
        if(temp->left){
            q.push(temp->left);
         }
        else{
            temp->left=new_node;
            break;
            }
         if(temp->right){
            q.push(temp->right);
        }
        else{
            temp->right=new_node;
            break;
        }
    }

}
Node* deepestNode(Node* root){
    queue<Node*> q;
    Node *temp = new Node();
    if(root!=NULL){
        q.push(root);
    }
    while(!q.empty()){
        temp =q.front();
        q.pop();
    
        if(temp->left)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);
    }
    return temp;
  }

  int height(Node* root){
      if(root == NULL)
      return 0;
      else{
          int leftheight=height(root->left);// left height
          int rightheight=height(root->right);// right height.

          if(leftheight>rightheight){
          return leftheight+1;
          }
          else{
              return rightheight+1;
          }
      }
  }

  int No_ofleaves(Node* root){
      int count=0;
       queue<Node*> q;
    Node* temp = new Node();
    if(root!=NULL){
        q.push(root);
    }
    while(!q.empty()){
        temp =q.front();
        q.pop();
        if(temp->left==NULL && temp->left==NULL){
            count++;
        }
       if(temp->left)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);
    }
    return count;
    }

    int maximum(Node* root){
        int max=INT_MAX;int root_val,left_max,right_max;
        if(root==NULL)
        return 0;
        else{
        root_val=root->data;

        left_max=maximum(root->left);
        right_max=maximum(root->right);

        if(left_max>right_max){
            max=left_max;
        }else{
            max=right_max;;
        }
        if(root_val>max){
        
        return root_val;
        }
        else{
        return max;
        }
        }
    }

    int totalnodes(Node* root){
        queue<Node*> q;
        Node* temp = new Node();
        int count=0;
        if(root==NULL){
            return 0;}
        else{
            q.push(root);
        
            while(!q.empty()){
                temp =q.front();
                q.pop();
                count++;
            
             if(temp->left)
                q.push(temp->left);
             if(temp->right)
                q.push(temp->right);
            }
            return count++;
        }
    
    }
    
    void reverse_levelorder(Node* root){
        queue<Node*> q;stack<Node*> st;
        Node* temp = new Node();
        Node* res = new Node();
        if(root!=NULL){
        q.push(root);
        }
        while(!q.empty()){
            temp =q.front();
            q.pop();
            
            if(temp->left)
            q.push(temp->left);
            if(temp->right)
            q.push(temp->right);
            st.push(temp);
        }
        while(!st.empty()){
            res=st.top();
            st.pop();
            cout<<res->data<<" ";
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

    cout<<"Inorder traversal\n";
    inorder(root);
    cout<<"\nPreorder traversal\n";
    preorder(root);
    cout<<"\nPostorder traversal\n";
    postorder(root);

    insertion(root,10);
    cout<<"\n Tree after insertion \n";
    inorder(root);
    cout<<"\nDeepsest node \n";
    cout<<deepestNode(root);

    cout<<"\n Height of a tree \n";
    cout<<height(root);
   cout<<"\n No of leaves nodes of a tree \n";
    cout<<No_ofleaves(root);
    cout<<"\n Maximum node of a tree \n";
    cout<<maximum(root);
    cout<<"\n Total nodes in a tree \n";
    cout<<totalnodes(root);
    cout<<"\nReverse level order \n";
    reverse_levelorder(root);
    
    cout<<"\n total nodes \n";
    cout<<totalnodes_recurssive(root);

    

    return 0;
}