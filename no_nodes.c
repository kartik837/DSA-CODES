#include<stdio.h>
struct node
{
    int num;
    struct node *next;
};
typedef struct node *Node;
Node insertend(Node head);
main()
{
    Node head=NULL;
    int ch;
    while(1)
    {
        printf("Enter\n1 to insert node\n2 to count nodes\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:head=insertend(head);
            break;
            case 2:count_node(head);
            break;
        }
    }
}
void count_node(Node head)
{
    int count=0;
    Node cur=head;
    while(cur)
    {
        count++;
        cur=cur->next;
    }
    printf("%d is the number of nodes\n",count);
}
Node insertend(Node head)
{
    Node newn=NULL,cur=head;
    int a;
    newn=(Node)malloc(sizeof(struct node));
    printf("Enter the number to be stored in the node\n");
    scanf("%d",&a);
    newn->num=a;
    newn->next=NULL;
    if(head==NULL)
    {
       return newn;
    }
        while(cur->next!=NULL)
            cur=cur->next;
        cur->next=newn;
        return head;

}
//iterative logic 2
