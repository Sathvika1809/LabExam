#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    //U can do many Transactions
    int profit = 0;
    if(k>=n/2){
        for(int i=1;i<n;i++){
            if(a[i]>a[i-1]){
                profit += a[i]-a[i-1];
            }
        }
        printf("%d\n",profit);
    }else{

    //K is less than n/2
    int buy[k+1];
    int sell[k+1];
    for(int i=0;i<=k;i++){
        buy[i] = INT_MIN;
    }
    for(int i=0;i<=k;i++){
        sell[i] = 0;
    }
    for(int j=0;j<n;j++){
        for(int i=1;i<=k;i++){
            buy[i] = max(buy[i],sell[i-1]-a[j]);
            sell[i] = max(sell[i],buy[i]+a[j]);
        }
    }
    printf("%d\n",sell[k]);
}
    return 0;
}