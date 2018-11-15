#include <bits/stdc++.h>
using namespace std;
// This three variable dicliar global because
// I use it many other function.
int pos, n_factor_len[11000];
char dp_fact[12000][45000];
// sum dicliar here for memory saving.
char sum[20000][40010];
// This in my reverse function
void revers(char s[], int len);
// This in Muliplycation function
void mult(char num1[], char num2[]);
// This function convert number to string
void num_to_string(char s[], int n);
// This function for store all factorial between n.
void store_all_fact(int num);
int main()
{
    int n, len, i, start=clock();
    store_all_fact(1000);
    cout<<clock()-start<<endl;
    while(cin>>n){
        printf("%s\n",dp_fact[n]);
    }
    return 0;
}
void num_to_string(char s[], int n)
{
    int x=n, i=0;
    while(n!=0){
        s[i++] = (n%10)+48;
        n/=10;
    }s[i]=0;
    revers(s, i);
}
void mult(char num1[], char num2[])
{
    int i, J, k, l, mult, len1, len2, small_sum;
        len1=strlen(num1);
        len2=strlen(num2);
        // This line for remember this factorial number length.
        n_factor_len[pos-1]=len1;
        // This is main loop for finding total multiple;
        for(i=len2-1, l=0; i>=0; i--, l++){
            for(J=len1-1,k=l, mult=0; J>=0; J--,k++){
                mult = mult+((num1[J]-48)*(num2[i]-48));
                sum[i][k] = mult % 10;
                mult = mult/10;
            }
            if(mult>0) sum[i][k++]=mult;
        }len1=k;
        // loop for finding total sum;
        for(i=0, small_sum=0; i<len1; i++){
            for(J=0; J<len2; J++)
                small_sum=sum[J][i]+small_sum;
            dp_fact[pos][i]=(small_sum%10)+48;
            small_sum=small_sum/10;
        }
        if(small_sum>0) dp_fact[pos][i++]=small_sum+48;
        // Using this line I finish the string line.
        dp_fact[pos][i]=0;
        revers(dp_fact[pos],i);
}
void store_all_fact(int num)
{
    char s[20];
    int i;
    dp_fact[0][0]='1';
    for(pos=1; pos<=num; pos++){
        num_to_string(s, pos);
        mult(dp_fact[pos-1], s);

    }
}
void revers(char s[], int len)
{
    int i = len-1, J;
    for(len=len>>1, J=0; i>J; i--,J++){
        s[J] ^= s[i];
        s[i] ^= s[J];
        s[J] ^= s[i];
    }
}

