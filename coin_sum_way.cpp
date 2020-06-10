//given coin array you have to find no of ways to make the given sum
//remember coin can we taken multiple time
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[4][6];
int way(int *coin,int n,int sum){
    for(int k=0;k<n+1;k++){
        for(int l=0;l<sum+1;l++){
            if(k==0){
            dp[k][l]=0;
           }
            if(l==0){
                dp[k][l]=1;
           }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(coin[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j]+dp[i][j-coin[i-1]];
            }
        }
    }
    return dp[n][sum];
}
int main()
{
    int coin[3]={1,2,3};
    int sum=5;
    int ans=way(coin,3,sum);
    cout<<ans;
    return 0;
}
