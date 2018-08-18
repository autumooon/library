#include <iostream>
using namespace std;
//
//n以下の自然数のうちnと互いに素な数の個数(1も)
struct eulerphi{
	int cul(int n){
		if(n==0){
			return 0;
		}
		int ans=n;
		for(int i=2;i*i<=n;i++){
			if(n%i==0){
				ans-=ans/i;
				while(n%i==0){
					n/=i;
				}
			}
		}
		if(n>1){
			ans-=ans/n;
		}
		return ans;
	}
};
//
int main(){
	int N;
	cin>>N;
	eulerphi e;
	cout<<e.cul(N)<<endl;
	return 0;
}