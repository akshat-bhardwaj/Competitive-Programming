//Akshat_Bhardwaj
//IIT Roorkee
#include <bits/stdc++.h>
using namespace std;
void build_tree(pair<int,int> tree[],int l,int r,int index,int a[]){
	//cout<<l<<" "<<r<<" index "<<index<<endl;//" "<<tree[index].first<<endl;
	if(l==r){
		tree[index].first=a[l];
		tree[index].second=1;
		return;
	}
	int mid=(l+r)/2;
	build_tree(tree,l,mid,2*index,a);
	build_tree(tree,mid+1,r,2*index+1,a);
	if(tree[2*index].first==tree[2*index+1].first){
		tree[index].first=tree[2*index].first;
		tree[index].second=tree[2*index].second+tree[2*index+1].second;
	}
	else if(tree[2*index].second>tree[2*index+1].second){
		tree[index].first=tree[2*index].first;
		tree[index].second=tree[2*index].second-tree[2*index+1].second;	
	}
	else{
		tree[index].first=tree[2*index+1].first;
		tree[index].second=tree[2*index+1].second-tree[2*index].second;	
	}
}
pair<int,int> query(int l,int r,pair<int,int> tree[],int left,int right,int index){
	//cout<<left<<" "<<right<<" "<<index<<" "<<tree[index].first<<" second: "<<tree[index].second<<endl;
	if(l==left && r==right)
		return tree[index];
	int mid=(left+right)/2;
	if(l>mid){
		return query(l,r,tree,mid+1,right,2*index+1);
	}
	if(r<=mid){
		return query(l,r,tree,left,mid,2*index);
	}
	pair<int,int> left_res=query(l,mid,tree,left,mid,2*index);
	pair<int,int> right_res=query(mid+1,r,tree,mid+1,right,2*index+1);
	pair<int,int> res;
	if(left_res.first==right_res.first){
		res.first=left_res.first;
		res.second=left_res.second+right_res.second;
	}
	else if(left_res.second>right_res.second){
		res.first=left_res.first;
		res.second=left_res.second - right_res.second;	
	}
	else{
		res.first=right_res.first;
		res.second=right_res.second-left_res.second;	
	}
	return res;
	return make_pair(1,2);
}
int bin1(vector <int> v[],int cand,int val){
	int l=0;
	int r=v[cand].size()-1;int mid;
	while(l<r){
		mid=(l+r)/2;
		if(v[cand][mid]==val)
			return mid;
		if(v[cand][mid]>val){
			r=mid-1;
		}
		else
			l=mid+1;
		mid=(l+r)/2;
	}
	if(v[cand][mid]>val) mid--;
	return mid;
}
int size(int N) {
	int size = 1;
	for (; size < N; size <<= 1);
  	return size << 1;
}
pair<int,int> tree[1000001];
int a[600001]={0};
vector<int> v[200001];
int main(){
	int n,c;
	cin>>n>>c;
	pair<int,int> tree[size(n)+1];
	int a[n+1]={0};
	vector<int> v[c+1];
	for(int i=0;i<n;i++){
		cin>>a[i];
		v[a[i]].push_back(i+1);
	}
	build_tree(tree,0,n-1,1,a);
	cout<<endl;
	int q,l,r;pair <int,int> cand;
	cin>>q;
	while(q--){
		l=0;r=0;cand.first=0;cand.second=0;
		cin>>l>>r;
		cand=query(l-1,r-1,tree,0,n-1,1);
		int left = bin1(v,cand.first,l);
		int right = bin1(v,cand.first,r);
		if(v[cand.first][left]>=l) left--;
		//for(int i=0;i<v[cand.first].size();i++) cout<<v[cand.first][i]<<" ";
		//cout<<endl;
		//cout<<v[cand.first][left]<<endl;
		//cout<<left<<" "<<right<<endl;
		if(right-left>(r-l+1)/2.0) cout<<"yes "<<cand.first<<endl;
		else cout<<"no"<<endl;
	}
}
