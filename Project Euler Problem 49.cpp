#include <bits/stdc++.h>
using namespace std;
int prime[1000001]={0};vector <int> p;
#define gen 9999
void sieve(){
	for(int i=2;i*i<=gen;i++){
		if(prime[i]==0){
			for(int j=2*i;j<=gen;j+=i){
				prime[j]=1;
			}
		}
	}
	for(int i=1000;i<=gen;i++){
		if(prime[i]==0){
			p.push_back(i);
		}
	}
}
bool perm(int a,int b){
	int digit[10]={0},dig,digit2[10]={0};
	while(a){
		dig=a%10;
		digit[dig]++;
		a/=10;
	}
	while(b){
		dig=b%10;
		digit2[dig]++;
		b/=10;
	}
	for(int i=0;i<10;i++){
		if(digit[i]!=digit2[i]) return 0;
	}
	return 1;
}
bool bins(int a){
	int mid,hi=p.size(),lo=0;
	while(lo < hi){
		mid = lo + (hi-lo+1)/2;
		if(p[mid]>a)
	 		hi = mid-1;
		else
	        lo = mid;
    }
    if(p[lo]==a) return 1;
    return 0;
}
int main(){
	sieve();
	int n=p.size();
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(perm(p[i],p[j]) && perm(2*p[j]-p[i],p[i]) && bins(2*p[j]-p[i])){
				cout<<p[i]<<" "<<p[j]<<" "<<2*p[j]-p[i]<<endl;
			}
		}
	}
}
