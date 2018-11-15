//
//  main.cpp
//  Permutation
//
//  Created by S M HEMEL on 11/29/16.
//  Copyright © 2016 S M HEMEL. All rights reserved.
//

/*#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
    int myints[] = {1,2,3};
    sort (myints,myints+3);
    cout << "The 3! possible permutations with 3 elements:\n";
    do
    {
        cout <<myints[0]<<' '<<myints[1]<<' '<< myints[2] << '\n';
    }while(next_permutation(myints,myints+3));
    
    cout << "After loop: " << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
    
    return 0;
}


#include <stdio.h>
#include <cstring>
void swap(char *x,char *y);
void permutate(char *x,int i,int n) {
    int j;
    if(i==n) printf("%s\n",x);
    else {
        for(j=i;j<=n;j++) {
            swap(x+i,x+j);
            permutate(x,i+1,n);
            swap(x+i,x+j);
        }
    }
}
// Combination
void swap(char *x,char *y) {
    char temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int main()
{
    char x[30];
    printf("\nEnter a word : ");
    scanf("%s",x);
    permutate(x,0,(int)strlen(x)-1);
    return 0;
}*/






#include <iostream>
#include <cstring>
using namespace std;
void swap(char *x,char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}
void permutation(char *s, int i, int n)
{
    int j;
    if(i==n)
        cout << s << endl;
    else {
        for(j=i; j<=n; j++)
        {
            swap(s+i,s+j);
            permutation(s,i+1,n);
            swap(s+i,s+j);
        }
    }
}
int main()
{
    char s[100];
    cin >> s;
    int n = (int) strlen(s) - 1;
    permutation(s,0,n);
}


