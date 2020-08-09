#include<stdio.h>
#include<stdlib.h>
struct node 
{ int data;
  struct node *next;
  struct node *prev;
};
struct node *head=NULL;
void create(int d)
{ struct node *curr,*t;
  curr=(struct node*)malloc(sizeof(struct node));
  curr->data=d;
  curr->next=NULL;
  curr->prev=NULL;
  if(head==NULL)
  { head=curr;
  }
  else
  { t=head;
    while(t->next!=NULL)
    { t=t->next;
    }
    t->next=curr;
    curr->prev=t;
  }
}
void display()
{ struct node *ptr;
  ptr=head;
  while(ptr!=NULL)
  { printf("%d\t",ptr->data);
    ptr=ptr->next;
  }
}
void reverse()
{ struct node *t1,*temp;
  t1=head;
  temp=NULL;
  while(t1!=NULL)
  { 
    temp=t1->prev;
    t1->prev=t1->next;
    t1->next=temp;
    t1=t1->prev;
   }
   if(temp!=NULL)
   {head=temp->prev;
   }

}

int main()
{
  int n,i,k;
  printf("enter the number of nodes\n");
  scanf("%d",&n);
  for(i=0;i<n;++i)
  { printf("enter the data\n");
    scanf("%d",&k);
    create(k);
  }
  display();
  reverse();
  printf("\n");
  display();
  return 0;
} 

