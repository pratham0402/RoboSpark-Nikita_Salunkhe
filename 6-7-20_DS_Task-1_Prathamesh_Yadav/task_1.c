#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

// adding at front
void addAtFront(int d, struct node *head){
    struct node *new_head = (struct node *)malloc(sizeof(struct node));
    new_head->data = head->data;
    new_head->next = head->next;
    head->data = d;
    head->next = new_head;
}

// adding at end
void addAtRear(int d, struct node *head){
    struct node *temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    struct node *last = (struct node *)malloc(sizeof(struct node));
    last->data = d;
    last->next = NULL;
    temp->next = last;
    
}

// adding before particular data
void addBefore(int n, int d, struct node *head){
    struct node *temp = head;
    while (temp->next->data != n){
        temp = temp->next;
    }
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = d;
    new->next = temp->next;
    temp->next = new_head;
}

// delete front element
void deleteFront(struct node *head){
   struct node *temp;
   temp = head;
   head = head->next;
   free(temp);    
}

// delete rear element
void deleteRear(struct node *head){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *prev = (struct node *)malloc(sizeof(struct node));
    struct node *curr = (struct node *)malloc(sizeof(struct node));
    temp = head; 
    while ((temp->next)->next != NULL){
        temp = temp->next;
    }
    prev = temp;
    curr = temp->next;
    prev->next = NULL;
    free(curr); 
}

// delete with value
void deleteValue(int n, struct node *head){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *prev = (struct node *)malloc(sizeof(struct node));
    struct node *curr = (struct node *)malloc(sizeof(struct node));
    temp = head;
    while (temp->next->data != n){
        temp = temp->next;
    }
    prev = temp;
    curr = temp->next;
    prev->next = curr->next;
    curr->next = NULL;
    free(curr);
}

int main()
{   
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 45;
    head->next = NULL;


    struct node *sec_link = (struct node *)malloc(sizeof(struct node));
    sec_link->data = 85;
    sec_link->next = NULL;
    head -> next = sec_link;

    struct node *third_link = (struct node *)malloc(sizeof(struct node));
    third_link->data = 96;
    third_link->next = NULL;
    sec_link->next = third_link;

    struct node *fourth_link = (struct node *)malloc(sizeof(struct node));
    fourth_link->data = 200;
    fourth_link->next = NULL;
    third_link->next = fourth_link;

    addAtFront(40,head);
    addAtRear(87,head);
    addBefore(200,98,head);
    deleteRear(head);
    deleteValue(200,head);

    struct node *temp = head;
    while(temp->next!=NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d -> NULL ", temp->data);
 
}