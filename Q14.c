#include <stdio.h>
#include <stdlib.h>
typedef struct Point{
   int u,v;
   int type;
}Point;
int min(int a,int b){
    return a<b?a:b;
}
int cmp(Point* a,Point* b){
    if(a.u < b.u)return -1;
    if(a.u > b.u)return 1;
    if(a.v < b.v)return -1;
    if(a.v > b.v)return 1;
    return 0;
}
int findAnswer(Point* p1,int size){
    

}
void merge(int p1,int l,int mid,int r){
    int n1 = mid-l+1; int n2 = r-m;
    Point L[n1],Point R[n2];

    



}

void mergesort(Point* p1,int l,int r){
    
    if(l<r){
        int mid = l+(r-l)/2;
        mergesort(p1,l,mid);
        mergesort(p1,mid+1,r);
        merge(p1,l,mid,r);
    }
    return;

}
int cmp(Point a,Point b){
    if(a.u < b.u)return 1;
    else if(a.u == b.u && a.v < b.v){
        return 1;
    }
    return 0;
}
void merge(Point* a,int l,int mid,int r ,Point* temp){
    int i = l,j = mid+1,k=l;

    while(i<=mid && j<=r){
        if(cmp(a[i],a[j])){
            temp[k++] = a[i++];
        }else{
            temp[k++] = a[j++];
        }
    while(i<=mid)temp[k++] = a[i++];
    while(j<=r)temp[k++] = a[j++];
    for(int i=l;i<=r;i++){
        a[i] = temp[i];
    }


    }





}



void mergesort(Point* a,int l,int r,Point* temp){
    if(l>=r)return;

    int mid = l+(r-l)/2;
    mergesort(a,l,mid,temp);
    mergesort(a,mid+1,r,temp);
    merge(a,l,mid,r,temp);
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int tot = n+m;
    Point* p1 = (Point*)malloc(tot*sizeof(Point));
    Point* temp = (Point*)malloc(tot*sizeof(Point));

    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p1[i].u = x+y;
        p1[i].v = x-y;
        p1[i].type = 0;
    }
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        int u1 = x+y;
        int v1 = x-y;
        p1[n+i].u = u1;
        p1[n+i].v = v1;
        p1[n+i].type = 1;
    }
    mergesort(p1,0,tot-1,temp);

    printf("%d\n",findAnswer(p1,n+m));
    return 0;
}