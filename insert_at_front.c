#include<stdio.h>
#include<stdlib.h>

struct mynode{
  int data;
  struct mynode *next;
};
typedef struct mynode LN;

void insert_at_front(LN **hptr,int d);
void show(LN *head);
int sum(LN *head);

int main(){
  LN *head;
  head = NULL;
  LN **hhead;
  hhead = &head;
  printf("enter value\n");
  int i=1;
  int data;
  do{
    printf("data(%d)=",i++);
    scanf(" %d",&data);
    if(data >0)
      insert_at_front(hhead,data);
  }while(data >0);

  show(head);
  printf("sum = %d",sum(head));
  return 0;

}

void insert_at_front(LN **hptr , int d){
    //step1 create node
    LN* new_node;
    new_node = (LN*)malloc(sizeof(LN));

    //step2 assign value
    new_node->data = d;

    //step3 setup direction
    new_node->next = *hptr;
    *hptr=new_node;
}

void show(LN *head){
  LN *cur;
  cur = head;
  while(cur != NULL){
    printf("%d|",cur->data);
    cur = cur->next;
  }
}

int sum(LN *head){
  LN *cur;
  cur = head;
  int sum = 0;
  while(cur != NULL){
    sum += cur->data;
    cur = cur->next;
  }
  return sum;
}
