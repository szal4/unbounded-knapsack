//givne a rod of l length and different lenght you can cut in cut array and corrosponding price of that cut 
//you have to find maximum price you can get
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int dp[5][6];
int max(int a,int b){
    if(a>b){
       return a; 
    }
    else{
        return b;
    }
}
int roadcut(int *c,int *p,int n,int len){
    for(int k=0;k<n+1;k++){
        for(int l=0;l<len+1;l++){
            if(k==0||l==0){
                dp[k][l]=0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=len;j++){
            if(j<c[i-1]){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(dp[i-1][j],p[i-1]+dp[i][j-c[i-1]]);//if we take ith element then we write dp[i](not dp[i-1])
            }
        }
    }
    return dp[n][len];
}
int main()
{
    int l=5;
    int cut[4]={1,2,3,4};
    int pr[4]= {1,3,1,5};
    int ans=roadcut(cut,pr,4,l);
    cout<<ans;

    return 0;
}
