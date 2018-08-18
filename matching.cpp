#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//
struct pair_match{
	//
	int v;
	vector<int> G[100000];
	vector<int> match,used;
	//
	pair_match(int n){
		v=n;
		match.resize(v);
		used.resize(v);
	}
	//
	void add_edge(int from,int to){
		G[from].push_back(to);
		G[to].push_back(from);
	}
	//
	bool DFS(int v){
		used[v]=true;
		for(int i=0;i<G[v].size();i++){
			int u=G[v][i],w=match[u];
			if(w<0||!used[w]&&DFS(w)){
				match[v]=u;
				match[u]=v;
				return true;
			}
		}
		return false;
	}
	//
	int matching(){
		int res=0;
		fill(match.begin(),match.end(),-1);
		for(int i=0;i<v;i++){
			if(match[i]<0){
				fill(used.begin(),used.end(),0);
				if(DFS(i)){
					res++;
				}
			}
		}
		return res;
	}
	//
};
//
int main(){
	int X,Y,E;
	cin>>X>>Y>>E;
	pair_match PM(X+Y);
	for(int i=0;i<E;i++){
		int x,y;
		cin>>x>>y;
		PM.add_edge(x,X+y);
	}
	cout<<PM.matching()<<endl;
	return 0;

}