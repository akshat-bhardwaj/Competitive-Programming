#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ss second
#define ff first
#define mk make_pair
#define pp pair<int,int>
#define ppl pair<long long int,long long int>
#define vec vector<int> 
/**
int bins2(int a[],int lo,int hi){
	//finds the first true
	// F F F F "T" T T T T
	int mid;
	while(lo < hi){
		mid = lo + (hi-lo)/2;
		if(a[mid]==TRUE)
	 		hi = mid;
		else
	        lo = mid+1;
    }
    if(a[lo]==FALSE){
    	return -1;
    	//All are false
    }
    return lo;
}
ll int mod(ll int a){
	if(a<0) return -a;
	return a;
}
int prime[1000001]={0},vector <int> p;
void sieve(){
	for(int i=2;i*i<=1000000;i++){
		if(prime[i]==0){
			for(int j=2*i;j<=1000000;j+=i){
				prime[j]=1;
			}
		}
	}
	for(int i=2;i<=1000000;i++){
		if(prime[i]==0){
			p.push_back(i);
		}
	}
}
*/
int prime[1000001]={0};vector <int> p;
ll int a[1001];
void sieve(){
	for(int i=2;i*i<=1000000;i++){
		if(prime[i]==0){
			for(int j=2*i;j<=1000000;j+=i){
				prime[j]=1;
			}
		}
	}
	for(int i=2;i<=1000000;i++){
		if(prime[i]==0){
			p.push_back(i);
		}
	}
}
bool check(int x){
	int mid,lo=0,hi=p.size()-1;
	while(lo < hi){
		mid = lo + (hi-lo+1)/2;
		if(p[mid]>x)
	 		hi = mid-1;
		else
	        lo = mid;
    }
    if(p[lo]==x)
    	return 1;
    return 0;
}
int main(){
	sieve();
	for(ll int i=1;i<=1000;i++)
		a[i]=2*i*i;
	for(int i=3;i<=999999;i+=2){
		int j=0;
		while(a[j]<i){
			if(check(i-a[j]))
				break;
			j++;
		}
		if(a[j]>=i) {
			cout<<i<<endl;
			break;
		}
	}
}
