#include <stdio.h>
#include <stdlib.h>

// Here two players Alpha and beta are playing optimally
//We need to find Alpha max score
// To find Alpha max score, first player is alpha hence 
//alpha picks left or right then beta plays so he plays optimally so he would give the 
//worst case to alpha so we need to find max of that
//if l>r return 0 -not possible to play
//if l==r only one cache so alpha plays and wins


int max(int a,int b){
    return a>b?a:b;
}
int min(int a,int b){
    return a<b?a:b;
}
int findMax(int* a,int n,int l,int r,int dp[n+1][n+1]){
    if(l>r){
        return 0;
    }
    if(l==r){
        return dp[l][r] = a[l];
    }
    
    int takeleft = a[l]+min(findMax(a,n,l+2,r,dp),findMax(a,n,l+1,r-1,dp));
    int takeright = a[r]+min(findMax(a,n,l+1,r-1,dp),findMax(a,n,l,r-2,dp));
     return dp[l][r] = max(takeleft,takeright);

}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            dp[i][j] = 0;
        }
    }
    printf("%d",findMax(a,n,0,n-1,dp));



    return 0;
}