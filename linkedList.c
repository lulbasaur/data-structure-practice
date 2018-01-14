#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


struct Node{

  int value;
  struct Node * next;
  
};

struct Node* newLinkedList(){
  struct Node *node = malloc(sizeof(struct Node));
  node->value = 0;
  node->next = NULL;
  return node;
}


void linkNodes(struct Node *node, struct Node *newNode){
  
  struct Node *temp;
  temp = node->next;
  node->next = newNode;
  newNode->next = temp;
  
}

struct Node* deleteValue(struct Node *list, int value){
  
  struct Node *current;
  struct Node *nextNode;
  struct Node *temp;
  struct Node *prev;

  current = list;
  prev = list;
  temp = NULL;
  nextNode = current->next;

  bool run = true;
  
  if(list->value == value){

    temp=list;
    list=temp->next;
    free(temp);
    run=false;
  }

  while(run){
    if(current->value == value){
      temp = current;
      prev->next = nextNode;
      
      free(temp);
      run = false;	
    }
    else if(nextNode != NULL){

      prev = current;
      current = nextNode;
      nextNode = current->next;	
    }     
    else{

      printf("\n\nValue %d not in list! \n", value);
      run = false;
    } 
  }
  
  return list;
  
}

void changeValueAtIndex(struct Node *list, int value, int index){
  
  struct Node *current;
  struct Node *nextNode;
  current = list;
  nextNode = current->next;
  int i = 0;
  bool run = true;
  while(run){
    if(i == index){
      current->value = value;
      run = false;
      printf("\n Index %d changed...\n\n", index);

    }
    else if(nextNode != NULL){
      current = nextNode;
      nextNode = current->next;
      i++;
    }     
    else{
      printf("\n\n No item at index %d! \n", index);
      run = false;
    } 
  }
  
  
}


void findValueAtIndex(struct Node *list, int value, int index){
  
  struct Node *current;
  struct Node *nextNode;
  current = list;
  nextNode = current->next;
  int i = 0;
  bool run = true;
  while(run){
    if(i == index){
      run = false;
      printf("\n Value it index %d found...", index);
      printf("\n Value: %d\n\n", value);

    }
    else if(nextNode != NULL){
      current = nextNode;
      nextNode = current->next;
      i++;
    }     
    else{
      printf("\n\n No item at index %d! \n", index);
      run = false;
    } 
  }
  
  
}


void addValue(struct Node *list, int value){

  struct Node *current;
  struct Node *nextNode;

  struct Node *new = malloc(sizeof(struct Node));
  new->value = value;
  new->next = NULL;
  bool run = true;

  current = list;
  nextNode = current->next;
  
  if (list->value > value){
    new->value = list->value;
    list->value = value;
    linkNodes(list,new);
    run = false;   
  }
  while(run){
    
    if(nextNode != NULL && nextNode->value >= value){

      linkNodes(current,new);
      run = false;	
    }
    else if(nextNode != NULL){
	current = nextNode;
	nextNode = current->next;	
    }     
    else{
      current->next = new;
      run = false;
    } 
  }
}

void addValueNonSort(struct Node *list, int value){

  struct Node *current;
  struct Node *nextNode;

  struct Node *new = malloc(sizeof(struct Node));
  new->value = value;
  new->next = NULL;
  bool run = true;

  current = list;
  nextNode = current->next;
  
  while(run){
    
    if(nextNode != NULL){
	current = nextNode;
	nextNode = current->next;	
    }     
    else{
      current->next = new;
      run = false;
    } 
  }
}



void printList(struct Node *list){

  struct Node *current;
  bool run = true;

  current = list;
  printf("\n\tPrinting list: \n");
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


int main(int argc, char *argv[])
{

  bool run = true;
  struct Node *linkedListPtr = newLinkedList(); 
  int choice = 0;
  int value = 0;

  printf("\nLinked List created... \n");

  while(run){
    
    printf("\nEnter command:");
    printf("\n [1] add element (sorted)");
    printf("\n [2] delete element"); 
    printf("\n [3] print list");
    printf("\n [4] quit");
    printf("\n [5] add element (non-sorted)");
    printf("\n [6] Change element at index");
    printf("\n [7] Find element at index");
	

    printf("\nEnter integer (1-7):");

    scanf("%d", &choice);
    printf("\n");
	  

    // while(getchar() != '\0'){}
    
    switch (choice) {
      //add
    case 1: {
      
      printf("\n Add what value?");
      printf("\n Value: ");
      scanf("%d", &value);
      addValue(linkedListPtr, value);
      printf("\n Value %d added...\n\n", value);
      printList(linkedListPtr);
 
      break;
    }
      //delete
    case 2: {
      printf("\n Delete what value?");
      printf("\n Value: ");
      scanf("%d", &value);
      linkedListPtr = deleteValue(linkedListPtr,value);
      printList(linkedListPtr);
      
      break;
    }
      //print
    case 3: {
      printList(linkedListPtr);
      
      break;
    }
    case 4: {
      run = false;
      break;
    }
    case 5: {
      printf("\n Add what value?");
      printf("\n Value: ");
      scanf("%d", &value);
      addValueNonSort(linkedListPtr, value);
      printf("\n Value %d added...\n\n", value);
      printList(linkedListPtr);


      break;
    }
    case 6: {
      int index = 0;
      printf("\n Change at what index?");
      printf("\n Index: ");
      scanf("%d", &index);
      printf("\n Change to what value?");
      printf("\n Value: ");
      scanf("%d", &value);
      changeValueAtIndex(linkedListPtr, value,index);
      printList(linkedListPtr);
      break;
    }
    case 7: {
      int index = 0;
      printf("\n Find value at what index?");
      printf("\n Index: ");
      scanf("%d", &index);
      findValueAtIndex(linkedListPtr, value,index);
      printList(linkedListPtr);
      break;
    }
    default:
      break;
    }

  }
  
  
  return 0;
}
