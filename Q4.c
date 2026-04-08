#include <stdio.h>
#include <stdlib.h>
int max(int a,int b){
    return a>b?a:b;
}
int solve(int* a,int l,int r){
    int prev = a[l];
    int prev1 = max(a[l],a[l+1]);
    for(int i=l+2;i<=r;i++){
        int cur = max(prev+a[i],prev1);
        prev = prev1;
        prev1 = cur;
    }
    return prev1;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    if(n==1){
        printf("%d\n",a[0]);
        return 0;
    }
    if(n==2){
        printf("%d\n",max(a[0],a[1]));
        return 0;
    }
    printf("%d\n",max(solve(a,0,n-2),solve(a,1,n-1)));
    return 0;
}