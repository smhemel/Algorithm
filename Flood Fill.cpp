//
//  main.cpp
//  Flood Fill
//
//  Created by S M HEMEL on 2/8/17.
//  Copyright © 2017 Eastern University. All rights reserved.
//

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int flag[110][110],row,column;
char grid[110][110];
void floodfill(int i, int j);
int main()
{
    int i,j,cnt;
    cnt = 0;
    memset(flag, 0, sizeof(flag));
    cin>>row>>column;
    getchar();
    for(i=0; i<row; i++)
    {
        for(j=0; j<column; j++)
            scanf("%c", &grid[i][j]);
        getchar();
    }
    for(i=0; i<row; i++)
        for(j=0; j<column; j++)
            if(grid[i][j]=='.' && flag[i][j]==0)
            {
                cnt++;
                floodfill(i,j);
            }
    cout<<"Number of colored region is: "<<cnt<<endl<<endl;
    cout<<"New 2D array is:"<<endl<<endl;
    for(i=0; i<row; i++)
    {
        for(j=0; j<column; j++)
        {
            cout<<grid[i][j];
        }
        cout<<endl;
    }
    return 0;
}
void floodfill(int i, int j)
{
    if(i<0 || j<0 || i>row-1 || j>column-1)
        return;
    if(grid[i][j]=='.' && flag[i][j]==0)
    {
        flag[i][j]=1;
        grid[i][j]='+';
        
        floodfill(i+1,j);
        floodfill(i-1,j);
        floodfill(i,j+1);
        floodfill(i,j-1);
        floodfill(i+1,j+1);
        floodfill(i+1,j-1);
        floodfill(i-1,j+1);
        floodfill(i-1,j-1);
    }
}
