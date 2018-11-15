//
//  main.cpp
//  Quick Sort
//
//  Created by S M HEMEL on 2/2/17.
//  Copyright © 2017 S M HEMEL. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int arr[] = {7,6,2,10,4,5,9,8};
int n = sizeof(arr)/sizeof(arr[0]);
int partition(int low, int high)
{
    int pivot = arr[high];
    int i = (low-1);
    for (int j = low; j <= high-1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return (i+1);
}
void quickSort(int low, int high)
{
    int x = (rand()%n)+low;
    for(auto u: arr)
        cout << u << " ";
    cout << endl;
    //printf("Range: High(%d)  Low(%d) Random(%d)\n",high,low,x);
    if (low<x && n>x) {
        int pi = partition(low, x);
        quickSort(low, pi-1);
        quickSort(pi+1, x);
    }
}
int main()
{
    quickSort(0, n-1);
    printf("Sorted array: ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    puts("");
    return 0;
}






















/*#include <iostream>
#include<cstdio>
using namespace std;
void quicksort(int number[],int first,int last){
    int i, j, pivot, temp;
    if(first<last){
        pivot=first;
        i=first;
        j=last;

        while(i<j){
            while(number[i]<=number[pivot] && i<last)
                i++;
            while(number[j]>number[pivot])
                j--;
            if(i<j){
                temp=number[i];
                number[i]=number[j];
                number[j]=temp;
            }
        }
        temp=number[pivot];
        number[pivot]=number[j];
        number[j]=temp;
        quicksort(number,first,j-1);
        quicksort(number,j+1,last);
    }
}
int main(){
    int i, count, number[25];
    
    printf("How many elements are u going to enter?: ");
    scanf("%d",&count);
    
    printf("Enter %d elements: ", count);
    for(i=0;i<count;i++)
        scanf("%d",&number[i]);
    quicksort(number,0,count-1);
    printf("Order of Sorted elements: ");
    for(i=0;i<count;i++)
        printf("%d ",number[i]);
    cout << endl;
    return 0;
}*/


 
 
 
 
 
 
 
 
 
 
 
 
 
 
/*#include <iostream>
#include <cstdlib>
#define SIZE 10
//Quick Sort
using namespace std;
int compare (const void *elem1, const void *elem2){
    return *(int*)elem1 - *(int*)elem2;
}

int main(){
    int i;
    int array[SIZE] = {9,1,3,7,0,5,2,6,8,4};
    qsort(array, SIZE, sizeof(int), compare);
    for (i=0;i<SIZE;i++)
        cout << array[i] << " ";
    cout << endl;
    return 0;
}*/
