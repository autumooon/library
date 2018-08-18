#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//
struct UnionFind{
	//
	vector<int> par,ran;
	//
	UnionFind(int n){
		init(n);
	}
	//
	void init(int n){
		par.resize(n);
		ran.resize(n,0);
		for(int i=0;i<n;i++){
			par[i]=i;
		}
	}
	//
	int find(int x){
		return (x==par[x]?x:par[x]=find(par[x]));
	}
	//
	bool same(int x,int y){
		return find(x)==find(y);
	}
	//
	void unite(int x,int y){
		x=find(x);
		y=find(y);
		if(x==y){
			return;
		}else{
			if(ran[x]<ran[y]){
				par[x]=y;
			}else{
				par[y]=x;
				if(ran[x]==ran[y]){
					ran[x]++;
				}
			}
		}
	}
	//
};
//
int main(){
	int N,Q;
	cin>>N>>Q;
	UnionFind UF(N);
	for(int i=0;i<Q;i++){
		int C,X,Y;
		cin>>C>>X>>Y;
		if(C==1){
			cout<<(UF.same(X,Y)?1:0)<<endl;
		}else{
			UF.unite(X,Y);
		}
	}
	return 0;
}