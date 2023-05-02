#include<stdio.h>
#include<stdlib.h>
#define MAX 4

int stack_arr[MAX];
int top = -1;

void push(int data){
    if(top == MAX -1){
        printf("Stack overflow!\n");
        return;
    }
    top++;
    stack_arr[top] = data;
    printf("%d is added successfully to the stack.\n", data);
}

int pop(){
    if(top == -1){
        printf("Stack underflow!\n");
        exit(1); //abnormal termination ->when no need to return anything
    }   
    int value = stack_arr[top];
    top--;
    return value;
}

void printStack(){
    if(top == -1){
        printf("Stack underflow!");
    }
    for(int i=top; i>-1; i--){
        printf("%d, ", stack_arr[i]);
    }
    printf("\n");
}

int main(){
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    printStack();
    // printf("%d is poped successfully.\n", pop());
    // printf("%d is poped successfully.\n", pop());
    // printf("%d is poped successfully.\n", pop());
    // printf("%d is poped successfully.\n", pop());
    // printf("%d is poped successfully.\n", pop());
    printf("top = %d\n",top);

}