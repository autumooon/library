#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
//
struct edge{int to;int cost;};
struct dijkstra{
	//
	int v;
	vector<edge> G[100000];
	vector<int> D;
	vector<int> sub;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
	//
	dijkstra(int n){
		D.resize(n);
		sub.resize(n);
	}
	//
	void add_edge(int from,int to,int cost){
		G[from].push_back((edge){to,cost});
	}
	//
	vector<int> dist(int s){
		fill(D.begin(),D.end(),1e9+7);
		fill(sub.begin(),sub.end(),-1);
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
						sub[e.to]=vv;
					}
				}
			}
		}
		return D;
	}
	//
	vector<int> getpath(int t){
		vector<int> path;
		for(;t!=-1;t=sub[t]){
			path.push_back(t);
		}
		reverse(path.begin(),path.end());
		return path;
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
	int ma=0,mm;
	for(int i=0;i<V;i++){
		cout<<ans[i]<<endl;
		if(ma<ans[i]){
			ma=ans[i];
			mm=i;
		}
	}
	ans=di.getpath(mm);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}