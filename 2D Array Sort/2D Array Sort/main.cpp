//
//  main.cpp
//  2D Array Sort
//
//  Created by S M HEMEL on 2/22/17.
//  Copyright © 2017 Eastern University. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char *array[10000][1000];
#define n_array sizeof(array)/sizeof(const char *)
static int compare (const void * a, const void * b)
{
    return strcmp (*(const char **) a, *(const char **) b);
}
int main ()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i=0; i<n; i++)
        scanf("%s",array[i]);
    qsort (array, n_array, sizeof (const char *), compare);
    for (int i = 0; i < n_array; i++) {
        printf ("%s\n",array[i]);
    }
    return 0;
}
