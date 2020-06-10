//min coin required to make given sum
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int dp[4][31];
int min_coin(int *coin,int n,int sum){
    for(int k=0;k<n+1;k++){
        for(int l=0;l<sum+1;l++){
            if(k==0){
            dp[k][l]=INT_MAX-1;
           }
            if(l==0){
                dp[k][l]=0;
           }
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<sum+1;j++){
            if(coin[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=min(dp[i-1][j],1+dp[i][j-coin[i-1]]);
            }
        }
    }
    return dp[n][sum];
}
int main()
{
    int coin[3]={1,2,3};
    int sum=4;
    int ans=min_coin(coin,3,sum);
    cout<<ans;
    return 0;
}
