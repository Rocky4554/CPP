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
     
void levelorder(Node* root){
    queue<Node*> q;
    Node* temp = new Node();
    if(root!=NULL){
        q.push(root);
    }
    while(!q.empty()){
        temp =q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left)
        q.push(temp->left);
        if(temp->right)
        q.push(temp->right);
    }
    }

    void levelorder1(Node* root){//line by line
        
        if(!root){
            return;
        }
            queue<Node*> q;
            Node* temp = new Node();
            q.push(root);
            // int count=q.size();
        
        while(!q.empty()){      
            int count=q.size();
            while(count>0)
            {
                temp=q.front();
                q.pop();
                cout<<temp->data<<" ";
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
                count--;
            }
            cout<<endl;
         
            } 
         }

void levelorderspiral(Node* root)
{
 
    deque<Node*> d;
 
    // Push root
    d.push_back(root);
 
    // Direction 0 shows print right to left
    // and for Direction 1 left to right
    int dir = 0;
    while (!d.empty()) {
        int size = d.size();
        while (size--) {
            // One whole level
            // will be print in this loop
 
            if (dir == 0) {
                Node* temp = d.back();
                d.pop_back();
                if (temp->right)
                    d.push_front(temp->right);
                if (temp->left)
                    d.push_front(temp->left);
                cout << temp->data << " ";
            }
            else {
                Node* temp = d.front();
                d.pop_front();
                if (temp->left)
                    d.push_back(temp->left);
                if (temp->right)
                    d.push_back(temp->right);
                cout << temp->data << " ";       
            }
        }
        cout << endl;
        // Direction change
        dir = 1 - dir;
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

    cout<<"\n Levelorder Traversal in one line \n";
    levelorder(root);
     cout<<"\n Levelorder Traversal in line by line \n";
    levelorder1(root);
    cout<<"\n Levelorder Traversal in spiral form\n";
    levelorderspiral(root);

 
    return 0;
}
