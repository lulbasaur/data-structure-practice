#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define INIT_CAP 1000;

typedef struct List{
  int size;      
  int capacity;  
  int *elements; 
}List;

void init_list(List* list, int capacity){
  list->size = 0;
  list->capacity = capacity;
  list->elements = malloc(sizeof(int) * list->capacity);  
}

void add_to_list(List* list,int i){
  if(list->size < list->capacity){
    list->elements[list->size] = i;
    list->size = list->size +1; 
  }
}

int return_element(List* list, int i){
  if (i < 0 || i >= list->size) {
    printf("return_element: index out of bounds error\n");
    exit(EXIT_FAILURE);
  }
  else
    return list->elements[i];
}


void set_element(List* list, int i, int j){
  if (i < 0 || i >= list->size) {
    printf("set_element: index out of bounds error\n");
    exit(EXIT_FAILURE);
  }
  else
    list->elements[i] = j;
}


//not used: still under implementation
List* double_list_capacity(List **list){
  List* new_list = malloc(sizeof(List));
  init_list(new_list,(*list)->capacity*2);
  for (int i = 0; i < (*list)->size; i++) {
    new_list->elements[i] = return_element(*list,i);
  }
  free(*list);
  return new_list;
}

void parse_ints_from_file_to_list(FILE* file, List* list){
  int i = 0;
  while (fscanf(file, "%d", &i) == 1){
      add_to_list(list,i);
    }
}


int find_pivot(int i, int j, int k){
  int median = i;
  if (i <= j){
    median = j;
  }
  if (median>k) {
    median = k;
  }
  return median;
}

// Based on the Hoare partition scheme pseudocode:
// https://en.wikipedia.org/wiki/Quicksort#Hoare_partition_scheme
int partition( List* list, int p, int r) {
   int pivot, i, j, temp;
   //pivot = list->elements[p];
   if(r-p > 2){
     pivot = find_pivot(return_element(list,p),
			return_element(list,r/2),
			return_element(list,r));
   }
   else{
     pivot = list->elements[p];
   }
   i = p-1;
   j = r+1;	
   while(true)
   {
     do --j; while( return_element(list,j) > pivot);
     do ++i; while( return_element(list,i) < pivot);

   	if( i >= j ) return j;	

	else{
	  //temp = list->elements[i];
	  temp = return_element(list,i);
	  set_element(list,i,return_element(list,j));
	  //list->elements[i] = return_element(list,j);
	  set_element(list,j,temp);
	  //list->elements[j] = temp;
	}
   }
}


// Based on the Hoare partition scheme pseudocode:
// https://en.wikipedia.org/wiki/Quicksort#Hoare_partition_scheme
void quicksort( List *list, int p, int r)
{
   int q;
   if(p < r) 
     {
       q = partition(list, p, r);
       quicksort(list, p, q);
       quicksort(list, q+1, r);
   }
}

int main(int argc, char *argv[]){
  if (argc != 2){
    printf( "usage: %s [filename]\n",argv[0]);
   }
  else{
    // create list
    List* list = malloc(sizeof(List));
    int capacity = INIT_CAP;
    init_list(list, capacity);

    //open file
    FILE *file = fopen( argv[1],"r");
    parse_ints_from_file_to_list(file,list);
    fclose(file);

    printf("\nUnsorted list: ");
    for (int i = 0; i < list->size; i++) {
      printf(" %d ",list->elements[i]);
    }
    printf("\n");

    printf("quicksorting...\n");
    quicksort(list,0,list->size-1);//quicksort(list, starting index, max index)

    //print sorted list
    printf("Sorted list:   ");
    for (int i = 0; i < list->size; i++) {
      printf(" %d ",list->elements[i]);
    }
    printf("\n");
    printf("\n");

    free(list->elements);
    free(list);
  }
  return 0;
}
