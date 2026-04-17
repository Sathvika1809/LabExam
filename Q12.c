#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int longestSubString(char* s,int l,int r,int k){
    if(r-l+1<k){
        return 0;
    }
    int freq[26]= {0};
    for(int i=l;i<=r;i++){
        freq[s[i]-'a']++;
    }
    for(int i=l;i<=r;i++){
        if(freq[s[i]-'a']<k){
            //split around this invalid ch
            int left = longestSubString(s,l,i-1,k);
            int right = longestSubString(s,i+1,r,k);
            return left>right?left:right;
        }
    }
    //If all chars occur at least k times
    return r-l+1;
}



int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    char str[n+1];
    scanf("%s",str);

    printf("%d\n",longestSubString(str,0,n-1,k));
    return 0;
}