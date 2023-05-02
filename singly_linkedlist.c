#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

int calculateNode(struct node *head);
void printLinkedlist(struct node *head);
void add_at_beg(struct node **head_ref, int data);
void add_at_End(struct node *head, int data);
void add_at_pos(struct node *head, int data, int pos);
void del_first(struct node **head_ref);
void del_last(struct node **head);
void del_anypos(struct node **head_ref, int pos);
void del_linkedlist(struct node **head_ref);

int main(){
    struct node *head = NULL;
    struct node *current = malloc(sizeof(struct node)); 
    head = malloc(sizeof(struct node));

    head->data=10;
    head->link = NULL;

    add_at_beg(&head, 1);
    add_at_End(head, 20);
    add_at_pos(head, 15,3);// head, data, pos
    add_at_pos(head, 5, 2);
    add_at_End(head, 30);

    del_anypos(&head, 1);
    del_anypos(&head, 5);
    del_first(&head);
    del_last(&head);
    del_linkedlist(&head);

    int totalnodes = calculateNode(head); 
    printf("Number of nodes in the linkedlist is: %d\n", totalnodes);
    printLinkedlist(head);
}

void del_linkedlist(struct node **head_ref){
    if(*head_ref==NULL){
        printf("Linkedlist is empty!!");
    }
    else{
        struct node *temp;
        temp = *head_ref;
        while(temp){
            temp = temp->link;
            free(*head_ref);
            *head_ref = temp;
        }
        printf("The whole linkedlist is deleted successfully.");
    }
}

void del_anypos(struct node **head_ref, int pos){
    struct node *current = NULL, *prev_node = NULL;
    if(*head_ref == NULL){
        printf("Linked is empty to delete something!!");
    }
    else if(pos == 1){
        current = *head_ref;
        *head_ref = (*head_ref)->link;
        free(current);
        current = NULL;
    }
    else{
        prev_node = *head_ref;
        pos--;
        while(pos != 1){
            prev_node = prev_node->link;
            pos--;
        }
        current = prev_node->link;
        prev_node->link = current->link;
        free(current);
        current = NULL;
    }
}

void del_last(struct node **head){
    if(*head == NULL){
        printf("The linkedlist is empty!!\n");
    }
    else if((*head)->link == NULL){
        free(*head);
        *head = NULL;
    }
    else{
        struct node* temp, *temp2;  
        temp = *head;
        while(temp->link->link){
            temp = temp->link;
        }
        temp2 = temp->link;
        temp->link = NULL;
        free(temp2);
        temp2 = NULL;
    }
}

void del_first(struct node **head_ref){
    if(*head_ref == NULL){
        printf("Linkedlist is empty");
    }
    else{
        struct node *temp = NULL;
        temp = *head_ref;
        *head_ref = (*head_ref)->link;
        free(temp);
        temp = NULL;
    }
}

void add_at_pos(struct node *head, int data, int pos){
    struct node *ptr, *ptr2;
    ptr = head;
    ptr2 = malloc(sizeof(struct node));
    ptr2->data = data;
    ptr2->link = NULL;

    pos--;
    while(pos != 1){
        ptr = ptr->link;
        pos--;
    }
    ptr2->link = ptr->link;
    ptr->link = ptr2;
}

void add_at_End(struct node *head, int data){
    struct node *temp, *ptr; 
    ptr = head;
    temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    while(ptr->link){
        ptr = ptr->link;
    }
    ptr->link = temp;
}

void add_at_beg(struct node **head_ref, int data){
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->link = NULL;

    ptr->link = *head_ref;
    *head_ref = ptr;
}

void printLinkedlist(struct node *head){
    if(head == NULL){
        printf("The linkedlist is empty!!");
    }
    else{
        struct node *ptr=NULL;
        ptr = head;
        while(ptr != NULL){
            printf("%d, ",ptr->data);
            ptr = ptr->link;
        }
    }
}

int calculateNode(struct node *head){
    if(head == NULL){
        return 0;
    }
    int count =0;
    struct node *ptr = NULL;
    ptr = head;
    while(head){
        count++;
        head = head->link;
    }
    return count;
}