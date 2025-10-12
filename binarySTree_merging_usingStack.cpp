#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left=NULL;
    Node* right=NULL;
};
//creating a stack node.(it is not like implementing the stack)
class StackNode{
    public://stack creation using linked list.
    Node* d;//like int data in linked list.
    StackNode* next;// next of a node.
};

void push(StackNode** s,Node* x){//StackNode is like top of stack and Node8 x is like the data.
    //creating a new stackNode.
    StackNode* temp = new StackNode();

    temp->d=x;//temp->data=x;
    temp->next=*s;//temp->next=top of a stack which is (*s).
    (*s)=temp;//top=temp(making temp as top of stack)..
}

Node* pop(StackNode** s){//passing top of stack as argument.
    Node* t;//used to store a data which is poped from the stack.
    StackNode* temp;
    temp=*s;//storing head in temp;
    (*s)=(*s)->next;// decreasing the top value.
    t=temp->d;//
    free(temp);
    return t;
}

int isempty(StackNode* s){
    if(s==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
// end of stack related work.


Node* createNode(int val){// function to create a new node.
Node* node = new Node();
node->data=val;
node->left=NULL;
node->right=NULL;

return node;
}

void inorder(Node* root){
    if(root!=NULL){
       
        inorder(root->left);
         cout<<root->data<<" ";
        inorder(root->right);
    }
}

void merge(Node* root1,Node* root2){
    StackNode* st1=NULL;//empty stack for storing element of tree 1.
    Node* curr1=root1;//temp node storing root ogf tree 1.

    StackNode* st2=NULL;
    Node* curr2=root2;

    if(root1==NULL && root2==NULL)
    return;

    if(root1==NULL){
        inorder(root2);
    }

    if(root2==NULL){
        inorder(root1);
    }
    // if root of tree1 and tree2 are not empty and st1 andst2 are not empty
    while(curr1!=NULL ||curr2!=NULL || !isempty(st1)|| !isempty(st2)){
        //Now we are performing like inorder traversal(iterative).
        if(curr1!=NULL || curr2!=NULL){
            while(curr1!=NULL){// going to the leftmost of the Tree 1.
                  push(&st1,curr1);
                  curr1=curr1->left;
            }
            while(curr2!=NULL){// going to the leftmost of the Tree 2.
                  push(&st2,curr2);
                  curr2=curr2->left;
            }
        }
        else{
            if(isempty(st1)){
                while(!isempty(st2)){// here we are handling the condition in which one of the stack will become empty.
                    curr2=pop(&st2);//means we have printed all the node of one of the trees.
                    curr2->left=NULL;//poping the node and making its left child of poped node NULL.
                    inorder(curr2);
                }
            }
             if(isempty(st2)){
                while(!isempty(st1)){
                    curr1=pop(&st1);
                    curr1->left=NULL;
                    inorder(curr1);
                }
            }
            //pop element from both the stack and campare them.
            curr1=pop(&st1);
            curr2=pop(&st2);

            if(curr1->data <= curr2->data){// here we are comparing the two nod and printing it 
                cout<<curr1->data<<" ";
                curr1=curr1->right;
                push(&st2,curr2);//here we are again pushing back the unprinted node in the stack.  
                curr2=NULL;
            }
            else{
                cout<<curr2->data<<" ";
                curr2=curr2->right;
                push(&st1,curr1);
                curr1=NULL;
            }
        }

    }
}
int main(){

    Node* root1=createNode(24);
    root1->left=createNode(16);
    root1->right=createNode(30);
    root1->left->left=createNode(10);
    root1->left->right=createNode(16);
    root1->right->right=createNode(34);

    Node* root2=createNode(36);
    root2->left=createNode(18);
    root2->right=createNode(25);
    root2->left->left=createNode(14);
    root2->right->left=createNode(23);

    merge(root1,root2);

    return 0;
}

