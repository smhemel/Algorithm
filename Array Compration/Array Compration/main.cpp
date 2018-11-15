//
//  main.cpp
//  Array Compration
//
//  Created by S M HEMEL on 11/28/16.
//  Copyright © 2016 S M HEMEL. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;
void compress()
{
    map<int,int>mymap;
    int input[]={-102,1,134565589,134565589,-102,66666668,134565589,66666668,-102,1,-2};
    int assign=0,compressed[100],c=0,n=sizeof(input)/sizeof(int);
    for(int i=0;i<n;i++)
    {
        int x=input[i];
        if(mymap.find(x)==mymap.end())
        {
            mymap[x]=assign;
            printf("Mapping %d with %d\n",x,assign);
            assign++;
        }
        x=mymap[x];
        compressed[c++]=x;
    }
    printf("Compressed array: ");
    for(int i=0;i<n;i++)
        printf("%d ",compressed[i]);puts("");
}
int main()
{
    compress();
    return 0;
}
