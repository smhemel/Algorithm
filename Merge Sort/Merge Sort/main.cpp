//
//  main.cpp
//  Merge Sort
//
//  Created by S M HEMEL on 26/2/18.
//  Copyright © 2018 Eastern University. All rights reserved.
//

#include<iostream>
#include<cstdio>
using namespace std;
int arr[] = {38,27,43,3,9,82,-10};
void merge(int l, int m, int r) {
    int n1 = m-l+1, n2 = r-m;
    int left[n1], right[n2];
    for (int i=0; i<n1; i++) left[i]=arr[l+i];
    for(int j=0; j<n2; j++) right[j] = arr[m+1+j];
    int i = 0,j = 0,k = l;
    while (i<n1 && j<n2) {
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while(i<n1) arr[k++] = left[i++];
    while(j<n2) arr[k++] = right[j++];
}
void mergeSort(int l, int r) {
    if(l<r) {
        int m = l+(r-l)/2;
        cout << "sort: " << l << " " << m << " " << r << endl;
        mergeSort(l, m);
        mergeSort(m+1, r);
        merge(l, m, r);
    }
}
int main() {
    mergeSort(0,6);
    printf("Sorted array is : ");
    for(int i=0; i<6; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
