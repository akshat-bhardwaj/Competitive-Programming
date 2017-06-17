#include <iostream>
#include <cmath>
using namespace std;
int a[21];
int pal2(int n){
	int b[21]={0};
	for(int i=20;i>=0;i--){
		if(a[i]<=n){
			b[i]=1;
			n-=a[i];
		}
		if(n==0)
			break;
	}
//	for(int i=20;i>=0;i--)
//		cout<<b[i];
	//cout<<endl;
	int j=20;
	while(b[j]!=1){
		j--;
	}
	//cout<<j<<endl;
	for(int k=0;k<(j+1)/2;k++){
		if(b[k]!=b[j-k])
			return 0;
		//cout<<b[k]<<" "<<b[j-k]<<endl;
	}
	return 1;
}
int pal1(int n){
	int len=0,temp=n;
	while(temp!=0){
		temp/=10;
		len++;
	}
	int d1,d2;
	for(int i=0;i<len/2;i++){
		d1=(n/(int)pow(10,i))%10;
		d2=(n/(int)pow(10,len-i-1))%10;
		if(d1!=d2)
			return 0;
	}
	return 1;
}
int main(){
	long long int count=0;
	a[0]=1;
	for(int i=1;i<21;i++){
		a[i]=a[i-1]*2;
	}
	cout<<pal2(585)<<endl;
	for(int i=2;i<1000000;i++){
		if(pal1(i)==1 && pal2(i)==1){
			count+=i;
		}
	}
	cout<<count;
}
