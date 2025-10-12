#include<stdio.h>
#include<stdlib.h>//library for using malloc.
#include<string.h>

struct Stack{

    int size;
    int top;
    char* ar;// taking chracter array here.
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
        int val=ptr->ar[ptr->top];//like val=ar[top].
        ptr->top--;
        return val;
    }
}

int top(struct Stack* ptr){
    return ptr->ar[ptr->top];
}

void print(struct Stack* ptr){
    int i;
    printf("Our new stack is :\n");
    for(int i=ptr->ar[ptr->top];i>0;i--){
        printf(" %d\n",i);
    }
}

// int precedence(char ch){
//     switch(ch){
//         case '+':
//         case '-':
//             return 1;
//         case '*':
//         case '/':
//             return 2;
//         case '^':
//             return 3;
//     }
//     return -1;
// }
int precedence(char ch){
    
        if(ch=='^'){
            return 3;
        }
        else if(ch=='*'|| ch=='/'){
            return 2;
        }
        else if(ch=='+'|| ch=='-'){
            return 1;
        }
        else{
            return -1;
        }
}

int isoperator(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
        return 1;
    }
    else{
        return 0;
    }
}
// int alpha(char ch){
//     if((ch>='a'&& ch<='z')|| (ch>='A' && ch<='Z')){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }


char* conversion(char* infix){
    struct Stack* st =(struct Stack*)malloc(sizeof(struct Stack));
    st->top=-1;
    st->size=100;
    st->ar=(char*)malloc(st->size *sizeof(char));
    
    char* postfix=(char*)malloc((strlen(infix)+1)*sizeof(char));//another character array for storing our ans.
    int i=0,j=0;
    while(infix[i]!='\0'){// this means our loop will run till our infix become empty.
        if(!isoperator(infix[i])){
            postfix[j]=infix[i];
            i++;j++;
        }
        else if(infix[i]=='('){
            push(st,infix[i]);
            i++;
        }
        else if(infix[i]==')')
        {
            while(!isEmpty(st) && top(st)!='('){
            postfix[j]=pop(st);
            j++;
            }
            if(!isEmpty(st)){
                pop(st);
            }
        
        }
        else{
            while(!isEmpty(st) && (precedence(top(st))>=precedence(infix[i]))){
                postfix[j] = pop(st);
                j++;
            }
            push(st,infix[i]);
            i++;
        }
    }
        while(!isEmpty(st)){
            postfix[j]=pop(st);
            j++;
        }
        postfix[j]='\0';
        return postfix;
}        
 
int main(){
    
    struct Stack* s=(struct Stack*)malloc(sizeof(struct Stack));// using stack as a pointer so that we could easily use it in functions(operations) by calling it.
    s->size=4;//stack limit;
    s->top=-1;
    s->ar=(char*)malloc(s->size *sizeof(char));//allocating memory dynamically.

   printf("Stack is empty: %d\n",isEmpty(s));
   printf("Stack is full: %d\n",isFull(s));
    push(s,1);
     push(s,2);
      push(s,3);
       push(s,4);
    print(s);
    printf("Popped %d from stack\n", pop(s));
    print(s);
    printf("top of stack is %d\n",top(s));
    print(s);

    char* infix="(a*b)+c";
    printf("postfix is %s",conversion(infix));

    return 0;
}