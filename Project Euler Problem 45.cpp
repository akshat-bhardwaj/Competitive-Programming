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
ll int a[1000001]={0},b[1000001]={0},c[1000001]={0};
bool check(ll int x){
	int mid,hi=1000000,lo=1;
	while(lo < hi){
		mid = lo + (hi-lo+1)/2;
	//	cout<<b[mid]<<endl;
		if(b[mid]>x)
	 		hi = mid-1;
		else
	        lo = mid;
    }
    hi=1000000;int lo2=1;
	while(lo2 < hi){
		mid = lo2 + (hi-lo2+1)/2;
		if(c[mid]>x)
	 		hi = mid-1;
		else
	        lo2 = mid;
    }
    //cout<<x<<' '<<lo<<' '<<lo2<<endl;
    if(b[lo]==x && c[lo2]==x)
    	return 1;
    return 0;
}
int main(){
	for(ll int i=1;i<=1000000;i++){
		a[i]=(i*(i+1))/2;
		b[i]=(i*(3*i-1))/2;
		c[i]=i*(2*i-1);
	}
	for(int i=286;i<=1000000;i++){
		if(check(a[i])) cout<<a[i]<<endl;
	}
}
