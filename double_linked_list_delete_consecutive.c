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
  { struct node *t1=head;
    while(t1->next!=NULL)
    { t1=t1->next;
    }
    t1->next=new;
    new->prev=t1;
  }
}
void display()
{ struct node *ptr=head;
  while(ptr!=NULL)
  { printf("%d\t",ptr->data);
    ptr=ptr->next;
  }
}
void delete_consecutive(int d)
{ struct node *t=head;
  while(t->data!=d)
  { t=t->next;
  }
  struct node *temp1=t->next;
  struct node *temp2=temp1->next;
  t->next=temp2->next;
  (temp2->next)->prev=t;
  free(temp1);
  free(temp2);
}
int main()
{ int n,e;
  printf("enter the no. of nodes\n");
  scanf("%d",&n);
  int i;
  printf("enter the values\n");
  for(i=0;i<n;++i)
  { scanf("%d",&e);
    create(e);
  }
  display();
  int k;
  printf("enter the value \n");
  scanf("%d",&k);
  delete_consecutive(k);
  display();
  return 0;
}
  
  
