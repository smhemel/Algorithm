//
//  main.cpp
//  Insertion Sort
//
//  Created by S M HEMEL on 19/2/18.
//  Copyright © 2018 Eastern University. All rights reserved.
//

#include <iostream>
#include<cstdio>
using namespace std;
int arr[100]={1,5,3,7,2};
void insertionSort(){
    for(int i=1; i<5; i++) {
        int temp = arr[i];
        int k=i-1;
        while(temp<arr[k] && k>=0)
        {
            arr[k+1] = arr[k];
            k--;
        }
        arr[k+1]=temp;
    }
}
void insertionSort_d(){
    for(int i=1; i<5; i++) {
        int temp = arr[i];
        int k=i-1;
        while(temp>arr[k] && k>=0)
        {
            arr[k+1] = arr[k];
            k--;
        }
        arr[k+1]=temp;
    }
}
int main()
{
    insertionSort();
    for(int i=0; i<5; i++)
        printf("%d ",arr[i]);
    printf("\n");
    insertionSort_d();
    for(int i=0; i<5; i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;
}
