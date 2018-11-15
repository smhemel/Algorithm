//
//  main.cpp
//  Sorting 2D string array
//
//  Created by S M HEMEL on 1/31/17.
//  Copyright © 2017 S M HEMEL. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char s[100][100],s1[100];
    int n;
    cin >> n;
    cout << "Enter Name: \n";
    for(int i=0; i<n; i++)
        cin >> s[i];
    for(int i=0; i<n; i++)
        for(int l=0; l<n-i; l++)
        {
            int r = strcmp(s[i],s[i+1]);
            if(r>0)
            {
                strcpy(s1,s[i]);
                strcpy(s[i],s[i+1]);
                strcpy(s[i+1],s1);
            }
        }
    for(int i=0; i<n; i++)
        cout << s[i] <<endl;
    return 0;
}
