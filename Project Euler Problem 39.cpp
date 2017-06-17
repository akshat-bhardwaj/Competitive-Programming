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
int main(){
	int n=500,a[n+1]={0},sum[1001]={0},max=0,ans;
	for(int i=1;i<=n;i++){
		a[i]=i*i;
	}
	for(int i=n;i>=3;i--){
		int l=1,r=i-1;
		while(l<r){
			//cout<<a[i]<<" "<<a[l]<<" "<<a[r]<<endl;
			if(a[i]==a[l]+a[r]){
				if(l+r+i<=1000)	
					sum[i+l+r]++;
				//cout<<i<<" "<<l<<" "<<r<<endl;
				l++;
			}
			else if(a[i]>a[l]+a[r])
				l++;
			else r--;
		}
	}
	for(int i=1;i<=1000;i++){
		if(max<sum[i]){
			max=sum[i];
			ans=i;
		}
	}
	cout<<ans<<endl;
}
