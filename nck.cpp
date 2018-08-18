#include <iostream>
#define ll long long
using namespace std;
//
struct nCk{
	//
	ll pow(ll x,ll n,ll mod){
		ll res=1;
		if(n>0){
			res=pow(x,n/2,mod);
			if(n%2==0){
				(res=(res*res))%=mod;
			}else{
				(res=((res*res)%mod)*x)%=mod;
			}
		}
		return res;
	}
	//
	ll inv(ll n,ll mod){
		return pow(n,mod-2,mod);
	}
	//
	ll cul(ll n,ll k,ll mod){
		ll res=1;
		for(int i=n;i>n-k;i--){
			(res*=i)%=mod;
		}
		for(int i=k;i>=1;i--){
			(res*=inv(i,mod))%=mod;
		}
		return res;
	}
	//
};
//
int main(){
	int N,K;
	cin>>N>>K;
	nCk nck;
	cout<<nck.cul(N,K,1e9+7)<<endl;
	return 0;
}