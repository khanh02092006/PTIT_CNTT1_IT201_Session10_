#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct  node* next;
}node;
node *ceatenode(int value)
{
node *newnode=(node*) malloc(sizeof(node));
    if (newnode==NULL)
    {
        printf(" chua duoc cap phat");
        return NULL;
    }
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}
void print_lit(node * head)
{
    node * current=head;
    while (current !=NULL)
    {
        printf("%d->",current->data);
        current=current->next;
    }
    printf("NULL\n");
}
node* xoa_trunglap(node* head,int value)
{
    while (head!= NULL,head->data==value)
    {
        node *temp=head;
        head=head->next;
        free(temp);
    }
    if (head==NULL ) return NULL;
    node * current=head;
    while (current->next!=NULL)
    {
        if (current->next->data== value)
        {
            node *tmep=current->next;
            current->next=tmep->next;
            free(tmep);
        } else
        {
            current=current->next;
        }
    }
    return  head;
}
int main(void)
{
    node* head = ceatenode(10);
    head->next = ceatenode(20);
    head->next->next = ceatenode(30);
    head->next->next->next = ceatenode(40);
    head->next->next->next->next = ceatenode(50);
print_lit(head);
    int valu;
    printf(" nhap xem gia trung");
    scanf("%d",&valu);
    head=xoa_trunglap(head,valu);
    print_lit(head);
    return 0;
}