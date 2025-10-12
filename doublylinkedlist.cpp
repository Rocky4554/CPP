#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;   
};

void printforward(Node* ptr){
    
    while(ptr!=NULL){
        cout<<ptr->data+" ";
        ptr=ptr->next;
    }
}

// void printbackw(Node* ptr){
    
//         while(ptr!=NULL){
//             cout<<ptr->data+" ";
//             ptr=ptr->prev;
//         }
// }

int main(){

    Node* head = new Node();
    Node* second= new Node();
    Node* third= new Node();
    Node* four= new Node();

    head->data=1;
    head->next=second;
    head->prev=NULL;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=four;

    four->data=4;
    four->next=NULL;

    printforward(head);
    // void printbackward();
    
    return 0;
}