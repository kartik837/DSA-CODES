//here the random numbers generated are between 0 to 9 only....
#include<stdio.h>
#include<time.h>
struct node
{
    int data;
    struct node *next;
};
 FILE* fp3,*fp4;
struct node * head,* temp,* temp1,*temp2,* newnode;



struct node *Insert_node_beg(struct node *newnode)
{
    if(head==NULL)
    {
        head=newnode;
        head->next=NULL;

    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
    return(head);
}

void sort(struct node *head , int n)
{

    struct node *temp;
    struct node *temp1;
    int i,j;
if(head==NULL)
    {
        printf("linked list is empty\n");

    }
    else
    {
        if(head->next==head)
        {
            return(head);
        }


      else
        {


            temp1=(struct node * )malloc(sizeof(struct node));

    for(i=0;i<n;i++)
    {
         temp=head;
        for(j=0;j<n-i-1;j++)
         {
            if(temp->data>temp->next->data)
            {
                temp1->data=temp->data;
                temp->data=temp->next->data;
                temp->next->data=temp1->data;

            }
            temp=temp->next;

         }
        }

       }
    }
}



void display(struct node *head)
{
    if(head==NULL)
    {
        printf("Singly linked list is empty\n");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {

            fprintf(fp4,"%d->",temp->data);
            temp=temp->next;

        }

    }
}

int count_nodes(struct node * head)
{
    int count=0;
if(head==NULL)
    {
         printf("Number of nodes is zero\n");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
        return(count);
    }
}

int main()
{
    int i,j;
    int n;
     int c;

     time_t t;
     srand((unsigned) time(&t));


     fp3=fopen("anna.txt","w");
     fp4=fopen("heyy.txt","w");

     printf("enter the number of numbers you want to generate : \n");
     scanf("%d",&n);

     clock_t st,et,st2,et2;
     st=clock();

    for(i=0;i<n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=rand()%10;
        head=Insert_node_beg(newnode);
        fprintf(fp3,"%d\n",head->data);
       // c=count_nodes(head);

    }
    et=clock();

    double time_taken1 = (double)(et-st);

    printf("%lf\n",time_taken1);

      st2=clock();

         sort(head,n);

          et2=clock();

    double time_taken = (double)(et2-st2);

    printf("%lf\n",time_taken);

         display(head);

}
