//
//  main.cpp
//  Structure Sort
//
//  Created by S M HEMEL on 5/11/17.
//  Copyright © 2017 Eastern University. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
struct classroom{
    char s[100];
    double cgpa;
    int id;
};
void structsort(struct classroom student[],int n){
    int i,j;
    for(i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
            if(strcmp(student[i].s,student[j].s)>0){
                swap(student[i].s,student[j].s);
                swap(student[i].id,student[j].id);
                swap(student[i].cgpa,student[j].cgpa);
            }
}
int main()
{
    struct classroom student[10];
    int n,i;
    cin >> n;
    for(i=0; i<10; i++)
        scanf("%s%d%lf",student[i].s,&student[i].id,&student[i].cgpa);
    structsort(student,10);
    for(i=0; i<10; i++)
        printf("%s %d %.2lf\n",student[i].s,student[i].id,student[i].cgpa);
    return 0;
}
