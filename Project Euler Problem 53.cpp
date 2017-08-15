#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll int nc(ll int n,ll int r){
	if(r==0) return 1;
    ll int res=1;
    for(ll int i=n;i>=(n-r+1);i--){
        res*=i;
    }
    for(ll int i=1;i<=r;i++){
        res/=i;
    }
    return res;
}
int main(){
    int ans=0,count,flag=0;
    for(int i=1;i<=100;i++){
        count=0;flag=0;
        ans+=100-i;
        for(int j=0;j<=i;j++){
            if(nc(i,j)<=1000000){
                count++;
                if(j==i/2 && i%2==0){ 
                    flag=1;
                    break;
                }
                else if(j==i/2) break;
            }
            else break;
        }
        if(flag==1) ans+=(count*2-1);
        else ans+=(count*2);
    }
    cout<<10100-ans;
}
