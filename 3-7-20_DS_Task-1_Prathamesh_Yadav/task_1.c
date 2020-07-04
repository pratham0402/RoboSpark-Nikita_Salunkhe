#include<stdio.h>
#include<stdlib.h>

typedef struct Queue
{
    int arr[10];
    int front,rear;
}Queue;


struct Student
{
    int roll;
    char name[20];
};


void initialize(Queue* q){
    q->front=0;
    q->rear=0;

}

void enqueue(Queue* q,int x){
    q->arr[q->rear++]= x;

}

int dequeue(Queue* q){
    return q->arr[q->front++];
}

int isEmpty(Queue* q){
    return q->front==q->rear;
}

void print(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }

    printf("front ");
    for(int i=q->front;i<q->rear;i++){
        printf("%d ",q->arr[i]);
    }
    printf("Rear\n");
}


int main(){
    Queue* q1=(Queue*)malloc(sizeof(Queue));
    initialize(q1);
    
    printf("\nEnter number of students: ");
    int n;
    scanf("%d",&n);
    struct Student s[n];
    
    printf("\nEnter details:\n ");
    for (int i=0; i<n; i++){
        scanf("%d", &s[i].roll);
        fflush(stdin);
        scanf("%s",s[i].name);
        //get();
    }
    
    for (int i=0; i<n; i++){
        if (s[i].roll%2 == 0){
            enqueue(q1, s[i].roll);
        }
    }

    print(q1);
}