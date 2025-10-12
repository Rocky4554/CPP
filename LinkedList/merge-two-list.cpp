
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

Node* mergedList(Node* head1, Node* head2){
       Node* t1=head1; Node* t2=head2;Node* dummy = new Node(-1);Node* temp=dummy;

       if(head1==NULL){
        return head2;
       }
       if(head2==NULL){
        return head1;
       }
       while(t1!=NULL && t2!=NULL){// remember the condition
          if(t1->data <= t2->data){
            temp->next=t1;
            temp=t1;
            t1=t1->next;
          }
          else{
            temp->next=t2;
            temp=t2;
            t2=t2->next;
          }          
       }
       if(t1){
        temp->next=t1;
       }else{
        temp->next=t2;
       }
       return dummy->next;
    }

int main(){
vector<int> arr1={2,4,8,10};
Node* head1=createList(arr1);
cout<< "Linked List 1"<<endl;
print(head1);

vector<int> arr2={1,3,3,6,11,14};
Node* head2=createList(arr2);
cout<< "Linked List 2"<<endl;
print(head2);

Node* merged=mergedList(head1, head2);
cout<<"Merged list is : "<<endl;

print(merged);

    return 0;
}



