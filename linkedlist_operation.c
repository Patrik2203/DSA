#include<stdio.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *next;
};

void printlist(struct node *head)
{
    printf("H->");
    while(head)
    {
        printf("%d->",head->val);
        head=head->next;
    }
    printf(".....");
}

void insertfront(struct node **head,int value)
{
    struct node * newnode=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Out of memory");
    }
    newnode->val=value;
    newnode->next=*head;
    *head=newnode;
}

void insertend(struct node **head,int value)
{
    struct node * newnode=NULL;
    struct node * last=NULL;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("Out of memeory");
    }
    newnode->val=value;
    newnode->next=NULL;
    if(*head==NULL)
    {
        *head=newnode;
        return;
    }
    last=*head;
    while (last->next)
        last = last->next;
        last->next=newnode;
}

int main()
{
    int count=0;
    int val;
    int i;
    struct node* head=NULL;
    printf("Enter the number of elements : ");
    scanf("%d",&count);
    for(i=0;i<count;i++)
    {
        printf("Enter the %dth element : ",i);
        scanf("%d",&val);
        insertfront(&head,val);
    }

    printf("starting list : ");
    printlist(head);
    printf("\nEnter front ele : ");
    scanf("%d",&val);
    insertfront(&head,val);
    printf("Ele after inserting at begining : ");
    printlist(head);
    printf("\nEnter the last ele : ");
    scanf("%d",&val);
    insertend(&head,val);
    printf("Ele after inserting at end : ");
    printlist(head);

    printf("%s", "\U0001f631");
    printf("%s", "\U0001f631");
    printf("%s", "\U0001f631");
   
}