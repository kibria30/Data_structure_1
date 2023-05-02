#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int cirQue_arr[MAX];
int front =-1, rear = -1;

void enqueue(int data){
    if(rear == -1 && front == -1){
        rear = front = 0;
        cirQue_arr[rear] = data;
    }else if( (rear+1)% MAX == front){
        printf("Queue is overflow!\n");
    }else{
        rear = (rear+1)%MAX;
        cirQue_arr[rear] = data;
    }
}

int dequeue(){
    int value;
    if(front == -1 && rear == -1){
        printf("Queue is underflow!\n");
        exit(1);
    }else if(front == rear){
        value = cirQue_arr[front];
        front = rear = -1;
        return value;
    }else{
        value = cirQue_arr[front];
        front = (front + 1)%MAX;
        return value;
    }
}

void display(){
    if(front == -1 && rear==-1){
        printf("Queue is empty!!\n");
    }
    int i;
    for(i = front; i!=rear; i = (i+1)%MAX){
        printf("%d, ", cirQue_arr[i]);
    }
    printf("%d\n", cirQue_arr[i]);
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    dequeue();
    dequeue();
    display();
    enqueue(50);
    enqueue(60);
    dequeue();
    
    display();
}