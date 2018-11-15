//
//  main.cpp
//  Topological Sort
//
//  Created by S M HEMEL on 11/29/16.
//  Copyright © 2016 S M HEMEL. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int taken[55];
    int n,take[55][55],list[55],indegree[55];
    int i,j,k;
    int invalid = 0;
    cin >> n;
    for(int i=0; i<n; i++) cin >> taken[i];
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if( !indegree[j] && !taken[j]) {
                taken[j] = 1;
                list[i] = j;
                for(k=0; k<n; k++)
                    if( !taken[k] && take[j][k] )
                        --indegree[k];
                break;
            }
        if(j==n) {
            invalid = 1;
            break;
        }
    }
    if(invalid) printf("There is no solution\n");
    else
        for(i=0; i<n; i++)
            printf("%d\n", list[i]);
    }
    return 0;
}
