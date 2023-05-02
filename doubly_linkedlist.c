#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *prev;
    int data;
    struct node *next;
};

void printLinkedlist(struct node *head){
    if(head==NULL){
        printf("Linkedlist is empty!");
    }
    else{
        while(head){
            printf("%d, ", head->data);
            head = head->next;
        }
    }
}

void add_at_beg(struct node **head_ref, int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data= data;
    temp->next = NULL;

    (*head_ref)->prev = temp;
    temp->next = *head_ref;
    *head_ref = temp;
}

void add_at_end(struct node *head, int data){
    if(head==NULL){
        printf("Linkedlist is empty");
    }
    else{
        struct node *temp = malloc(sizeof(struct node));
        temp->prev = NULL;
        temp->data = data;
        temp->next = NULL;

        while(head->next){
            head = head->next;
        }
        head->next = temp;
        temp->prev = head;
    }
}

void add_at_pos(struct node *head, int data, int pos){
    if(head == NULL){
        printf("Linkedlist is empty!");
    }
    else{
        struct node *temp = malloc(sizeof(struct node));
        struct node *temp2 = malloc(sizeof(struct node));
        temp->prev = NULL;
        temp->data = data;
        temp->next = NULL;
        pos--;
        while(pos != 1){
            head = head->next;
            pos--;
        }
        temp2 = head->next;
        head->next = temp;
        temp->prev = head;
        temp->next = temp2;
        temp2->prev = temp;
    }
}

void del_beg(struct node **head_ref){
    if(*head_ref==NULL){
        printf("Linkedlist is already empty!");
    }
    else{
        struct node *temp = *head_ref;
        *head_ref = (*head_ref)->next;
        free(temp);
        temp = NULL;
    }
}

void del_last(struct node *head){
    if(head == NULL){
        printf("Linkedlist is already empty");
    }
    else if(head->next == NULL){
        free(head);
        head = NULL;
    }
    else{
        struct node *temp;
        while(head->next->next){
            head = head->next;
        }
        temp = head->next;
        head->next = NULL;
        free(temp);
        temp = NULL;
    }
}

void del_pos(struct node *head, int pos){
    struct node *temp; //*temp2
    pos--;
    while(pos != 1){
        head = head->next;
        pos--;
    }
    temp = head->next; // without extra temp2 node as doubly linkedlist
    head->next = temp->next;
    temp->next->prev = head;
    // temp2 = temp->next;
    // head->next = temp2;
    // temp2->prev = head;
    free(temp);
    temp = NULL;
}

void reverse_linkedlist(struct node **head_ref){
    struct node *temp= NULL, *temp2;
    while(*head_ref){
        temp2 = (*head_ref)->next;
        (*head_ref)->next = temp;
        (*head_ref)->prev = temp2;
        temp = *head_ref;
        *head_ref = temp2;
    }
    *head_ref = temp;
}

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->prev = NULL;
    head->data = 10;
    head->next = NULL;
    add_at_beg(&head, 5);
    add_at_beg(&head, 0);

    add_at_end(head, 20);
    add_at_end(head, 30);

    add_at_pos(head, 15,4);//head, data, pos
    add_at_pos(head, 25,6);

    del_beg(&head);
    del_beg(&head);
    
    del_last(head);
    del_last(head);

    del_pos(head, 4);

    reverse_linkedlist(&head);


    printLinkedlist(head);
}