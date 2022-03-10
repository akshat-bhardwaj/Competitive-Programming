#include <math.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define ll long long
#define pb push_back
#define N 80
//sieve
// int p[1001]={0};
// vector<int> primes;
// void sieve(){
// 	p[2]=0;
// 	p[1]=0;
// 	for(int i=2;i<=N;i++){
// 		if(p[i]==1)
// 			continue;
// 		primes.pb(i);
// 		for(int j=i*2;j<=N;j+=i){
// 			p[j]=1;
// 		}
// 	}
// }
struct node{
	int cost;
	int x;
	int y;
};
inline bool operator<(const node& lhs, const node& rhs)
{
    return lhs.cost < rhs.cost;
}
inline bool operator>(const node& lhs, const node& rhs)
{
    return lhs.cost > rhs.cost;
}
int main() {
	ifstream cin; 
 	cin.open("input.txt"); 
 	priority_queue<node, vector<node>, greater<node> > dj; 
	int a[N][N];
	int ans[N][N];
	int done[N][N];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>a[i][j];
			ans[i][j]=0;
			done[i][j]=0;
		}
	}
	ans[0][0]=a[0][0];
	node st;
	st.cost=a[0][0];
	st.x=0;
	st.y=0;
	dj.push(st);
	done[0][0]=1;
	while(dj.size()){
		node head=dj.top();
		node temp;
		dj.pop();
		ans[head.x][head.y]=head.cost;
		if(head.x-1>=0 && !done[head.x-1][head.y]){
			temp.cost=head.cost + a[head.x-1][head.y];
			temp.x=head.x-1;
			temp.y=head.y;
			dj.push(temp);
			done[head.x-1][head.y]=1;
		}
		if(head.x+1<N && !done[head.x+1][head.y]){
			temp.cost=head.cost + a[head.x+1][head.y];
			temp.x=head.x+1;
			temp.y=head.y;
			dj.push(temp);
			done[head.x+1][head.y]=1;
		}
		if(head.y-1>=0 && !done[head.x][head.y-1]){
			temp.cost=head.cost + a[head.x][head.y-1];
			temp.x=head.x;
			temp.y=head.y-1;
			dj.push(temp);
			done[head.x][head.y-1]=1;
		}
		if(head.y+1<N && !done[head.x][head.y+1]){
			temp.cost=head.cost + a[head.x][head.y+1];
			temp.x=head.x;
			temp.y=head.y+1;
			dj.push(temp);
			done[head.x][head.y+1]=1;
		}
	}
	cout<<ans[N-1][N-1]<<endl;
}
