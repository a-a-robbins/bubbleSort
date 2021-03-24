#include <stdio.h>
#include <stdlib.h>


void bubbleSort(int arr[], int size);
void printArr(int arr[], int size);
 

int main(int argc, char* argv[])
{
  FILE *ifp = NULL; 
    
  ifp = fopen(argv[1], "r"); 
    if(ifp == NULL)
    {
      printf("Whoops, %s didn't open properly...sorry...exiting :(\n", argv[1]); 

      exit(1); 
    }

  int size = 0; 
  fscanf(ifp, "%d", &size); 

  int list[size]; 

  for(int i = 0; i < size; i++)
  {
    fscanf(ifp, "%d", &list[i]); 
  }

  printf("\n** Before Sorting**\n"); 
  for(int i = 0; i < size; i++)
  {
    printf("%d ", list[i]); 
  }
  printf("\n\n"); 

  printf("==Bubble Sort==\n"); 
  bubbleSort(list, size); 
  printf("==Sorting Completed==\n\n\n"); 

  printf("** After Sorting**\n"); 
  for(int i = 0; i < size; i++)
  {
    printf("%d ", list[i]);
  }
  fclose(ifp); 
	return 0;
}

void bubbleSort(int arr[], int size)
{
  
  int printSize = size; 
  int swapped; 


  for(int i = 0; i < size; i++)
  {
    swapped = 0; 

    for(int j = 0; j < size-1; j++)
    {
      if(arr[j] > arr[j+1])
      {
        int temp = arr[j]; 
        arr[j] = arr[j+1]; 
        arr[j+1] = temp;

        swapped = 1; 
      }

     
      printArr(arr, printSize);
    
    }
      if(swapped == 0)
      {
        break;
      }       

    printSize = printSize-1; 
    printArr(arr, printSize);     
    
  }

}

void printArr(int arr[], int size)
{
  for(int i = 0; i < size; i++)
  {
    printf("%3d ", arr[i]); 
  }
  printf("\n"); 
}
