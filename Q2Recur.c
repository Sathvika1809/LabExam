#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max(int a,int b){
    return a>b?a:b;

}

int foo(int* p,int n,int* hours,int idx,int H,int dp[][H+1]){

   if(dp[idx][H]!=-1){
      return dp[idx][H];
   }
   if(idx == 0){
    if(hours[idx]<=H){
        dp[idx][H] = p[idx];
    }else{
        dp[idx][H] = 0;
    }
    return dp[idx][H];
   }
   int take = INT_MIN,notTake = INT_MIN;
   if(hours[idx]<=H){
    take = p[idx]+foo(p,n,hours,idx-1,H-hours[idx],dp);
   }
    notTake = foo(p,n,hours,idx-1,H,dp);
    return dp[idx][H] = max(notTake,take);
   }
  

int main(){
    int n,H;
    scanf("%d %d",&n,&H);
    int p[n];
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    int hours[n];
    for(int i=0;i<n;i++){
        scanf("%d",&hours[i]);
    }
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
        dp[i][j]=-1;
    }
}
    printf("%d",foo(p,n,hours,n-1,H,dp));






    return 0;
}