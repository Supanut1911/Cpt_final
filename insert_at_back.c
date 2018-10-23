#include<stdio.h>
#include<stdlib.h>

struct mynode{
  int data;
  struct mynode *link;
};

typedef struct mynode LN;

LN *find_tail(LN *head){
  LN* tail;
  if(head == NULL){
    return NULL;
  }
  tail = head;
  while(tail->link != NULL){
    tail = tail->link;
  }
  return tail;
}



void insert_at_back(LN **hptr, int d){
  LN *new_node;
  new_node = (LN*)malloc(sizeof(LN));
  new_node->data = d;
  new_node->link = NULL;
  LN *tail = find_tail(*hptr);

  //condition check for creating at empty to 1 node
  if(tail == NULL){
    *hptr = new_node;
  }
  //condition check for creating for 2 node , 3 node ... n node
  else{
    tail->link = new_node;
  }
}



void show(LN *head){
  LN* current = head;
  while(current != NULL){
    printf("%d|",current->data );
    current = current->link;
  }
}

int sum(LN *head){
  int sum = 0;
  LN* current = head;
  while (current != NULL) {
    sum += current->data;
    current = current->link;
  }
  return sum;
}

int main(){
  LN *head;
  LN **hhead;
  head = NULL;
  hhead = &head;
  int data;
  int i=0;
  printf("%s\n","enter value:" );
  do{
    printf("data(%d)=",i+1 );
    i++;
    scanf(" %d",&data);
    if(data >0){
      insert_at_back(hhead,data);
    }
  }while(data > 0);
  show(head);
  printf("\nsum = %d\n",sum(head) );


  return 0;
}
