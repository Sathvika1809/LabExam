#include <stdio.h>
#include <stdlib.h>

int max(int a,int b){
    return a>b?a:b;
}
int findProfit(int* a,int n,int idx,int buy,int k){
    if(idx == n||k==0){
        return 0;
    }
    if(buy == 1){//buy
        return max(-a[idx]+findProfit(a,n,idx+1,0,k), findProfit(a,n,idx+1,1,k));
    }else{//sell
        return max(a[idx]+findProfit(a,n,idx+1,1,k-1),findProfit(a,n,idx+1,0,k));
    }

}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d\n",findProfit(a,n,0,1,k));

    return 0;
}