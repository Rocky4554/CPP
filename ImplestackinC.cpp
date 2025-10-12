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


int main(){
    
    struct Stack* s=(struct Stack*)malloc(sizeof(struct Stack));// using stack as a pointer so that we could easily use it in functions(operations) by calling it.
    s->size=80;
    s->top=-1;
    s->ar=(int*)malloc(s->size *sizeof(int));//allocating memory dynamically.

    if(isEmpty(s)){
        printf("Stack is empty");
    }
    else{
        printf("Not empty");
    }


    return 0;
}