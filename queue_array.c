#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue_arr[MAX];
int front =-1, rear = -1;

void enqueue(int data){
    if(rear == MAX -1){
        printf("Queue is overflow!\n");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue_arr[rear] = data;
    }
    else{
        rear++;
        queue_arr[rear] = data;
    }
}

int dequeue(){
    int value;
    if(front == -1 && rear == -1){
        printf("Queue is underflow!\n");
        exit(1);
    }
    else if(front == rear){
        value = queue_arr[front];
        front = rear = -1;
        return value;
    }
    else{
        value = queue_arr[front];
        front++;
        return value;
    }
}

void display(){
    if(front == -1 && rear == -1){
        printf("Queue is empty!\n");
    }
    else{
        for(int i=front; i<=rear; i++){
            printf("%d, ", queue_arr[i]);
        }
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    //display();
}