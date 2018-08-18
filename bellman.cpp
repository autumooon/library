#include <iostream>
#include <vector>
using namespace std;
//
bool negative=true;
struct edge{int from;int to;int cost;};
struct bellman{
	//
	int v,e;
	vector<edge> G;
	vector<int> D;
	//
	bellman(int n,int m){
		v=n;e=m;
		D.resize(v);
	}
	//
	void add_edge(int from,int to,int cost){
		G.push_back((edge){from,to,cost});
	}
	//
	vector<int> dist(int s){
		fill(D.begin(),D.end(),1e9+7);
		D[s]=0;
		for(int i=0;i<v;i++){
			bool f=false;
			for(int j=0;j<e;j++){
				edge &e=G[j];
				if(D[e.from]!=1e9+7&&D[e.to]>D[e.from]+e.cost){
					D[e.to]=D[e.from]+e.cost;
					f=true;
					if(i==v-1){
						negative=false;
						break;
					}
				}
			}
			if(!negative){
				break;
			}
			if(!f){
				break;
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
	bellman be(V,E);
	for(int i=0;i<E;i++){
		int s,t,d;
		cin>>s>>t>>d;
		be.add_edge(s,t,d);
	}
	vector<int> ans=be.dist(r);
	if(!negative){
		cout<<"NEGATIVE CYCLE"<<endl;
		return 0;
	}
	for(int i=0;i<V;i++){
		if(ans[i]==1e9+7){
			cout<<"INF"<<endl;
		}else{
			cout<<ans[i]<<endl;
		}
	}
	return 0;
}