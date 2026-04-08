#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int crossingSum(int* a,int left,int mid,int right){
    //How far can go from mid
    int leftMax = INT_MIN;
    int sum = 0;
    for(int i=mid;i>=left;i--){
        sum+=a[i];
        if(sum>leftMax){
            leftMax = sum;
        }
    }
    sum = 0;
    int rightMax = INT_MIN;
    for(int i=mid+1;i<=right;i++){
        sum+=a[i];
        if(sum>rightMax){
            rightMax = sum;
        }
    }
    int crosssum = leftMax+rightMax;
    return crosssum;
}
int max3(int l,int r,int m){
    int maxi = l;
    if(r>l&&r>m){
        maxi = r;
    }else if(m>l&&m>r){
        maxi = m;
    }
    return maxi;
}
int max(int a,int b){
    return a>b?a:b;
}
int maxSubArraySum(int* a,int low,int hi){

    int left = low,right = hi;
    int l,r,m;
    int maxSum  = INT_MIN;
    
    if(left == right){
        return a[left];
    }
    if(left<right){
        int mid = left+(right-left)/2;
        l = maxSubArraySum(a,left,mid);
        r = maxSubArraySum(a,mid+1,right);
        m = crossingSum(a,left,mid,right);
        int maxi= max3(l,r,m);
        maxSum = max(maxSum,maxi);
    }
    return maxSum;
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("%d\n",maxSubArraySum(a,0,n-1));

    return 0;
}