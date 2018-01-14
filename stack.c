#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


struct Node{

  int value;
  struct Node * next;

};



struct Node* newLinkedStack(){
  struct Node *node = malloc(sizeof(struct Node));
  int size = 0;
  node->value = size;
  node->next = NULL;
  return node;
}

struct Node* pushValue(struct Node *stack, int value){

  struct Node *newNode = malloc(sizeof(struct Node));
  struct Node *temp;
  newNode->value = value;
  
  temp=stack->next;
  stack->next=newNode;
  stack->next->next = temp;

  stack->value = stack->value + 1;
  
  return stack;
}

struct Node* popValue(struct Node *stack){
  if (stack->next != NULL) {
    
  
  struct Node *start;
  struct Node *temp;

  start = stack->next;
  printf("\n\tPopped Value: %d\n", start->value);

  temp = NULL;

  temp=start->next;
  stack->next = temp;
  free(start);

  stack->value = stack->value - 1;

  return stack;
  }
  else {
    return stack;
  }
}

void printStack(struct Node *stack){

  struct Node *current;
  bool run = true;
  
  if (stack->next != NULL) {
  
  current = stack->next;
  printf("\n\tPrinting stack: \n\t");

  while (run) {
    printf("%d ", current->value);
    
    if(current->next != NULL){

      current = current->next;
    }	
    
    else{
      run = false;
    }
    
  }
  printf("\n");
  }
  else {
    printf("\n\tStack empty! \n");
    
  }
}


void printSize(struct Node *stack){

  printf("\tSize: %d\n", stack->value);
  
}

void peakTop(struct Node *stack){

  if (stack->next != NULL) {
    printf("\tTop: %d\n", stack->next->value);
  }
  else {
    printf("\n\tStack empty! \n");
  }
  
  
}

int main()
{

  bool run = true;
  struct Node *linkedStackPtr = newLinkedStack(); 
  int choice = 0;
  int value = 0;

  printf("\nLinked Stack created... \n");

  while(run){
    
    printf("\nEnter command:");
    printf("\n [1] Push element");
    printf("\n [2] Pop element"); 
    printf("\n [3] Print top element"); 
    printf("\n [4] Quit\n"); 
	

    printf("\nEnter integer (1-4):");

    scanf("%d", &choice);
    printf("\n");
	  

    // while(getchar() != '\0'){}
    
    switch (choice) {
      //add
    case 1: {
      
      printf("\n\t Push what value?\n");
      printf("\nValue: ");
      scanf("%d", &value);
      linkedStackPtr = pushValue(linkedStackPtr, value);
      printf("\n\tValue %d added...\n\n", value);
      printStack(linkedStackPtr);
      printSize(linkedStackPtr);
 
      break;
    }
      //delete
    case 2: {
      linkedStackPtr = popValue(linkedStackPtr);
      printStack(linkedStackPtr);
      printSize(linkedStackPtr);      
      break;
    }
    case 3: {
      peakTop(linkedStackPtr);
      break;
      }
    default:
      free(linkedStackPtr);
      run = false;
      break;
    }
  }
  
  
  return 0;
}
