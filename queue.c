#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


struct Node{
  int value;
  int size;
  struct Node *tail;
  struct Node * next;
};



struct Node* newLinkedQueue(){
  struct Node *node = malloc(sizeof(struct Node));
  node->next = NULL;
  node->tail = NULL;
  node->size = 0;
  node->value = 0; 
  return node;
}

struct Node* enqueueValue(struct Node *queue, int value){

  struct Node *newNode = malloc(sizeof(struct Node));
  
  newNode->value = value;

  if (queue->tail != NULL) {
    
    queue->tail->next = newNode;
  }
  else {
    queue->next = newNode;
  }
  queue->tail = newNode;

  queue->size = queue->size + 1;

  return queue;
}

struct Node* dequeueValue(struct Node *queue){
  if (queue->next != NULL) {
    
  struct Node *head;
  struct Node *temp;

  head = queue->next;
  printf("\n\tDequeued value: %d\n", head->value);

  temp = NULL;

  temp=head->next;
  queue->next = temp;
  free(head);

  queue->size = queue->size - 1;

  return queue;
  }
  else {
    return queue;
  }
}


void linkNodes(struct Node *node, struct Node *newNode){
  
  struct Node *temp;
  temp = node->next;
  node->next = newNode;
  newNode->next = temp;
  
}

struct Node* enqueueValuePriority(struct Node *queue, int value){

  struct Node *newNode = malloc(sizeof(struct Node));
  struct Node *current;
  struct Node *nextNode;

  newNode->value = value;

  bool run = true;
  
  current = queue;
  nextNode = current->next;

  
  while(run){
    //0  23 12 1 
    if(nextNode != NULL && nextNode->value <= value){
      linkNodes(current,newNode);
      run = false;	
    }
    else if(nextNode != NULL){
	current = nextNode;
	nextNode = current->next;	
    }     
    else{
      current->next = newNode;
      queue->tail = newNode;
      run = false;
    } 
  }
  queue->size = queue->size +1;
  return queue;
}


void printQueue(struct Node *queue){
  struct Node *current;
  bool run = true;  
  if (queue->next != NULL) {
    current = queue->next;
    printf("\n\tPrinting queue: \n\t");

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
    printf("\n\tQueue empty! \n");
    
  }
}


void printSize(struct Node *queue){

  printf("\tSize: %d\n", queue->size);
  
}


int main()
{

  bool run = true;
  struct Node *linkedQueuePtr = newLinkedQueue(); 
  int choice = 0;
  int value = 0;

  printf("\nLinked Queue created... \n");

  while(run){
    
    printf("\nEnter command:");
    printf("\n [1] Enqueue element");
    printf("\n [2] Dequeue element");
    printf("\n [3] Enqueue element with priority");
    printf("\n [4] Quit\n"); 
	
    printf("\nEnter integer (1-3):");

    scanf("%d", &choice);
    printf("\n");
	  
    
    switch (choice) {
    case 1: {
      
      printf("\n\t Enqueue what value?\n");
      printf("\nValue: ");
      scanf("%d", &value);
      linkedQueuePtr = enqueueValue(linkedQueuePtr, value);
      printf("\n\tValue %d added...\n\n", value);
      printQueue(linkedQueuePtr);
      printSize(linkedQueuePtr);
 
      break;
    }
      //delete
    case 2: {
      linkedQueuePtr = dequeueValue(linkedQueuePtr);
      printQueue(linkedQueuePtr);
      printSize(linkedQueuePtr);      
      break;
    }
    case 3: {

      printf("\n\t Enqueue what value with priority?\n");
      printf("\nValue: ");
      scanf("%d", &value);
      linkedQueuePtr = enqueueValuePriority(linkedQueuePtr, value);
      printf("\n\tValue %d added...\n\n", value);
      printQueue(linkedQueuePtr);
      printSize(linkedQueuePtr);
      
	break;
      }
    default:
      free(linkedQueuePtr);
      run = false;
      break;
    }
  }
  
  
  return 0;
}
