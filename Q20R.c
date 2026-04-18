#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int min(int a,int b){
    return a<b?a:b;
}
int mergestones(int* a,int n,int k){
    if((n-1)%(k-1)!=0)return -1;
    int pref[n+1];
    pref[0] = 0;
    for(int i=0;i<n;i++){
        pref[i+1] = pref[i]+a[i];
    }
    int dp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = 0;
        }
    }

    //length of subarray
    for(int len =k;len<=n;len++){
        for(int i=0;i+len<=n;i++){
            int j = len+i-1;
            dp[i][j] = INT_MAX;
            //split into two parts
            for(int mid = i;mid<j;mid+=(k-1)){
                dp[i][j] = min(dp[i][j],dp[i][mid]+dp[mid+1][j]);
            }
        
        if((len-1)%(k-1)==0){
            dp[i][j]+=pref[j+1]-pref[i];
        }
    }
}
return dp[0][n-1];
    
}


int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d\n",mergestones(a,n,k));


    return 0;
}