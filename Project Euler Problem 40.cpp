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
	clock_t t;
	t=clock();
	vector<int> v;
	int ans=1,len=1,temp,i=0,j=1,t_len=0,x=10;
	v.push_back(1);
	v.push_back(10);
	v.push_back(100);
	v.push_back(1000);
	v.push_back(10000);
	v.push_back(100000);
	v.push_back(1000000);
	while(i<7){
		if(j%x==0){ 
			len++;
			x*=10;
		}
		t_len+=len;
		if(t_len==v[i]){
			ans*=(j%10);
			i++;
		}
		else if(t_len>v[i]){
			temp=j;
			temp/=(int)pow(10,t_len-v[i]);
			ans*=temp%10;
			i++;
		}
		j++;
	}
	cout<<ans<<endl;
	t=clock()-t;
	cout<<float(t)/CLOCKS_PER_SEC<<endl;
}
