#include <stdio.h>
#include <stdlib.h>

typedef  struct node
{
    int data;
    struct node * next;
}node;
node * createnode(int value)
{
    node *newnode=(node *) malloc(sizeof(node));
    if (newnode== NULL)
    {
        printf(" chua duoc cap phat ");
        return NULL;
    }
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}
void print_lit(node * head)
{
    node*current=head;
    while (current!= NULL)
    {
        printf("%d->",current->data);
        current=current->next;
    }
    printf("NULL\n");
}
node * append(node *head,int value)
{
    node *newnode=createnode(value);
    if (head==NULL)
    {

        return newnode;
    }
    node*curent=head;
    while ( curent->next!=NULL)
    {
curent=curent->next;
    }
    curent->next=newnode;
    return head;
}
int main(void)
{
    node *head=createnode(10);
    head->next=createnode(20);
    head->next->next=createnode(30);
    head->next->next->next=createnode(40);
    head->next->next->next->next=createnode(50);
printf(head);

    int number;
    printf("Nhập số nguyên dương để thêm vào cuối danh sách: ");
    scanf("%d", &number);
    if (number>0)
    {
        head=append(head,number);
        print_lit(head);
    }else
    {
        printf("khong hop le")
    }
    return 0;
}