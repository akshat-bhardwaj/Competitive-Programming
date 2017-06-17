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
ll int pand(ll int a,ll int b){
	ll int ans=0,boo[10]={0},tem,dig,len=0;
	for(int i=b;i>=1;i--){
		tem=i*a;
		ans+=(ll int)pow(10,len) * tem;
		while(tem>0){
			dig=tem%10;
			if(boo[dig]==1) return 0;
			boo[dig]=1;
			len++;
			tem/=10;
		}
	}
	if(boo[0]==1) return -1;
	return ans;
}	
int main(){
	ll int max=0,temp;
	for(int i=1;i<=9999;i++){
		for(int j=2;j<=9;j++){
			temp=pand(i,j);
			if(temp!=-1 && max<temp)
				max=temp;
		}
	}
	cout<<max;
}
