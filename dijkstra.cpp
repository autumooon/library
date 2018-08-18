#include <iostream>
#include <vector>
#include <queue>
using namespace std;
//
struct edge{int to;int cost;};
struct dijkstra{
	//
	int v;
	vector<edge> G[100000];
	vector<int> D;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
	//
	dijkstra(int n){
		D.resize(n);
	}
	//
	void add_edge(int from,int to,int cost){
		G[from].push_back((edge){to,cost});
	}
	//
	vector<int> dist(int s){
		fill(D.begin(),D.end(),1e9+7);
		D[s]=0;
		que.push(make_pair(0,s));
		while(!que.empty()){
			pair<int,int> p=que.top();que.pop();
			int vv=p.second;
			if(D[vv]<p.first){
				continue;
			}else{
				for(int i=0;i<G[vv].size();i++){
					edge &e=G[vv][i];
					if(D[e.to]>D[vv]+e.cost){
						D[e.to]=D[vv]+e.cost;
						que.push(make_pair(D[e.to],e.to));
					}
				}
			}
		}
		return D;
	}
	//
};
//
int main(){
	int V,E,r;
	cin>>V>>E>>r;
	dijkstra di(V);
	for(int i=0;i<E;i++){
		int s,t,d;
		cin>>s>>t>>d;
		di.add_edge(s,t,d);
	}
	vector<int> ans=di.dist(r);
	for(int i=0;i<V;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}