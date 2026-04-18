#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef long long ll;
typedef struct{
    ll sum0,sum1;
    ll pref0,pref1;
    ll suff0,suff1;
    ll best0,best1;
}Node;

ll max2(ll a, ll b){
    return (a>b)?a:b;
}
ll max3(ll a,ll b,ll c){
    return max2(a,max2(b,c));
}
ll max4(ll a,ll b,ll c,ll d){
    return max2(max2(a,b),max2(c,d));
}
Node make_leaf(ll x){
    Node res;
    res.sum0 = x;
    res.sum1 = x*x;

    res.pref0 = x;
    res.pref1 = x*x;

    res.suff0 = x;
    res.suff1 = x*x;

    res.best0 = x;
    res.best1 = x*x;

    return res;
}
Node merge(Node L,Node R){
    Node res;
    //Whole segment sums
    res.sum0 = L.sum0 + R.sum0;
    res.sum1 = max2(L.sum1+R.sum0,L.sum0+R.sum1);

    // Prefix
    res.pref0  = max2(L.pref0,L.sum0+R.pref0);
    res.pref1 = max3(L.pref1,
        L.sum1+R.pref0,
        L.sum0+R.pref1);

    //Suffix
    res.suff0 = max2(R.suff0,L.suff0+R.sum0);
    res.suff1 = max3(R.suff1,L.suff1+R.sum0,L.suff0+R.sum1);

    //Best SubArray
    res.best0 = max3(L.best0,
                R.best0,
            L.suff0+R.pref0);
    res.best1 = max4(L.best1,
                    R.best1,
                    L.suff1+R.pref0,
                    L.suff0+R.pref1);

    return res;
}

Node solve(ll a[],int l,int r){
    if(l==r){
        return make_leaf(a[l]);
    }
    int mid = l+(r-l)/2;
    Node left = solve(a,l,mid);
    Node right = solve(a,mid+1,r);
    return merge(left,right);
}
int main(){
    int n;
    scanf("%d",&n);
    ll a[n];
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }

    Node ans = solve(a,0,n-1);
    printf("%lld\n",ans.best1);

    return 0;
}