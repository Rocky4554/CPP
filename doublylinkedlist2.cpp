#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

void print(struct Node* ptr){
    struct Node* last;
    while(ptr!=NULL){
        last=ptr;
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n back list\n");
    while(last!=NULL){
        printf("%d ",last->data);
        last=last->prev;
    }
}

void printback(struct Node* p){
    while(p!=NULL){
        printf("%d",p->data);
        p->prev;
    }
}


int main(){

struct Node* head = (struct Node*)malloc(sizeof(struct Node));
struct Node* second = (struct Node*)malloc(sizeof(struct Node));
struct Node* third = (struct Node*)malloc(sizeof(struct Node));

head->data=1;
head->next=second;


second->data=2;
second->next=third;

third->data=3;
third->next=NULL;

print(head);
// print(head);
    return 0;
}