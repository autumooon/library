#include <iostream>
#include <vector>
using namespace std;
//
struct segtree{
	//
	int n;
	vector<int> dat;
	//
	segtree(int n_){
		init(n_);
	}
	//
	void init(int n_){
		n=1;
		while(n<n_){
			n*=2;
		}
		dat=vector<int>(n*2-1,2147483647);
	}
	//
	void update(int k,int a){
		k+=n-1;
		dat[k]=a;
		while(k){
			k=(k-1)/2;
			dat[k]=min(dat[k*2+1],dat[k*2+2]);
		}
	}
	//[a,b)
	int query(int a,int b,int k=0,int l=0,int r=-1){
		if(r==-1){
			r=n;
		}
		if(r<=a||b<=l){
			return INT_MAX;
		}else if(a<=l&&r<=b){
			return dat[k];
		}else{
			int va=query(a,b,k*2+1,l,(l+r)/2);
			int vb=query(a,b,k*2+2,(l+r)/2,r);
			return min(va,vb);
		}
	}
	//
};
//
int main(){
	int N,Q;
	cin>>N>>Q;
	segtree seg(N);
	while(Q--){
		int C;
		cin>>C;
		if(C==1){
			int X,Y;
			cin>>X>>Y;
			cout<<seg.query(X,Y+1)<<endl;
		}else{
			int K,A;
			cin>>K>>A;
			seg.update(K,A);
		}
	}
	return 0;
}