//
//  main.cpp
//  String sort Using Iterator
//
//  Created by S M HEMEL on 3/23/17.
//  Copyright © 2017 Eastern University. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;
map <string,int> s;
int main()
{
    s["hemel"] = 10;
    s["Habib"] = 8;
    s["Nayan"] = 3;
    s["Sabu"] = 15;
    s["Jeba"] = 20;
    for(auto it=s.begin(); it!=s.end(); it++)
        cout << it->first  << " = " << it->second << endl;
    return 0;
}
