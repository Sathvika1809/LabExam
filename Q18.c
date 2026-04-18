#include <stdio.h>
#include <stdlib.h>

int mergeCount(int* pref,int* temp,int l,int r,int lower,int upper){
    if(r-l<=1)return 0; //only one element

    int mid = l+(r-l)/2;
    int cnt  = 0;
    cnt+=mergeCount(pref,temp,l,mid,lower,upper);
    cnt+=mergeCount(pref,temp,mid,r,lower,upper);
    int j = mid,k = mid,t = mid;
    int idx = l;

    for(int i=l;i<mid;i++){
        while(k<r && pref[k]-pref[i] < lower)k++;
        while(j<r && pref[j]-pref[i]<=upper)j++;
        cnt+=(j-k);

        while (t < r && pref[t] < pref[i]) {
            temp[idx++] = pref[t++];
        }
        temp[idx++] = pref[i];
    }

    while (t < r) {
        temp[idx++] = pref[t++];
    }

    for (int i = l; i < r; i++) {
        pref[i] = temp[i];
    }
    return cnt;
    }

int find(int* a,int n,int lower,int upper,int* temp){
   
    int pref[n+1];
    pref[0] = 0;
    for(int i=0;i<n;i++){
        pref[i+1] = pref[i]+a[i];
    }
    
    int ans = mergeCount(pref,temp,0,n+1,lower,upper);
    return ans;

}
int main(){
    int n,lower,upper;
    scanf("%d %d %d",&n,&lower,&upper);
    int a[n];
    for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    }
    int temp[n+1];
    int ans = find(a,n,lower,upper,temp);
    printf("%d\n",ans);

    return 0;
}