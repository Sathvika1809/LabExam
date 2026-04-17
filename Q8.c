#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int max(int a,int b){
    return a>b?a:b;
}
int bitonic(int* a,int n,int* inc,int* dec){
   //For subsequence elements need not be adjacent
   int ans = 1;
   for(int i=0;i<n;i++){
    inc[i] = 1;
    for(int j=0;j<i;j++){
        if(a[j]<a[i]){
            inc[i] = max(inc[i],inc[j]+1);
        }
    }
   }
   for(int i=n-1;i>=0;i--){
    dec[i] = 1;
    for(int j=n-1;j>i;j--){
        if(a[j]<a[i]){ //longest dec subseq
            dec[i] = max(dec[i],dec[j]+1);
        }
    }
    ans = max(ans,inc[i]+dec[i]-1);
   }
   
   return ans;
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int inc[n];
    for(int i=0;i<n;i++){
        inc[i] = 1;
    }
    int dec[n];
    for(int i=0;i<n;i++){
        dec[i] = 1;
    }
    printf("%d",bitonic(a,n,inc,dec));



    return 0;
}