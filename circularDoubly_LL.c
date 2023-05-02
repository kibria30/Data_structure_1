#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

void printDoubly(struct node *tail){
    struct node *ptr = tail->next;
    while(ptr != tail) {
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d\n", ptr->data);
}

struct node* InsertAtBig(struct node *tail, int data){
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = tail->next;
    new->next->prev = new;
    tail->next = new;
    new->prev = tail;
    return tail;
} 

struct node* InsertAtEnd(struct node *tail, int data){
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = tail->next;
    new->next->prev = new;
    tail->next = new;
    new->prev = tail;
    tail = new;
    return tail;
}

struct node* InsertAtMiddle(struct node *tail, int data, int position){
    struct node *new = malloc(sizeof(struct node));
    struct node *ptr = tail->next;
    struct node *temp = NULL;
    new->data = data;
    position--;
    while(position > 1){
        ptr = ptr->next;
        position--;
    }
    temp = ptr->next;
    ptr->next = new;
    new->prev = ptr;
    new->next = temp;
    temp->prev = new;
    return tail;
}

struct node* Delet_node(struct node *tail, int position){
    struct node *ptr = tail;
    struct node *temp = NULL;
    while(position>1){
        ptr = ptr->next;
        position--;
    }
    if(ptr->next == tail){
        tail = ptr;
    }
    temp = ptr->next->next;
    ptr->next = temp;
    temp->prev = ptr;
    return tail;
}

int main(){
    struct node *tail = malloc(sizeof(struct node));
    tail->prev = tail;
    tail->data = 20;
    tail->next = tail;
    printDoubly(tail);
    tail = InsertAtBig(tail, 10);
    printDoubly(tail);
    tail = InsertAtBig(tail, 5);
    tail = InsertAtBig(tail, 1);
    printDoubly(tail);
    tail = InsertAtEnd(tail, 30);
    printDoubly(tail);
    tail = InsertAtEnd(tail, 40);
    printDoubly(tail);
    tail = InsertAtMiddle(tail, 15, 4);
    printDoubly(tail);
    tail = InsertAtMiddle(tail, 25, 6);
    printDoubly(tail);
    tail = Delet_node(tail, 1);
    printDoubly(tail);
    tail = Delet_node(tail, 1);
    printDoubly(tail);
    tail = Delet_node(tail, 6);
    printDoubly(tail);
    tail = Delet_node(tail, 3);
    printDoubly(tail);
}