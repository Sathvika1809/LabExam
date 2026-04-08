#include <stdio.h>
#include <stdlib.h>

int min3(int a,int b,int c){
    int mini = a;
    if(b<c&&b<a){
        mini = b;
    }
    if(c<a&&c<b){
        mini = c;
    }
    return mini;
    
}

int solve(char* seq1,char* seq2,int n,int m){
    int dp[n+1][m+1]; //min no of operations to convert first i characters of seq1 to first 
    //j characters of seq2;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j]=0;
        }
    }
    for(int i=0;i<=n;i++){
        dp[i][0] = i;
    }
    for(int j=0;j<=m;j++){
        dp[0][j] = j;
    }
    //replace seq1[i-1] with seq2[j-1] dp[i-1][j-1]+1
    //delete seq1[i-1] then dp[i-1][j]+1
    //insert seq1[i-1] with seq2[j-1] then dp[i][j-1]+1
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(seq1[i-1]==seq2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = 1+min3(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    char seq1[n+1];
    char seq2[m+1];
    scanf("%s",seq1);
    scanf("%s",seq2);
    printf("%d\n",solve(seq1,seq2,n,m));
    return 0;
}