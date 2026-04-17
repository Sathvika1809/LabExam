#include <stdio.h>
#include <stdlib.h>

int findCrossing(int* pref,int l,int mid,int r,int lower,int upper){
    int cnt  = 0;
    int sum = pref[mid];
    for(int i=mid-1;i>=l;i++){
        if(lower<=sum+pref[i]<=upper){
            cnt++;
            sum+=pref[i];
        }
    }
    for(int i=mid+1;i<=r;i++){
        if(lower<=sum+pref[i]<=upper){
            cnt++;
            sum+=pref[i];
        }
    }
    return cnt;
}

int findPair(int* pref,int t,int lower,int upper){
    int l = 0,r=t-1;
    if(l==r && lower<=pref[l]<=upper){ //base case
        return pref[l];
    }else{
        return 0;
    }
    int leftSum=0;
    int rightSum=0;
    int crossing = 0;
    if(l<r){
        int mid = l+(r-l)/2;
        leftSum +=findPair(pref,t,lower,upper);
        rightSum +=findPair(pref,t,lower,upper);
        crossing +=findCrossing(pref,l,mid,r,lower,upper);
    }
    return 0;
}



int find(int* a,int n,int lower,int upper){
   
    int pref[n+1];
    pref[0] = 0;
    for(int i=0;i<n;i++){
        pref[i+1] = pref[i]+a[i];
    }
    return findPair(pref,n+1,lower,upper);

}
int main(){
    int n,lower,upper;
    scanf("%d %d %d",&n,&lower,&upper);
    int a[n];
    for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    }
    int cnt = 0;
    int ans = find(a,n,lower,upper);
    printf("%d\n",ans);





    return 0;
}