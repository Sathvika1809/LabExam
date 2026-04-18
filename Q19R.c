#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


typedef struct Node{
    int l;
    int r;
    int h;
}Node;

typedef struct Pair{
    int x;
    int h;
}Pair;

Pair* merge(Pair* left,int n1,Pair* right,int n2,int* cnt){
    Pair* res = (Pair*)malloc((n1+n2)*sizeof(Pair));
    int i=0,j=0,k=0;
    int h1=0,h2=0,prevMax = 0;
    while(i<n1 && j<n2){
        int x,currMax;
        if(left[i].x < right[j].x){
            x = left[i].x;
            h1 = left[i].h;
            i++;
        }else if(left[i].x > right[j].x){
            x = right[j].x;
            h2 = right[j].h;
            j++;
        }else{
            x = left[i].x;
            h1 = left[i].h;
            h2 = right[j].h;
            i++;
            j++;
        }
        currMax = h1>h2?h1:h2;
        if(k==0 || currMax!=prevMax){
            res[k].x = x;
            res[k].h = currMax;
            k++;
            prevMax = currMax;
        }
    }
    while(i<n1){
        if(k==0||res[k-1].h !=left[i].h){
            res[k] = left[i];
            k++;
        }
        i++;
    }
    while(j<n2){
        if(k==0||res[k-1].h != right[j].h){
            res[k] = right[j];
            k++;
        }
        j++;
    }
    *cnt = k;
    return res;
}
Pair* mergesort(Node* building,int left,int right,int* cnt){
    
    if(left==right){
        Pair* skyline = (Pair*)malloc(2*sizeof(Pair));
        skyline[0].x = building[left].l;
        skyline[0].h = building[left].h;
        skyline[1].x = building[left].r;
        skyline[1].h = 0;
        *cnt = 2;
        return skyline;
    }
    //otherwise
    int n1=0,n2=0;
    int mid = left+(right-left)/2;
    Pair* leftArr = mergesort(building,left,mid,&n1);
    Pair* rightArr = mergesort(building,mid+1,right,&n2);
    Pair* merged  = merge(leftArr,n1,rightArr,n2,cnt);
    free(leftArr);
    free(rightArr);
    return merged;
}

int main(){
    int n;
    scanf("%d",&n);
    Node* building = (Node*)malloc(n*sizeof(Node));
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&building[i].l,&building[i].r,&building[i].h);
    }
    int size = 0;
    Pair* skyline = mergesort(building,0,n-1,&size);
    
    for(int i=0;i<size;i++){
        printf("%d %d ",skyline[i].x ,skyline[i].h);
    }
    return 0;
}