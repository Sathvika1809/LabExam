#include <stdio.h>
#include <stdlib.h>
void swap(int* a,int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void merge(int* arr,int l,int m,int r,int k,int* ans){

    //count rev pairs
    int p = m+1;
    for(int i=l;i<=m;i++){
        while(p<=r && (long long)arr[i]>k*(long long)arr[p]){
            p++;
        }
        *ans +=(p-(m+1));
    }

    int L[m-l+1];
    int R[r-m];
    for(int i=0;i<(m-l+1);i++){
        L[i] = arr[i+l];
    }
    for(int i=0;i<(r-m);i++){
        R[i] = arr[i+m+1];
    }
    int i=0,j=0,p=l;
    while(i<m-l+1&&j<r-m){
        if(L[i]>R[j]){
            arr[p++] = R[j++];
        }else{
             arr[p++]=L[i++];
        }
    }
    while(i<m-l+1){
        arr[p++]=L[i++];
    }
    while(j<r-m){
        arr[p++]=R[j++];
    }
    return;
}

void mergesort(int* a,int l,int r,int k,int* ans){
    if(l<r){
        int mid = l+(r-l)/2;
        mergesort(a,l,mid,k,ans);
        mergesort(a,mid+1,r,k,ans);
        merge(a,l,mid,r,k,ans);
    }
    return;
}



void mergesortHelper(int* a,int n,int k,int* ans){
    mergesort(a,0,n-1,k,ans);
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int ans = 0;
    mergesortHelper(a,n,k,&ans);
    printf("%d\n",ans);
    return 0;
}