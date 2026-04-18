#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef long long ll;
typedef struct Point{
    int u;
    int v;
    int type;
}Point;

Point* pts;
Point* temp;
Point*stripArr;
ll maxll(ll a,ll b){
    return a>b?a:b;
}
ll minll(ll a,ll b){
    return a<b?a:b;
}
ll absll(ll x){
    return (x<0)?-x:x;
}
ll dist(Point p1,Point p2){
    return maxll(absll(p1.u-p2.u),absll(p1.v-p2.v));
}
void swap(Point* a,Point* b){
    Point t = *a;
    *a = *b;
    *b = t;
}
void bubbleSortU(Point arr[],int n){
    for(int i=0;i<n-1;i++){
        int swapped = 0;
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1].u < arr[j].u ||((arr[j+1].u == arr[j].u)
        &&( arr[j+1].v < arr[j].v))){
            swap(&arr[j+1],&arr[j]);
            swapped = 1;
        }
        }
        if(!swapped){
            break;
        }
    }
    return;
}

void bubbleSortV(int l,int r){
    for(int i=l;i<r-1;i++){
        int swapped = 0;
        for(int j=l;j<r-i-1;j++){
            if(pts[j].v > pts[j+1].v){
                swap(&pts[j],&pts[j+1]);
                swapped = 1;
            }
        }
        if(!swapped){
            break;
        }
    }
    return;
}
void mergeByV(int l,int mid,int r){
    if(l>=r){
        return;
    }
    
    int i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r){
        if(pts[i].v < pts[j].v){
            temp[k++] = pts[i++];
        }else{
            temp[k++] = pts[j++];
        }
    }
    while(i<=mid){
        temp[k++] = pts[i++];
    }
    while(j<=r){
        temp[k++] = pts[j++];
    }
    for(int i=l;i<=r;i++){
        pts[i] = temp[i];
    }
    return;
}

ll solve(int l,int r){
    if(r-l<=3){ //bruteforce
        ll ans = LLONG_MAX;
        for(int i=l;i<=r;i++){
            for(int j=i+1;j<=r;j++){
                if(pts[i].type!=pts[j].type){
                    ll cur = dist(pts[i],pts[j]);
                    if(cur<ans){
                        ans = cur;
                    }
                }
            }
        }
        bubbleSortV(l,r);
        return ans;
    }
    //otherwise dnc
    int mid = l+(r-l)/2;
    ll midU = pts[mid].u;
    int left = solve(l,mid);
    int right = solve(mid+1,r);
    int d = minll(left,right);
    mergeByV(l,mid,r);

    int sz = 0;
    for(int i=l;i<=r;i++){
        if(absll(pts[i].u - midU)<d){
            stripArr[sz++] = pts[i];
        }
    }

    for(int i=0;i<sz;i++){
        for(int j=i+1;j<sz&&((stripArr[j].v - stripArr[i].v)<d)&&j<=i+8;j++){
            if(stripArr[j].type!=stripArr[i].type){
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
    pts = (Point*)malloc(tot*sizeof(Point));
    temp = (Point*)malloc(tot*sizeof(Point));
    stripArr = (Point*)malloc(tot*sizeof(Point));

    for(int i=0;i<n;i++){
        ll x,y;
        scanf("%lld %lld",&x,&y);
        pts[i].u = x+y;
        pts[i].v = x-y;
        pts[i].type = 0;
    }
    for(int i=n;i<tot;i++){
        ll x,y;
        scanf("%lld %lld",&x,&y);
        pts[i].u = x+y;
        pts[i].v = x-y;
        pts[i].type = 1;
    }
    bubbleSortU(pts,tot);
    ll ans = solve(0,tot-1);
    printf("%lld",ans);
    free(pts);
    free(temp);
    free(stripArr);
    return 0;
}