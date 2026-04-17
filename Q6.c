#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000
int max(int a,int b){
    return a>b?a:b;
}
int LPS(char* str,int l,int r,int n,int dp[n+1][n+1]){
    if(l>r){
        return 0;
    }
    if(l==r){
        return 1;
    }
    int ans = 0;
    if(str[l]==str[r]){ // length 2 bexause 2 characters matched and then recurse
        return dp[l][r] = 2+LPS(str,l+1,r-1,n,dp);
    }else{
        return dp[l][r]= max(LPS(str,l+1,r,n,dp), LPS(str,l,r-1,n,dp));
    }
   
}


int main(){
 
    int n;
    scanf("%d",&n);
    char str[MAX];
    scanf("%s",str);
    
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
        dp[i][j] = -1;
        }
    }
    printf("%d",LPS(str,0,n-1,n,dp));


    return 0;
}