#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll int mod=1000000007;
std::vector<ll int> v;
struct matrix{
	ll int v00;
	ll int v01;
	ll int v10;
	ll int v11;
};
matrix a;
matrix mul(matrix a,matrix b){
	matrix temp;
	temp.v00=((a.v00*b.v00) + (a.v01*b.v10))%mod;
	temp.v01=((a.v00*b.v01) + (a.v01*b.v11))%mod;
	temp.v10=((a.v10*b.v00) + (a.v11*b.v10))%mod;
	temp.v11=((a.v10*b.v01) + (a.v11*b.v11))%mod;
	return temp;
}
ll int nonfib(ll int n){
	//cout<<1<<endl;
	ll int gap=0;
	int i=3;
	while(true){
		gap+=(v[i]-v[i-1]-1);
		//cout<<gap<<" ";
		if(gap>n){
			gap-=(v[i]-v[i-1]-1);
		//	cout<<endl;
			return v[i-1]-(gap-n); 
		}
		else if(gap==n){
		//	cout<<endl;
			return v[i]-1;
		}
		i++;
	}
}
ll int fib(ll int n){
	n-=2;
	//cout<<2<<endl;
	matrix result;
	result.v00=1;
	result.v10=0;
	result.v01=0;
	result.v11=1;
	matrix temp=a;
	while(n>0){
		if(n%2==1)
			result=mul(result,temp);
		temp=mul(temp,temp);
		n/=2;
	}
	//cout<<result.v00<<" "<<result.v01<<endl;
	//cout<<result.v10<<" "<<result.v11<<endl;
	return (result.v01+ result.v11)%mod;
}
ll int modexp(ll int x, ll int b){
	//cout<<3<<endl;
	ll int ans=1;
	while(b>0){
		if(b%2==1)
			ans=(ans*x)%mod;
		x=(x*x)%mod;
		b/=2;
	}
	return ans;
}
int main(){
	v.push_back(0);
	v.push_back(1);
	int i=1;
	while(true){
		//cout<<i<<" ";
		v.push_back(v[i]+v[i-1]);
		i++;
		if(v[i]>900000000){
			v.pop_back();
			break;
		}
	}
	a.v00=0;
	a.v10=1;
	a.v01=1;
	a.v11=1;
	int t;
	cin>>t;
	while(t--){
		ll int n;
		cin>>n;
		ll int nonf=nonfib(n);
		ll int f=fib(n);
		ll int mode=modexp(nonf,f);
		cout<<mode<<endl;
	}
 
} 
