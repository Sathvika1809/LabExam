#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        bool ok = true;
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1]){
                ok = false;
                break;
            }
        }
        if(!ok){
            cout<< -1 <<'\n';
            continue;
        }
        reverse(a.begin(),a.end());
        for(int i=0; i<n;i++){
            if(i==n-1){
                cout<<a[i]<<'\n';
            }else{
                cout<<a[i]<<' ';
            }
        }
    }

    return 0;
}
