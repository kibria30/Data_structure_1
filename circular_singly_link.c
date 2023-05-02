#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void printLinklist(struct node *tail){
    if(tail == NULL){
        printf("Linklist is empty!");
        return;
    }
    struct node *head = tail->next;
    do{// while loop use kora jay na karon fist iteration ei condition true hoy tai loop exit hoye jay
        printf("%d, ", head->data);
        head = head->next;
    }while(head != tail->next);
}

struct node* creat_first(int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
}

void add_at_beg(struct node *tail, int data){
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = tail->next;
    tail->next = new;
}

struct node* add_at_last(struct node *tail, int data){
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = tail->next;
    tail->next = new;
    tail = new;
    return tail;
}

struct node* add_at_middle(struct node *tail, int data, int pos){
    struct node *ptr = tail->next;
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    pos--;
    while(pos > 1){
        ptr = ptr->next;
        pos--;
    }
    if(ptr == tail){
        tail = add_at_last(tail, data);
    }else{
        new->next = ptr->next;
        ptr->next = new;
    }
    return tail;
}

void del_first(struct node *tail){
    if(tail == NULL){
        printf("Linklist is empty!");
        return;
    }
    struct node *temp = tail->next;
    tail->next = temp->next;
    free(temp);
    temp = NULL;
    return;
}

struct node* del_last(struct node *tail){
    if(tail == NULL ){
        printf("Linked list is empty!");
        return tail;
    }
    if(tail->next == tail){
        printf("Last node deleted!\n");
        free(tail);
        tail = NULL;
        return tail;
    }
    struct node *temp = tail;
    while(tail->next != temp){
        tail = tail->next;
    }
    tail->next = temp->next;
    free(temp);
    temp = NULL;
    return tail;
}

struct node* del_any_node(struct node *tail, int pos){
    struct node *ptr = tail;
    while(pos>1){
        ptr = ptr->next;
        pos--;
    }
    struct node *temp = ptr->next;
    ptr->next = temp->next;
    if(tail == temp){
        tail = ptr;
    }
    free(temp);
    temp = NULL;
    return tail;
}

int main(){
    struct node *tail = NULL;
    int data = 20;
    tail = creat_first(data);
    add_at_beg(tail, 10);
    add_at_beg(tail, 5);
    tail = add_at_last(tail, 30);
    tail = add_at_last(tail, 40);
    tail = add_at_middle(tail, 25, 4);
    tail = add_at_middle(tail, 15, 3);
    tail = add_at_middle(tail, 35, 8); 
    del_first(tail);
    tail = del_last(tail);
    del_any_node(tail,4);
    del_any_node(tail, 2);
    del_any_node(tail, 1);
    tail = del_any_node(tail, 3);
    tail = del_any_node(tail, 2);
    //tail = del_any_node(tail, 1);    // only node can't be deleted with this function
    tail = del_last(tail);
    printLinklist(tail);
}