//
//  main.cpp
//  Matrix
//
//  Created by S M HEMEL on 11/29/16.
//  Copyright © 2016 S M HEMEL. All rights reserved.
//

#include <iostream> 
int main()
{
    int a[1000][1000],n,x,y,x1,y1,ans = 0;
    std::cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            std::cin >> a[i][j];
    std::cin >> x >> y >> x1 >> y1;
    for (int i=x1; i<=x; i++)
        for (int j=y1; j<=y; j++)
            ans = ans+a[i][j];
    std::cout << ans <<std::endl;
    return 0;
}
