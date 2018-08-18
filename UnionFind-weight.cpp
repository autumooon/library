#include <iostream>
#include <vector>
using namespace std;
//
struct WeightUnionFind{
	//
	vector<int> ran,par,wei;
	//
	WeightUnionFind(int n){
		init(n);
	}
	//
	void init(int n){
		par.resize(n);
		ran.resize(n,0);
		wei.resize(n,0);
		for(int i=0;i<n;i++){
			par[i]=i;
		}
	}
	//
	int find(int x){
		if(par[x]==x){
			return x;
		}else{
			int r=find(par[x]);
			wei[x]+=wei[par[x]];
			return par[x]=r;
		}
	}
	//
	int weight(int x){
		find(x);
		return wei[x];
	}
	//
	bool same(int x,int y){
		return find(x)==find(y);
	}
	//
	bool unite(int x,int y,int w){
		w+=weight(x);
		w-=weight(y);
		x=find(x);
		y=find(y);
		if(x==y){
			return false;
		}else if(ran[x]<ran[y]){
			swap(x,y);
			w=-w;
		}else if(ran[x]==ran[y]){
			ran[x]++;
		}
		par[y]=x;
		wei[y]=w;
		return true;
	}
	//
	int diff(int x,int y){
		return weight(y)-weight(x);
	}
	//
};
//
int main(){
	int N,Q;
	cin>>N>>Q;
	WeightUnionFind UF(N);
	while(Q--){
		int C;
		cin>>C;
		if(C==1){
			int X,Y;
			cin>>X>>Y;
			if(UF.same(X,Y)){
				cout<<UF.diff(X,Y)<<endl;
			}else{
				cout<<"?"<<endl;
			}
		}else{
			int X,Y,Z;
			cin>>X>>Y>>Z;
			UF.unite(X,Y,Z);
		}
	}
	return 0;
}