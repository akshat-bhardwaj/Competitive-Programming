#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a, ll b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;
    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}
bool parity(ll i, ll j){
	if(i%2==0 && j%2==0) return false;
	if(i%2==1 && j%2==1) return false;
	return true;
}
int main(){
	ll N = 1e6 + 5e5;
	ll small_N = int(sqrt(N));
	int a[N+1] = {0};
	int cnt = 0;
	
	for(ll i = small_N;i>=2;i--){
		for(ll j = 1; (2*i*(i+j)<=N) && (j<i);j++){
			if((gcd(i,j) == 1) && parity(i,j)){
				for(ll k = 2*i*(i+j);k<=N;k+=2*i*(i+j)){
					a[k]++;
				}
			}
		}
	}
	for(int i=0;i<=N;i++){
		if(a[i]==1) cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
