 #include<bits/stdc++.h>
 using  namespace std;

class Node{//struct Node
 public://not in c
    int data;//same
    Node* next;//stuct Node* next
 };

   void print(Node* ptr){
      
     while(ptr != NULL){
         cout << ptr->data <<" ";
        ptr= ptr->next;    
      }
   }

   Node* deleteatfirst(Node* head){
      Node* ptr=head;
      head=head->next;
      delete(ptr);//free(head); in c language.

      return head;
   }

   Node* deleteatend(Node* head){
      Node* ptr = head->next;
      Node* pre_ptr = head;
      while(ptr->next != NULL)
      {
         pre_ptr=pre_ptr->next;
         ptr = ptr->next;
      }
      pre_ptr->next=NULL;
      delete(ptr);

   return head;
   }

   Node* deleteatindex(Node* head, int pos){
      if(pos==0){
      return head->next;
      }
      Node* ptr = head;
      Node* pre_ptr=head;
      
      while(pos>0){
         pre_ptr=ptr;
         ptr=ptr->next;
         pos--;
      }
      pre_ptr->next=ptr->next;
      ptr = NULL;
      return head;
   }

   

 int main()
 {

    Node* head= new Node();//struct Node* head=NULL;
    Node* second=new Node();
    Node* third= new Node();
    Node* fourth = new Node();
    Node* five = new Node();

    head->data=1;//same in c
    head->next=second;
    
    second->data=2;
    second->next=third;
    
    third->data=3;
    third->next= fourth;  

    fourth->data=4;
    fourth->next=five; 

    five->data=5;
    five->next=NULL;
    
    cout<<"Our list before deletion\n";
    print(head);

    cout<<"\n List our deletion at first: \n";
    head=deleteatfirst(head);
    print(head);

    
    cout<<"\n List after deletion at end: \n";
    head=deleteatend(head);
    print(head);

    cout<<"\n List after deletion at index \n";
    head=deleteatindex(head,2);
    print(head);
   

    return 0;
 }