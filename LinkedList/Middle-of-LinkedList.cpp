
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

Node* middleNode(Node* head){
       Node *slw=head, *fst=head;
       while(slw!=NULL && fst!=NULL && fst->next!=NULL){// remember the condition
          slw=slw->next;
          fst=fst->next->next;
       }
       return slw;
    }

int main(){
vector<int> arr={1,2,3,4,5,6};
Node* head=createList(arr);
cout<< "Original Linked List"<<endl;
print(head);

Node* middle=middleNode(head);
cout<<"Middle of list is: "<<middle->data<<endl;

    return 0;
}



