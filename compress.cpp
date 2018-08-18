#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//
int n;
vector<int> px,py,qx,qy;
int dp[8000][8000];
struct vevev{
	vector<int> a;vector<int> b;vector<int> ab;
};
vevev compress(vector<int> x1,vector<int> x2){
	vector<int> xs;
	for(int i=0;i<n;i++){
		for(int j=0;j<=1;j++){
			xs.push_back(x1[i]+j);
			xs.push_back(x2[i]+j);
		}
	}
	xs.push_back(1e9+7);
	sort(xs.begin(),xs.end());
	xs.erase(unique(xs.begin(),xs.end()),xs.end());
	for(int i=0;i<n;i++){
		x1[i]=lower_bound(xs.begin(),xs.end(),x1[i])-xs.begin();
		x2[i]=lower_bound(xs.begin(),xs.end(),x2[i])-xs.begin();
	}
	vevev v;
	v.a=x1;v.b=x2;v.ab=xs;
	return v;
}
//
int main(){
	cin>>n;
	px.resize(n);
	py.resize(n);
	qx.resize(n);
	qy.resize(n);
	for(int i=0;i<n;i++){
		cin>>px[i]>>py[i]>>qx[i]>>qy[i];
	}
	vevev x=compress(px,qx);
	vevev y=compress(py,qy);
	px=x.a;qx=x.b;vector<int> X=x.ab;
	py=y.a;qy=y.b;vector<int> Y=y.ab;
	for(int i=0;i<n;i++){
		dp[px[i]][py[i]]++;
		dp[qx[i]][qy[i]]++;
		dp[px[i]][qy[i]]--;
		dp[qx[i]][py[i]]--;
	}
	for(int i=0;i<X.size()-1;i++){
		for(int j=1;j<Y.size()-1;j++){
			dp[i][j]+=dp[i][j-1];
		}
	}
	for(int i=0;i<Y.size()-1;i++){
		for(int j=1;j<X.size()-1;j++){
			dp[j][i]+=dp[j-1][i];
		}
	}
	int ans=0;
	for(int i=0;i<X.size()-1;i++){
		for(int j=0;j<Y.size()-1;j++){
			if(dp[i][j]){
				ans+=(X[i+1]-X[i])*(Y[j+1]-Y[j]);
			}
		}
	}
	cout<<ans<<endl;
}