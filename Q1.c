#include <stdio.h>
#include <stdlib.h>
const int mod = 1e9+7;

int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int grid[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&grid[i][j]);
        }
    }
    int dp[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    for(int j=1;j<n;j++){
        if(grid[0][j]==0){
            dp[0][j] = dp[0][j-1];
        }else{
            dp[0][j] = 0;
        }
    }
    for(int i=1;i<m;i++){
        if(grid[i][0]==0){
            dp[i][0] = dp[i-1][0];
        }else{
            dp[i][0] = 0;
        }
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(grid[i][j]==0){
                dp[i][j] = (dp[i-1][j]+dp[i][j-1])%mod;
            }else{
                dp[i][j]=0;
            }
        }
    }
    printf("%d\n",dp[m-1][n-1]);



    return 0;
}