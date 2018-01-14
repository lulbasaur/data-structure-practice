#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


int arrayList[50];



void addValueEnd(int value){
  int length = arrayList[0] +1;
  arrayList[length] = value;
  arrayList[0] = arrayList[0]+1;
}

void addValueBegining(int value){
  
  for (int i = arrayList[0]+1; i > 0; i--){
    arrayList[i] = arrayList[i-1];
  }
  arrayList[1] = value;
  arrayList[0] = arrayList[0]+1;
}


void deleteValueEnd(){

  if (arrayList[0] > 1) {
    arrayList[0] = arrayList[0]-1;
  }
  else {
    printf("List is empty...");
  }
}


void deleteValueBegining(){
  int length = arrayList[0];
  if (arrayList[0] > 1) {
    for (int i = 1; i < length; i++) {
      arrayList[i]= arrayList[i+1];
    }
    arrayList[0] = arrayList[0] - 1;
  }
  else {
    printf("List is empty...");
  }
}

void printList(){
  int length;
  length = arrayList[0];
  printf("\t\t List: ");
  for (int i = 1; i < length+1; i++) {
    printf("%d ", arrayList[i]);
    
  }
  printf("\n");

}


void findValueAtIndex(int index){

  printf("\nValue: %d, Index: %d \n\n",arrayList[index+1], index);
  
}

void findValue(int value){

  int length = arrayList[0] + 1;
  for (int i = 1; i < length; i++) {
    if (arrayList[i] == value) {
      printf("\nFound %d in list!", value);
    }
    else {
      printf("\nValue %d not in list!", value);
	      
    }
  }
}

void changeValueAtIndex(int value, int index){
  
  arrayList[index+1] = value;
  
}


void addValueAtIndex(int value, int index){
  for (int i = arrayList[0]+1; i > index+1; i--){
    arrayList[i] = arrayList[i-1];
  }
  arrayList[index+1] = value;
  arrayList[0]= arrayList[0]+1;
  
}

void deleteValueAtIndex(int index){

  for (int j = index+1; j < arrayList[0]+1; j++){
    arrayList[j] = arrayList[j+1];
  }
  arrayList[0] = arrayList[0]-1;
}



int main(int argc, char *argv[])
{

  bool run = true;
  int choice = 0;
  int value = 0;

  printf("\nArray List created... \n");

  while(run){
    
    printf("\nEnter command:");
    printf("\n [1] add element end");
    printf("\n [2] add element begining");
    printf("\n [3] delete element at end");
    printf("\n [4] delete element at begining"); 
    printf("\n [5] print list");
    printf("\n [6] Find element at index");
    printf("\n [7] Find element");
    printf("\n [8] Change element at index");
    printf("\n [9] Add element at index");		
    printf("\n [10] Delete element at index");	
    printf("\n [11] quit");

	

    printf("\nEnter integer (1-11):");

    scanf("%d", &choice);
    printf("\n");
	  

    // while(getchar() != '\0'){}
    
    switch (choice) {
      //add end
    case 1: {
      
      printf("\n Add what value?");
      printf("\n Value: ");
      scanf("%d", &value);
      addValueEnd(value);
      printf("\n Value %d added...\n\n", value);
      printList();
 
      break;
    }
    case 2: {
            
      printf("\n Add what value?");
      printf("\n Value: ");
      scanf("%d", &value);
      addValueBegining(value);
      printf("\n Value %d added...\n\n", value);
      printList();
      break;
    }
    case 3: {
      
      deleteValueEnd();
      printList();
      
      break;
    }
      //print
    case 4: {
      deleteValueBegining();
      printList();
      
      break;
    }
      
    case 5: {
      printList();
      break;
    }
    case 6: {
      int index = 0;
      printf("\n Find at what index?");
      printf("\n Index: ");
      scanf("%d", &index);
      findValueAtIndex(index);
      printList();

      break;
    }
    case 7: {

      printf("\n Find what value?");
      printf("\n Value: ");
      scanf("%d", &value);
      findValue(value);
      printList();

      break;
    }
    case 8: {
      
      int index = 0;
      printf("\n Change at what index?");
      printf("\n Index: ");
      scanf("%d", &index);
      printf("\n Change to what value?");
      printf("\n Value: ");
      scanf("%d", &value);
      changeValueAtIndex(value,index);
      printList();
      
      break;
    }
    case 9: {
      int index = 0;
      printf("\n Add at what index?");
      printf("\n Index: ");
      scanf("%d", &index);
      printf("\n Add what value?");
      printf("\n Value: ");
      scanf("%d", &value);
      printf("\n");

      addValueAtIndex(value,index);
      printList();
      
      break;
    }
    case 10: {
      int index = 0;
      printf("\n Delete at what index?");
      printf("\n Index: ");
      scanf("%d", &index);
      printf("\n");

      deleteValueAtIndex(index);
      printList();

      break;
    }
    case 11: {
      run = false;
      break;
    }
    default:
      break;
    }

  }
  
  
  return 0;
}
