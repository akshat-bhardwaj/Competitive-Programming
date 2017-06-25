#include <bits/stdc++.h>
using namespace std;
int prime[1000001]={0};vector <int> p;
#define gen 1000000
void sieve(){
	for(int i=2;i*i<=gen;i++){
		if(prime[i]==0){
			for(int j=2*i;j<=gen;j+=i){
				prime[j]=1;
			}
		}
	}
	for(int i=2;i<=gen;i++){
		if(prime[i]==0){
			p.push_back(i);
		}
	}
}
bool bins(int a){
	int mid,hi=p.size()-1,lo=0;
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
	int ans,max=0;
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;sum<gen && j<n;j++){
			sum+=p[j];
			if(bins(sum) && j-i+1>max){
				max=j-i+1;
				ans=sum;
			}
		}
	}
	cout<<ans<<" "<<max<<endl;
}
