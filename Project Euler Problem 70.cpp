#include <bits/stdc++.h>
using namespace std;
#define ll long long

int mark[10000002] = {0};
ll totient[10000002] = {0};

void populate(){
	for(int i=2;i<=10000000;i++){
		totient[i]=i;
	}
	for(ll i=2;i<10000000;i++){
		if(mark[i]==0){
			for(ll j=i;j<=10000000;j+=i){
				mark[j]=1;
				totient[j] /= i;
				totient[j] *= i-1;
			}
		}
	}
}
int perm(ll int n){
	vector<int> a,b;
	ll tot = totient[n];
	while(n!=0){
		a.push_back(n%10);
		n/=10;
	}
	while(tot!=0){
		b.push_back(tot%10);
		tot/=10;
	}
	if(a.size() != b.size()) return 0;
	int l = a.size();
	sort(a.begin(),a.begin()+l);
	sort(b.begin(),b.begin()+l);
	for(int i=0;i<l;i++){
		if(a[i]!=b[i]) return 0;
	}
	return 1;
}
int main() {
	ll ans = 87109,curr = 0;
	populate();
	for(ll i=2;i<=10000000;i++){
		if(perm(i)==1){
			if( double(i)/double(totient[i]) < double(ans)/double(totient[ans])) 
				ans = i;
		}
	}
	cout<<ans;
	return 0;
}
