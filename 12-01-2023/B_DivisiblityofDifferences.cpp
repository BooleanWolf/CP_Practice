// time-limit: 1000
// problem-url: https://codeforces.com/contest/876/problem/B
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define iter(it,a) for(auto it=a.begin();it!=a.end();it++)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define preturn(X) cout<<X<<endl; return 0
typedef long long ll;
typedef long double ld;
const ll MOD = 1e9+7;
//cout.setf(ios::fixed); cout.precision(18)
 
 
int n,k,m;
int a[100000+10];
 
map<int,vector<int> > h; 
 
int main(){
    cin.tie(0);ios_base::sync_with_stdio(0);
    cin>>n>>k>>m;
    rep(i,0,n){
        cin>>a[i];
        h[a[i]%m].pb(i);        
    }
    iter(it,h){
        if((*it).S.size()>=k){
            cout<<"Yes"<<endl;
            rep(i,0,k){
                cout<<a[(*it).S[i]]<<" ";
            }
            cout<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}
