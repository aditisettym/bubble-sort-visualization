#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ARRAY_SIZE 10
#define DELAY_MICROSECONDS 100000 // 1 second

//call by refrence - passing address of array
void swap(int *a, int *b) {
    int temp=*a; //value of a in temp
    *a=*b;
    *b=temp;
}

void delay(int microseconds){
    //converting micro to nano 
    //ieration in for loop apprx takes time in nanoseconds 
    int nanoseconds = microseconds*10000;
    //running an empty loop to create a delay
    //each iteration takes some nanoseconds 
    for (int i=0;i<nanoseconds;i++);
}

void bubbleSort(int arr[],int size) {
    for (int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if (arr[j]>arr[j+1]){
                swap(&arr[i],&arr[j+1]);
                printArray(arr,size,j,j+1);
                delay(DELAY_MICROSECONDS); //might appear as animation(because of delay) but we are printing and clearing the screen
            }
        }
    }
}

void printArray(int arr[],int size,int selected1,int selected2) {
    //selected elements are the index of elements which are being swaped (being highligted)
    for(int i=0;i<size;i++) {
        if (i==selected1 || i==selected2) {
            //set text color to red for selected elemenst
            printf("\x1b[31m%d \x1b[0m",arr[i]);
        }
        else {
            printf("%d ",arr[i]);
        }
    }
    //moves the cursor back to the starting of the statement - because we are overwriting 
    printf("\r");
    //remove buffers and immediately print 
    //flush the output to make it visible immediatley 
    fflush(stdout);
    //the above two lines are used to create an animation kind of effect 
}


int main() {
    srand(time(NULL)); //takes the current time from your computer , its a built in function

    int arr[ARRAY_SIZE];
    for(int i=0;i<ARRAY_SIZE;i++){
        arr[i]=rand()%100; //generate random number from 0 to 100 (%100)
    }

    //printing the original array - that random array
    printf("Original array: ");
    printArray(arr,ARRAY_SIZE,-1,-1);
    printf("\n");

    //priniting the animation steps
    printf("Sorting steps:\n");
    bubbleSort(arr,ARRAY_SIZE);

    //printing sorted array
    printf("\nSorted array: ");
    printArray(arr,ARRAY_SIZE,-1,-1);
    printf("\n");
}