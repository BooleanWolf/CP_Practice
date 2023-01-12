// time-limit: 2000
// problem-url: https://codeforces.com/problemset/problem/1537/C
#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define loop(x,n) for(int x = 0; x < n; ++x)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define iter(it,a) for(auto it=a.begin();it!=a.end();it++)

bool custom_sort(pair<double, int> a, pair<double, int> b){
    if(a.first==b.first){
        return a.second < b.second;
    }
    else {
        return a.first > b.first;
    }
}


const int MAX_N = 2e9;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
    ll n;
    cin >> n;
    vector<ll> h(n);
    loop(i, n){
        cin >> h[i];
    }
    sort(h.begin(), h.end());


    ll min = MAX_N, ind = 0;

    loop(i, n-1){
        
        ll diff = h[i+1] - h[i];
        if(diff < min){
            min = diff;
            ind = i;
        } 
    } 

    
    vector<ll> small, big;

    loop(i, n){
        if(i==ind or i==ind+1) continue;

        if(h[i] > h[ind]) big.push_back(h[i]); 
    }
    loop(i, n){
        if(i==ind or i==ind+1) continue;

        if(h[i] <= h[ind+1]) small.push_back(h[i]); 
    }

    cout << h[ind] << " ";
    for(auto i : big) cout << i << " ";
    for(auto i : small) cout << i << " ";
    cout << h[ind+1] << endl;




}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }

    return 0;
}