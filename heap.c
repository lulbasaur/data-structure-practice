#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


#define MAX_SIZE 100
#define LEFT(i) ((2*i))
#define RIGHT(i) ((2*i)+1)

int HEAP_SIZE;
int HEAP[MAX_SIZE+1];

void init_heap(){
  HEAP_SIZE = 0;
  HEAP[0] = HEAP_SIZE;
}

void heapify(int i){
  int left = LEFT(i);
  int right =  RIGHT(i);
  int largest;
  int temp;
  if (left >= HEAP_SIZE){
    return;
  }
  if (left <= HEAP_SIZE && HEAP[left] > HEAP[i]){
    largest = left;
  }
  else{
    largest = i;
  }
  if(right <= HEAP_SIZE && HEAP[right] > HEAP[largest]){
    largest = right;
  }
  if(largest != i){
    temp = HEAP[i];
    HEAP[i] = HEAP[largest];
    HEAP[largest] = temp;
    heapify(largest); 
  }
}


void build_heap(){
  for(int i = HEAP_SIZE/2; i > 0; i--){
    heapify(i);
  }
}

int extract_max(){
  if(HEAP_SIZE < 1){
    printf("\n\tEMPTY!\n");
    return 0;
  }
  int max = HEAP[1];
  HEAP[1] = HEAP[HEAP_SIZE];
  HEAP_SIZE--;
  HEAP[0] = HEAP_SIZE;
  heapify(1);
  printf("\n\tExtracted max: %d\n", max);
  return max;
}

void insert(int i){
  if (HEAP_SIZE < MAX_SIZE) {
    HEAP[HEAP[0]+1] = i;
    HEAP_SIZE++;
    HEAP[0]= HEAP_SIZE;
  }
  printf("\n\tValue %d inserted...\n", i);
  build_heap();
}

void print_heap(){
  printf("\nPrinting heap:\t");
  for (int i = 1; i < HEAP_SIZE+1; i++) {
    printf("%d ", HEAP[i]);
  }
  printf("\n"); 
}

int main(){
  init_heap();
  bool run = true;
  int choice = 0;
  int value = 0;

  insert(5);
  insert(6);
  insert(5400);
  insert(4);
  insert(23);
  insert(643);
  insert(1);

  print_heap();

  extract_max();
  print_heap();
  extract_max();
  print_heap();
  extract_max();
  print_heap();
  extract_max();
  print_heap();
  insert(8923);
  insert(2);
  insert(43);
  print_heap();
  extract_max();
  print_heap();



  
  while(run){
    
    printf("\nEnter command:");
    printf("\n [1] Insert element");
    printf("\n [2] Extract max");
    printf("\n [3] Print heap");
    printf("\n [4] Quit");

    printf("\nEnter integer (1-4):");

    scanf("%d", &choice);
    printf("\n");
	  
    
    switch (choice) {
    case 1: {
      
      printf("\n Insert what value?");
      printf("\n Value: ");
      scanf("%d", &value);
      insert(value);
      printf("\n\tValue %d inserted...\n", value);
 
      break;
    }
    case 2: {
      extract_max();
      break;
    }
    case 3: {
      print_heap();
      break;
    }
    default:
      run = false;
      break;
    }

  }
  
  return 0;
}
