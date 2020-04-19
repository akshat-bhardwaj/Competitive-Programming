#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> mat[1000001];
int mark[1000002] = {0};

void populate(){
	for(ll i=2;i<1000000;i++){
		if(mark[i]==0){
			for(ll j=i;j<=1000000;j+=i){
				mark[j]=1;
				mat[j].push_back(i);
			}
		}
	}
}

int main() {
	ll ans = 0,curr = 0;
	populate();
	for(ll i=2;i<=1000000;i++){
		curr=i;
		for(int j=0;j<mat[i].size();j++){
			curr *= (mat[i][j]-1);
			curr /= mat[i][j];
		}
		ans+=curr;
	}
	cout<<ans;
	return 0;
}
