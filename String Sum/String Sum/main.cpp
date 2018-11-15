//
//  main.cpp
//  String Sum
//
//  Created by S M HEMEL on 11/26/16.
//  Copyright © 2016 S M HEMEL. All rights reserved.
//

/*#include <iostream>
using namespace std;
int main()
{
    int num1[10010],num2[10010],sum[10010];
    char s1[23],s2[23];
    while (cin >> s1 >> s2)
    {
        int l1,l2,carry = 0,k = 0;
        for (l1=0; s1[l1] != '\0'; l1++)
            num1[l1] = s1[l1] - '0';
        
        for (l2=0; s2[l2] !='\0'; l2++)
            num2[l2] = s2[l2] -'0';
        int i = l1 - 1;
        int j = l2 - 1;
        for (; i>=0 && j>=0; i--,j--,k++)
        {
            sum[k] = (num1[i]+num2[j]+carry) % 10;
            carry = (num1[i]+num2[j]+carry) / 10;
        }
        if (l1>l2)
        {
            while(i>=0)
            {
                sum[k++] = (num1[i] + carry) % 10;
                carry = (num1[i--] + carry) / 10;
            }
            if(sum[k-1]!=carry)
                sum[k++]=carry;
            
        }
        else if (l1<l2)
        {
            while (j>=0)
            {
                sum[k++] = (num2[j] + carry) % 10;
                carry = (num2[j--] + carry) / 10;
            }
            if(sum[k-1]!=carry)
                sum[k++]=carry;
        }
        else
        {
            if (carry > 0)
                sum[k++] = carry;
        }
        
        printf("Result: ");
        for (k--; k >= 0; k--)
            cout << sum[k];
        cout <<endl;
    }
    return 0;
}*/



#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>
using namespace std;
int main()
{
    char s[10010],s1[10010],s2[10000],s3[10000];
    while (cin >> s >> s1)
    {
        int len = (int) strlen(s);
        int len1 = (int) strlen(s1);
        if(len<len1)
        {
            int op = len;
            len = len1;
            len1 = op;
            strcpy(s3,s1);
            strcpy(s1,s);
            strcpy(s,s3);
        }
        int k= 0,temp = 0,x = 0;
        for(int i=len-1,l=len1-1; i>=0; i--,l--)
        {
            temp = (l<0) ? ((s[i]-'0')+x) : ((s[i]-'0')+(s1[l]-'0')+x);
            if(temp>9) {
                s2[k++] = ((temp%10)+'0');
                x = temp/10;
            }
            else {
                s2[k++] = (temp+'0');
                x = 0,temp = 0;
            }
        }
        if(x>0)
            s2[k++] = x+'0';
        for(int i=k-1; i>=0; i--)
            cout << s2[i];
    }
    
    return 0;
}
