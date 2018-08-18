#include <iostream>
#include <vector>
using namespace std;
//
struct SCC{
	//
	int V;
	vector<int> G[100000];
	vector<int> rG[100000];
	vector<int> vs,used,cmp;
	//
	SCC(int n){
		V=n;
		used.resize(V);
		cmp.resize(V);
	}
	//
	void add_edge(int from,int to){
		G[from].push_back(to);
		rG[to].push_back(from);
	}
	//
	void DFS(int v){
		used[v]=1;
		for(int i=0;i<G[v].size();i++){
			if(used[G[v][i]]==0){
				DFS(G[v][i]);
			}
		}
		vs.push_back(v);
	}
	//
	void rDFS(int v,int k){
		used[v]=1;
		cmp[v]=k;
		for(int i=0;i<rG[v].size();i++){
			if(used[rG[v][i]]==0){
				rDFS(rG[v][i],k);
			}
		}
	}
	//
	vector<int> scc(){
		fill(used.begin(),used.end(),0);
		for(int i=0;i<V;i++){
			if(used[i]==0){
				DFS(i);
			}
		}
		int ret=0;
		fill(used.begin(),used.end(),0);
		for(int i=vs.size()-1;i>=0;i--){
			if(used[vs[i]]==0){
				rDFS(vs[i],ret++);
			}
		}
		return cmp;
	}
	//
};
//
int main(){
	int V,E;
	cin>>V>>E;
	SCC sccc(V);
	for(int i=0;i<E;i++){
		int f,t;
		cin>>f>>t;
		sccc.add_edge(f,t);
	}
	vector<int> ans=sccc.scc();
	int Q;
	cin>>Q;
	while(Q--){
		int u,v;
		cin>>u>>v;
		if(ans[u]==ans[v]){
			cout<<1<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	return 0;
}