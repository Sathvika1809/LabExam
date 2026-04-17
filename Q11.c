#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int compute(int a,int b,char op){
    if(op=='+'){
        return a+b;
    }
    if(op=='-'){
        return a-b;
    }
    if(op=='*'){
        return a*b;
    }
    
    return 0;
}
int solve(char* str,int l,int r,int* res){
    int cnt  =0;
    int op = 0;
    for(int i=l;i<=r;i++){
        if(str[i]=='+'||str[i]=='-'||str[i]=='*'){
            op = 1;
            int left[MAX],right[MAX];
            int leftCnt = solve(str,l,i-1,left);
            int rightCnt = solve(str,i+1,r,right);

            for(int a = 0;a<leftCnt;a++){
                for(int b = 0;b<rightCnt;b++){
                    res[cnt++] = compute(left[a],right[b],str[i]);
                }
            }
        }
    }
    if(!op){
        //No operator just single digits
        res[cnt++] = str[l]-'0';
    }
    return cnt;
}

void bubble(int* a,int n){
    for(int i=0;i<n-1;i++){
        int swapped  =0;
        for(int j=0;j<n-i-1;j++){
            if(a[j+1]<a[j]){
                int t = a[j+1];
                a[j+1] = a[j];
                a[j] = t;
                swapped = 1;
            }
        }
        if(!swapped){
            break;
        }
    }
    return;
}

int main(){
    int n;
    scanf("%d",&n);
    char str[n+1];
    scanf("%s",str);
    int res[MAX];
    int cnt = solve(str,0,n-1,res);
    bubble(res,cnt);
    for(int i=0;i<cnt;i++){
        printf("%d ",res[i]);
    }
    printf("\n");

    return 0;
}