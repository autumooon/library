#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//
struct edge{
	int from;int to;int cost;
	bool operator<(const edge&R)const{
		return cost<R.cost;
	}
};
struct kruskal{
	//
	int v,e;
	vector<int> par,ran;
	//
	kruskal(int n,int m){
		v=n;e=m;
		init(v);
	}
	//
	void init(int n){
		par.resize(n);
		ran.resize(n);
		for(int i=0;i<n;i++){
			par[i]=i;
			ran[i]=0;
		}
	}
	//
	int find(int x){
		if(par[x]==x){
			return x;
		}else{
			return par[x]=find(par[x]);
		}
	}
	//
	void unite(int x,int y){
		x=find(x);
		y=find(y);
		if(x==y){
			return ;
		}
		if(ran[x]<ran[y]){
			par[x]=y;
		}else{
			par[y]=x;
			if(ran[x]==ran[y]){
				ran[x]++;
			}
		}
	}
	//
	bool same(int x,int y){
		return find(x)==find(y);
	}
	//
	int cul(vector<edge> es){
		sort(es.begin(),es.end());
		int res=0;
		for(int i=0;i<e;i++){
			edge &e=es[i];
			if(!same(e.from,e.to)){
				unite(e.from,e.to);
				res+=e.cost;
			}
		}
		return res;
	}
	//
};
//
int main(){
	int V,E;
	cin>>V>>E;
	vector<edge> G;
	for(int i=0;i<E;i++){
		int s,t,cost;
		cin>>s>>t>>cost;
		G.push_back((edge){s,t,cost});
	}
	kruskal k(V,E);
	cout<<k.cul(G)<<endl;
	return 0;
}