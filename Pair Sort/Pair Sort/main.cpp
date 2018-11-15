//
//  main.cpp
//  Pair Sort
//
//  Created by S M HEMEL on 5/16/17.
//  Copyright © 2017 Eastern University. All rights reserved.
//

#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
pair <int , int > a;
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.first<b.first;
}
int main()
{
    int n = 10;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        make_pair(x,i);
    }
    sort(a,a+n,cmp);
    return 0;
}
