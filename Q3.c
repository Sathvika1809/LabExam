#include <stdio.h>
#include <stdlib.h>
int findSubsequence(char* source,char* target,int n,int m,int dp[n+1][m+1]){
    for(int i=0;i<=n;i++){
        dp[i][0] = 1;
    }
    for(int i=1;i<=m;i++){
        dp[0][i]= 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(source[i-1]==target[j-1]){
                dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}


int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    char source[n];
    char target[m];
    scanf("%s",source);
    scanf("%s",target);
    // - No of ways to form target with source string
    //how many ways to get j letter target string of i letters of source
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=-1;
        }
    }
    printf("%d",findSubsequence(source,target,n,m,dp));


    return 0;
}