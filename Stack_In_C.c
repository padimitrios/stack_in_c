#include <stdio.h>
#include <stdlib.h>


typedef  struct stack{
  struct stack* next;
  int val;
}stack;

stack* createstack(int v){
  stack *node = malloc(sizeof(stack*));
  node->val = v;
  node->next = NULL;
  return node;
}


stack* insert(stack* head,int v){
    stack* node = malloc(sizeof(stack*));
    node->next = head;
    node->val = v;

    head = node;
    return head;
}

stack* pop(stack *head){
  if(head == NULL){
    printf("stack empty");
    return NULL;
  }
  stack* temp = head->next;
  head->next = NULL;
  free(head);
  return temp;
}

void printstk(stack *head){
  while(head != NULL){
    printf("%d->",head->val);
    head = head->next;
  }
}

int main(void) {
  stack*  stk = createstack(5);
  stk = insert(stk,90);
  stk = insert(stk,900);
  stk = insert(stk,123);
  printstk(stk);

  printf("\n\n\n");
  stk = pop(stk);
   stk = pop(stk);
    stk = pop(stk);


  printstk(stk);

  return 0;
}
