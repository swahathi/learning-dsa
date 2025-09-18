#include<stdio.h>
#define SIZE 5
int stack[SIZE];
int top=-1;
int el;
int ch;
void push(int);
void pop();
int isEmpty();
int isFull();
void traverse();
void peek();
void main(){
while(1){

printf("1.Push");
printf("1.Pop");
printf("3.Peek");
printf("4.Traverse");
int ch;
printf("enter choice: ");
scanf("%d",&ch);

switch(ch){
    case '1':printf("Enter element:");
    scanf("%d",&el);
    push(el);

    case'2':pop();
    case'3':peek();
    case'4':traverse();
    case'5':exit(0);
    default:printf("Invalid operation");
}}}
void push(int el){
        if(isFull){
            printf("Stack is full");
        }
        else{
            top++;
            stack[top]=el;
        }
}
int isFull(){
    if(top==SIZE-1){
        return 1;
    }
    else{
        return 0;
    }
}
void pop(){
    if(isEmpty){
        printf("Stack is empty");
    }
    else{
        int popped=stack[top];
        printf("returning %d from stack",popped);
        top--;

    }
}
int isEmpty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
void peek(){
    printf("%d is returned",stack[top]);
}
void traverse(){
    for(int i=0;i<top-1;i++){
        int t=stack[i];
        printf("%d\t",t);
    }
}