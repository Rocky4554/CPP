 #include<bits/stdc++.h>
 using  namespace std;

class Node{//struct Node
 public:
    int data;//same
    Node* next;//stuct Node* next poine
 };

   void print(Node* ptr){
      
     while(ptr != NULL){
         cout << ptr->data <<" ";
        ptr= ptr->next;    
      }
   }

   Node* insertatfront(Node* head,int new_data){
      Node* new_node= new Node();//struct Node* new_node=(struct Node*)malloc(sizeof(struct Node))
      new_node->next=head;//same
      new_node->data=new_data;//same
      
      return new_node;//here we are returning new_node not head because new_node is the new head; 
   }

   Node* insertatindex(Node* head,int new_data,int index){
      Node* new_node= new Node();
      Node* ptr=head;//dummy pointer

      int count=0;
      while(count!=index-1){   
         count++;
         ptr=ptr->next;
      }
          new_node->next=ptr->next;
          ptr->next=new_node;
      new_node->data=new_data;

      return head;//we have to return head of linked list to get the entire linked list in every case.
   }

   
   Node* insertatend(Node* head,int new_data){
      Node* new_node= new Node();
      Node* ptr=head;

      while(ptr->next!=NULL){
         ptr=ptr->next;

      }
       new_node->next=ptr->next;
          ptr->next=new_node;
      new_node->data=new_data;

      return head;
   }

    Node* insertaftergiven_node(Node* head,Node* prevNode,int new_data){
      Node* new_node= new Node();
      new_node->data=new_data;
      new_node->next= prevNode->next;
      prevNode->next=new_node;

      return head;
    }

    int cycle(Node* head){
       Node *slw=head, *fst=head;
       while(slw!=NULL && fst->next!=NULL && fst->next!=NULL){
          slw=slw->next;
          fst=fst->next->next;
          if(slw==fst)
          return 1;

       }
       return 0;
    }

 int main()
 {

    Node* head= NULL;//struct Node* head=NULL;
    Node* second= NULL;
    Node* third= NULL;

    head= new Node();// head=(struct Node*)malloc(sizeof(struct Node));
    second =new Node();//second=(struct Node*)malloc((struct Node))
    third= new Node();

    head->data=1;//same in c
    head->next=second;
    
    second->data=2;
    second->next=third;
    
    third->data=3;
    third->next= NULL;    
    
    print(head);
    cout<<"\n new list\n";
    head = insertatfront(head,5);
    print(head);

    cout<<"\n new list\n";
    head = insertatindex(head,6,2);
    print(head);

       cout<<"\n new list\n";
    head = insertatend(head,8);
    print(head);

      cout<<"\n new list\n";
    head = insertaftergiven_node(head,second,8);
    print(head);

     
    
    cout<<"\n cycle is found\n";
    cout<<cycle(head);
    

    return 0;
 }