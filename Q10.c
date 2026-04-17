#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int min(int a,int b){
    return a<b?a:b;
}

int minCuts(int* a,int n,int m,int dp[m+2][m+2]){
    for(int l=2;l<=m+1;l++){
        for(int i=0;i+l<m+2;i++){
            int j = i+l;
            dp[i][j] = INT_MAX;
        
        for(int k=i+1;k<j;k++){
            int cost = dp[i][k]+dp[k][j]+(a[j]-a[i]);
            dp[i][j] = min(dp[i][j],cost);
        }
    }
    }
    return dp[0][m+1];
}
void bubble(int* a,int n){
    for(int i=0;i<n-1;i++){
        int swapped = 0;
        for(int j=0;j<n-i-1;j++){
            if(a[j+1]<a[j]){
                int t = a[j+1];
                a[j+1]=a[j];
                a[j] = t;
                swapped = 1;
            }
        }
        if(!swapped){
            break;
        }
    }
    return;
}


int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[m+2];
    a[0] = 0;
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]);
    }
    a[m+1] = n;
    bubble(a,m+2);
    int dp[m+2][m+2];
    for(int i=0;i<m+2;i++){
        for(int j=0;j<m+2;j++){
            dp[i][j] = 0;
        }
    }
    printf("%d",minCuts(a,n,m,dp));
    
    return 0;
}