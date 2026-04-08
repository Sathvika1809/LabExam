#include <stdio.h>
#include <stdlib.h>

void solve(char* s,char* p,int n,int m){
    int i=0,j=0;
    int star = -1,match = 0;
    while(s[i]!='\0'){
        if(s[i]==p[j]||p[j]=='?'){
            i++;
            j++;
        }else if(p[j]=='*'){
            star = j;
            match = i;
            j++;
        }else if(star!=-1){
            j = star+1;
            match++;
            i=match;
        }else{
            printf("NO\n");
            return;
        }
    }
    while(p[j]=='*'){
        j++;
    }
    if(p[j]=='\0'){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return;
}



int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    char str[n+1];
    char p[m+1];
    scanf("%s",str);
    scanf("%s",p);
    solve(str,p,n,m);
    return 0;
}