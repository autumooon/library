//xのn乗をmodで返す
ll pow(ll x,ll n,ll mod){
	ll res=1;
	if(n>0){
		res=pow(x,n/2,mod);
		if(n%2==0){
			(res=res*res)%=mod;
		}else{
			(res=((res*res)%mod)*x)%=mod;
		}
	}
	return res;
}
