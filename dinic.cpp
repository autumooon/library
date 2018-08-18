#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
//
struct edge{int to;int cap;int rev;};
struct Dinic{
	//
	int v;
	vector<edge> G[10000];
	vector<int> lel,ite;
	//
	Dinic(int n){
		v=n;
		lel.resize(v);
		ite.resize(v);
	}
	//
	void add_edge(int from,int to,int cap){
		G[from].push_back((edge){to,cap,(int)G[to].size()});
		G[to].push_back((edge){from,0,(int)G[from].size()-1});
	}
	//
	void BFS(int s){
		fill(lel.begin(),lel.end(),-1);
		queue<int> que;
		lel[s]=0;
		que.push(s);
		while(!que.empty()){
			int v=que.front();que.pop();
			for(int i=0;i<G[v].size();i++){
				edge &e=G[v][i];
				if(e.cap>0&&lel[e.to]<0){
					lel[e.to]=lel[v]+1;
					que.push(e.to);
				}
			}
		}
	}
	//
	int DFS(int v,int t,int f){
		if(v==t){
			return f;
		}
		for(int i=ite[v];i<G[v].size();i++){
			edge &e=G[v][i];
			if(e.cap>0&&lel[v]<lel[e.to]){
				int d=DFS(e.to,t,min(f,e.cap));
				if(d>0){
					e.cap-=d;
					G[e.to][e.rev].cap+=d;
					return d;
				}
			}
		}
		return 0;
	}
	//
	int max_flow(int s,int t){
		int flow=0;
		while(1){
			BFS(s);
			if(lel[t]<0){
				return flow;
			}else{
				fill(ite.begin(),ite.end(),0);
				int f;
				while((f=DFS(s,t,1e9+7))>0){
					flow+=f;
				}
			}
		}
	}
	//
};
//
int main(){
	int V,E;
	cin>>V>>E;
	Dinic DC(V);
	for(int i=0;i<E;i++){
		int s,t,c;
		cin>>s>>t>>c;
		DC.add_edge(s,t,c);
	}
	cout<<DC.max_flow(0,V-1)<<endl;
	return 0;
}