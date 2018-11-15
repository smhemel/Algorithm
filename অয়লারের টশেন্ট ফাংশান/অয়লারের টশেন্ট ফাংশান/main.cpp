//
//  main.cpp
//  অয়লারের টশেন্ট ফাংশান
//
//  Created by S M HEMEL on 20/1/18.
//  Copyright © 2018 Eastern University. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int totient(int n){
    int result = n;
    for(int i=2;i*i <= n;i++){
        if (n % i == 0) result -= result / i;
        while (n % i == 0) n /= i;
    }
    if (n > 1) result -= result / n;
    return result;
}
int main(){
    cout << totient(25) << endl;
    return 0;
}
