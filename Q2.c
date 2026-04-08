#include <stdio.h>
#include <stdlib.h>
// U have to balance payment inc with h-h[i] not to go to 0
//U can sort na no sorting wont helpp!! sorting does take local max
// I feel like its type of Knapsack Problem
void swap(int* a,int* b){
    int t = *a;
    *a = *b;
    *b = t;
    return;
}
int max(int a,int b){
    return a>b?a:b;
}

int solve(int* p,int* hrs,int n,int h){
    int dp[n+1][h+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=h;j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }else if(hrs[i-1]<=j){
                dp[i][j] = max(dp[i-1][j],p[i-1]+dp[i-1][j-hrs[i-1]]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][h];
}
int main(){
    int n,h;
    scanf("%d %d",&n,&h);
    int p[n];
    int hrs[n];
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    for(int j=0;j<n;j++){
        scanf("%d",&hrs[j]);
    }

    printf("%d\n",solve(p,hrs,n,h));


    return 0;
}