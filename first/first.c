#include <stdio.h>
#include <stdlib.h>
void printArray(int array[], int * size){
	//method to print an array
        int i;
        for (i = 0; i < *size; i++){
                printf("%d\t", array[i]);
        }
        printf("\n");
}


void sort(int array[], int *length, int ascending){
	//i used an altered version of insertion sort that takes another argument to sort in either ascending or descending order
	//this method is quite useful for my purposes
        int i = 0, key = 1;
        while (key < *length){
                int j = key;
                if (ascending == 0) {
			 while ((i >= 0) && (array[j] > array[i])) {
                                // swap elements
                                int temp = array[j];
                                array[j] = array[i];
                                array[i] = temp;
                                i--;
                                j--;
                        }
                }
                else {
                        while ((i >= 0) && (array[j] < array[i])){
                                int temp = array[j];
                                array[j] = array[i];
                                array[i] = temp;
                                i--;
                                j--;
                        }
                       
                }
                i = key;
                key++;
        }
}



int main(int argc, char *argv[]){
	//first create some useful local variables i can use throughout the main method
        int size;
        int i;
	//check if there are enough args inputted
        if (argc < 2) {
                return -1;
        }
	//open file
        char *filename = argv[1];
        FILE *fptr = fopen(filename, "r");
        fscanf(fptr, "%d\n", &size);
        int * arr = (int*) malloc(sizeof(int) * size);
        for (i = 0; i < size; i++){
                fscanf(fptr, "%d", &arr[i]);
        }
	//now we're done with the file so close it
        fclose(fptr);
	//try to find count of even and odd numbers in the file
        int oCount = 0, eCount;
        for (i = 0; i < size; i++){
                if (arr[i] % 2 != 0){
                        oCount++;
                }
        }
        eCount = size - oCount;
	//create two arrays for even and odds so we can separate for now but put back later
        int *evens = (int*) malloc(sizeof(int) * eCount);
        int *odds = (int*) malloc(sizeof(int) * oCount);
        int oInd = 0, eInd = 0;
	//this loop separates the given array into even and odd arrays
        for (i = 0; i < size; i++){
                if (arr[i] % 2 != 0){
                        odds[oInd] = arr[i];
                        oInd++;
                }
                else {
                        evens[eInd] = arr[i];
                        eInd++;
                }
        }
	//sort both of the arrays we made
        sort(evens, &eCount, 0);
        sort(odds, &oCount, 1);
	//now put the arrays back together except in correct order
        for (i = 0; i < oCount; i++){
                arr[i] = odds[i];
        }
        for (eInd = 0; i < size; i++, eInd++){
                arr[i] = evens[eInd];
        }
        printArray(arr, &size);
	//free the dynamic memory we allocated
        free(arr);
        arr = NULL;
        free(evens);
        evens = NULL;
        free(odds);
        odds = NULL;

        return 0;
}
