#include<stdio.h>
#include<stdlib.h>
struct node
{ int data;
  struct node *next;
  struct node *prev;
};
struct node *head=NULL;
void create(int d)
{ struct node *new;
  new=(struct node*)malloc(sizeof(struct node));
  new->data=d;
  new->next=NULL;
  new->prev=NULL;
  if(head==NULL)
  { head=new;
  }
  else
  { struct node *t=head;
    while(t->next!=NULL)
    { t=t->next;
    }
    t->next=new;
    new->prev=t;
  }
}
void display()
{ struct node *ptr=head;
  while(ptr!=NULL)
  { printf("%d\t",ptr->data);
    ptr=ptr->next;
  }
}
void delete(int k)
{ struct node *ptr=head;
  while(ptr->data!=k)
  { ptr=ptr->next;
  }
  struct node *t1,*t2;
  t1=ptr->next;
  t2=ptr->prev;
  t1->prev=t2;
  t2->next=t1;
  free(ptr);
}
int main()
{
  int n,i,k,e;
  printf("enter the number of nodes\n");
  scanf("%d",&n);
  for(i=0;i<n;++i)
  { printf("enter the data\n");
    scanf("%d",&k);
    create(k);
  }
  display();
  printf("enter the element  to be deleted\n");
  scanf("%d",&e);
  delete(e);
  printf("\n");
  display();
  return 0;
} 
  
