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
int bins(int a[],int lo,int hi){
	//finds the last false
	// F F F "F" T T T T T
	int mid;
	while(lo < hi){
		mid = lo + (hi-lo+1)/2;
		if(a[mid]==TRUE)
	 		hi = mid-1;
		else
	        lo = mid;
    }
    if(a[lo]==TRUE){
    	return -1;
    	//All are true
    }
    return lo;
}
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
*/
int prime[1000001]={0};vector <ll int> p;
bool check(ll int n){
	int i=0;
	while(p[i]*p[i]<=n){
	//	cout<<1<<endl;
		if(n%p[i]==0) return 0;
		i++;
	}
	return 1;
}
int panPrime(int n){
	int a[n],val,max=0;
	for(int i=0;i<n;i++) a[i]=i+1;
	val=0;
	for(int i=n-1;i>=0;i--){ 
		val+=a[i]*pow(10,n-i-1);
	}
	if(check(val) && val>max) max=val;
	while(next_permutation(a,a+n)){
	//	cout<<1<<endl;
		val=0;
		for(int i=n-1;i>=0;i--){ 
			val+=a[i]*pow(10,n-i-1);
		}
 		if(check(val) && val>max) max=val;
	}
	return max;
}
int main(){
	int ans=0;
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
	for(int i=3;i<=9;i++){
		int temp=panPrime(i);
		if(temp>ans)
			ans=temp;
	}
	cout<<ans;
}
