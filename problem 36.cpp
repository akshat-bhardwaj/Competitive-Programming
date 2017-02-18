#include <iostream>
#include <cmath>
using namespace std;
int prime(int a){
	if(a==1)
		return 0;
	for(int i=2;i*i<=a;i++){
		if(a%i==0)
			return 0;
	}
	return 1;
}
int cp(int n){
	int len=0,temp=n;
	while(temp!=0){
		temp/=10;
		len++;
	}	
	int k;
	for(int i=0;i<len;i++){
		k=pow(10,len-1)*(k%10)+k/10;
		if(prime(k)==0)
			return 0;
	}
	return 1;
}
int main(){
//	cout<<prime(135)<<endl;
	int count=0;
	for(int i=2;i<1000000;i++){
		if(cp(i)==1){
			count++;
			cout<<i<<endl;
		}
	}
	cout<<count;
}
