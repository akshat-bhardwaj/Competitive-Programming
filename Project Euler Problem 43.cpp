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
int main(){
	ll int ans=0,temp=0,x[7]={2,3,5,7,11,13,17},count,val;
	int a[10]={0,1,2,3,4,5,6,7,8,9};
	while(next_permutation(a,a+10)){
		if(a[0]=='0') continue;
		val=0;
		count=0;
		for(int i=1;i<=7;i++){
			val=a[i]*100+a[i+1]*10+a[i+2];
			if(val%x[i-1]==0)
				count++;
		}
		if(count==7){
			temp=1;
			for(int i=9;i>=0;i--){
				ans+=temp*a[i];
				temp*=10;
			}
		}
	}
	cout<<ans;
}
