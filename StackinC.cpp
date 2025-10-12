#include<stdio.h>
#include<stdlib.h>//library for using malloc .

struct Stack{

    int size;
    int top;
    int* ar;
};

int isEmpty(struct Stack* ptr){
    if(ptr->top == -1){
        return 1;
        }
        else{//not necessary to give.
        return 0;
        }
}

int isFull(struct Stack* ptr){
    if(ptr->top==ptr->size-1){
        return 1;
        }
        else{//not necessary to give.
            return 0;
        }
}

void push(struct Stack* ptr,int val ){
    if(isFull(ptr)){
        printf("Stack Overflow\n");
    }
    else{
        ptr->top++;
        ptr->ar[ptr->top]=val;//like ar[i]=val;
    }
}

int pop(struct Stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow\n");
        return -1;
    }
    else{
        int val=ptr->ar[ptr->top];
        ptr->top--;
        return val;
    }
}

void print(struct Stack* ptr){
    int i;
    printf("Our new stack is :\n");
    for(int i=ptr->ar[ptr->top];i>0;i--){
        printf(" %d\n",i);
    }
}


int main(){
    
    struct Stack* s=(struct Stack*)malloc(sizeof(struct Stack));// using stack as a pointer so that we could easily use it in functions(operations) by calling it.
    s->size=4;//stack limit;
    s->top=-1;
    s->ar=(int*)malloc(s->size *sizeof(int));//allocating memory dynamically.

   printf("Stack is empty: %d\n",isEmpty(s));
   printf("Stack is full: %d\n",isFull(s));
    push(s,1);
     push(s,2);
      push(s,3);
       push(s,4);
    print(s);
    printf("Popped %d from stack\n", pop(s));
    print(s);

    return 0;
}