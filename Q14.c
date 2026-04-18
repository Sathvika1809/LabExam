#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
typedef long long ll;
typedef struct Point{
    ll u;
    ll v;
    int type;
}Point;
Point* pts,*temp,*stripArr;
ll minll(ll a,ll b){
    return (a<b)?a:b;
}
ll  maxll(ll a,ll b){
    return (a>b)?a:b;
}
ll absll(ll x){
    return (x<0)?-x:x;
}


long long dist(Point p1,Point p2){
    return maxll(absll(p1.u-p2.u),absll(p1.v-p2.v));
}

void swap(Point* a,Point* b){
    Point t = *a;
    *a = *b;
    *b = t;
}
void bubblesortU(Point arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j].u > arr[j+1].u ||
            (arr[j].u == arr[j+1].u && arr[j].v > arr[j+1].v)){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}
void bubblesortV(int l,int r){
    for(int i=l;i<r;i++){
        for(int j=l;j<r-(i-l);j++){
            if(pts[j].v > pts[j+1].v){
                swap(&pts[j],&pts[j+1]);
            }
        }
    }
}
void mergeByV(int l,int mid,int r){
    int i=l,j=mid+1,k=l;
    while(i<=mid && j<=r){
        if(pts[i].v <= pts[j].v){
            temp[k++] = pts[i++];
        }else{
            temp[k++] = pts[j++];
        }
    }
    while(i<=mid)temp[k++] = pts[i++];
    while(j<=r)temp[k++] = pts[j++];

    for(i=l;i<=r;i++){
        pts[i] = temp[i];
    }
}
ll solve(int l,int r){
    if(r-l<=3){
        ll ans = LLONG_MAX;
        for(int i=l;i<=r;i++){
            for(int j=i+1;j<=r;j++){
                if(pts[i].type != pts[j].type){
                    ll d = dist(pts[i],pts[j]);
                    if(d<ans)ans = d;
                }
            }
        }
        bubblesortV(l,r);
        return ans;
    }
    int mid = (l+(r-l)/2);
    ll  midU = pts[mid].u;

    ll leftAns = solve(l,mid);
    ll rightAns = solve(mid+1,r);
    ll d = minll(leftAns,rightAns);

    mergeByV(l,mid,r);
    int sz = 0;
    for(int i=l;i<=r;i++){
        if(absll(pts[i].u -midU)<d){
            stripArr[sz++] = pts[i];
        }
    }
    for(int i=0;i<sz;i++){
        for(int j=i+1;j<sz&&(stripArr[j].v - stripArr[i].v)< d && j<=i+8;j++){
            if(stripArr[i].type != stripArr[j].type){
                ll cur = dist(stripArr[i],stripArr[j]);
                if(cur<d){
                    d = cur;
                }
            }
        }
    }
    return d;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int tot = n+m;
    pts = malloc(tot*sizeof(Point));
    temp = (Point *)malloc(tot* sizeof(Point));
    stripArr = (Point *)malloc(tot * sizeof(Point));

    for(int i=0;i<n;i++){
        ll x,y;
       scanf("%lld %lld", &x, &y);
        pts[i].u = x + y;
        pts[i].v = x - y;
        pts[i].type = 0;
    }
    for(int i=n;i<tot;i++){
        ll x,y;
        scanf("%lld %lld", &x, &y);
        pts[ i].u = x + y;
        pts[ i].v = x - y;
        pts[i].type = 1;
    }
    bubblesortU(pts,tot);
    ll ans = solve(0,tot-1);
    printf("%lld",ans);
    free(pts);
    free(temp);
    free(stripArr);
    return 0;
}