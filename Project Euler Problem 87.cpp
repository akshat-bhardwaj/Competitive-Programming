#include <bits/stdc++.h>
using namespace std;
#define ll long long
int prime[10000] = {0};
vector<ll int> p;
int N;
void populate(){
	for(int i=2;i<=N;i++){
		if(prime[i]==0){
			for(int j=i*i;j<=N;j+=i){
				prime[j]=1;
			}
		}
	}
}
int main() {
	N = (int)sqrt(50000000);
	populate();
	for(int i=2;i<=N;i++){
		if(prime[i]==0){
			p.push_back(i);
		}
	}
	set<int> ans;
	int l = p.size();
	for(int i=0;i<l;i++){
		for(int j=0;j<l;j++){
			if(p[j]*p[j]*p[j] >= 50000000 ) continue;
			for(int k=0;k<l;k++){
				if(p[k]*p[k]*p[k]*p[k] >= 50000000 ) continue;
				ll val = p[i]*p[i] + p[j]*p[j]*p[j] + p[k]*p[k]*p[k]*p[k];
				if(val<=50000000){
					ans.insert(val);
				}
			}
		}
	}
	cout<<ans.size();
}
