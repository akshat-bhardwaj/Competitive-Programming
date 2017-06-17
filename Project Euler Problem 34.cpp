#include <iostream>
using namespace std;
int func(int b,int a[]){
	int sum=0;
	while(b!=0){
		sum+=a[b%10];
		b/=10;
	}
	return sum;
}
int main(){
	long long int sum=0;
	int a[10]={1,1,2,6,24,120,760,5040,40320,362880};
	for(int i=11;i<=6*a[9];i++){
		if(func(i,a)==i){
			sum+=i;
		}
	}
	cout<<sum;
}
