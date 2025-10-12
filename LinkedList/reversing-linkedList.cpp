#include<iostream>
#include<vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next; // Node is a data type like int

    Node(int val, Node* next1)
    {
        data = val;
        next =next1 ;
    }

    Node(int val)
    {
        data = val;
        next =NULL ;
    }
};

Node* createList(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* temp=head;
    for(int i=1;i<arr.size();i++){
        Node* newNode = new Node(arr[i]);
        temp->next=newNode;
        temp=newNode;
    }

    return head;
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

Node* reverse(Node* head){
    Node* prev=NULL;
    Node* curr=head;
    Node* next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;//this is the new head of reverse list
}

int main(){
vector<int> arr={1,2,3,4,5,6,7};
Node* head=createList(arr);
cout<< "Original Linked List"<<endl;
print(head);

cout<< "Reversed Linked List:"<<endl;
head=reverse(head);
print(head);

    return 0;
}



