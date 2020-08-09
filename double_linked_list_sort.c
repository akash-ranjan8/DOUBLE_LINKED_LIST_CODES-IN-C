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
void sort()
{ struct node *t1,*t2;
  int t;
  t1=head;
  t2=t1->next;
  while(t1!=NULL)
  { for(;t2!=NULL;t2=t2->next)
    { if(t2->data>t1->data)
      { t=t1->data;
        t1->data=t2->data;
        t2->data=t;
       }
    }
   t1=t1->next;
  }
}
int main()
{ int n,i,k;
  printf("enter the number of nodes\n");
  scanf("%d",&n);
  for(i=0;i<n;++i)
  { printf("enter the data\n");
    scanf("%d",&k);
    create(k);
  }
  display();
  sort();
  printf("\n");
  display();
  return 0;
}
