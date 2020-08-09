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
void insert(int k,int m)
{ struct node *new;
  new=(struct node*)malloc(sizeof(struct node));
  new->data=k;
  new->next=NULL;
  new->prev=NULL;
  struct node *ptr=head;
  int c=0;
  while(c<m-1)
  { ptr=ptr->next;
    ++c;
  }
  new->next=ptr->next;
  ptr->next->prev=new;
  ptr->next=new;
  new->prev=ptr;
  ptr=new;
  
}
int main()
{
  int n,i,k,e,m;
  printf("enter the number of nodes\n");
  scanf("%d",&n);
  for(i=0;i<n;++i)
  { printf("enter the data\n");
    scanf("%d",&k);
    create(k);
  }
  display();
  printf("enter the element and the position\n");
  scanf("%d%d",&e,&m);
  insert(e,m);
  printf("\n");
  display();
  return 0;
} 
  
