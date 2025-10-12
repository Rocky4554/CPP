
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

int cycle(Node* head){
       Node *slw=head, *fst=head;
       while(slw!=NULL && fst!=NULL && fst->next!=NULL){
          slw=slw->next;
          fst=fst->next->next;
          if(slw==fst)
          return 1;

       }
       return 0;
    }

    // Starting point of cycle
    Node* cyclicNode(Node* head){
       Node *slw=head, *fst=head;
       bool cycle=false;
       while(slw!=NULL && fst!=NULL && fst->next!=NULL){
          slw=slw->next;
          fst=fst->next->next;
          if(slw==fst){
            cycle=true;
            break;
          }
        }

          if(!cycle){
            return NULL;
          }
          slw=head;
          while(slw!=fst){
            slw=slw->next;
            fst=fst->next;
          }
           return slw;  
    }

      Node* breakCycle(Node* head){
       Node *slw=head, *fst=head;
       bool cycle=false;
       while(slw!=NULL && fst!=NULL && fst->next!=NULL){
          slw=slw->next;
          fst=fst->next->next;
          if(slw==fst){
            cycle=true;
            break;
          }
        }

          if(!cycle){
            return NULL;
          }
          slw=head;
          Node* prev=NULL;
          while(slw!=fst){
            slw=slw->next;
            prev=fst;// maintaing the previous value of fast pointer;
            fst=fst->next;
          }
          prev->next=NULL;// in this point cycle is removed by making the prev value of fast pointer NULL
          return head;  // returning the full Linked list after removing the cycle;
    }

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    Node* head = createList(arr);

    // Make it cyclic: last node points to the 3rd node (value 3)
    Node* temp = head;
    Node* third = nullptr;
    int count = 1;

    while (temp->next != nullptr) {
        if (count == 3) {
            third = temp; // 3rd node (value = 3)
        }
        temp = temp->next;
        count++;
    }
    // Create cycle
    temp->next = third; 

    cout << "Cycle is present: " << cycle(head) << endl;

    Node* node=cyclicNode(head);
    cout<<"Starting point of cycle: "<<node->data<<endl;

    Node* newhead=breakCycle(head);
     cout << "Cycle is present or not after removing cycle: " << cycle(newhead) << endl;
    

    return 0;
}




