#include <iostream>
#include <vector>
#define ll long long
using namespace std;
//
struct nCk{
	//
	vector<ll> kai;
	vector<ll> gya;
	vector<ll> nck;
	//
	nCk(int n){
		kai.resize(n+1);
		gya.resize(n+1);
		nck.resize(n+1);
	}
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
	vector<ll> cul(ll n,ll mod){
		kai[n]=n;
		for(int i=n-1;i>0;i--){
			(kai[i]=kai[i+1]*i)%=mod;
		}
		gya[1]=inv(1,mod);
		for(int i=2;i<=n;i++){
			(gya[i]=gya[i-1]*inv(i,mod))%=mod;
		}
		for(int i=1;i<=n;i++){
			(nck[i]=kai[n+1-i]*gya[i])%=mod;
		}
		nck[0]=1;
		nck[n]=1;
		return nck;
	}
	//
};
//
int main(){
	int N;
	cin>>N;
	nCk nck(N);
	vector<ll> ans=nck.cul(N,1e9+7);
	for(int i=0;i<=N;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}