#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define f64 double
#define ll long long
const i64 inf = 1e18;
const int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
#define all(a) a.begin(),a.end()
#define overload(_1,_2,_3,_4,name,...) name
#define _rep1(n) for(int i = 0; i < (n); i++)
#define _rep2(i,n) for(int i = 0; i < (n); i++)
#define _rep3(i,a,b) for(int i = (a); i < (b); i++)
#define _rep4(i,a,b,c) for(int i = (a); i < (b); i += (c))
#define rep(...) overload(__VA_ARGS__,_rep4,_rep3,_rep2,_rep1)(__VA_ARGS__)
#define _rrep1(n) for(int i = (n) - 1; i >= 0; i--)
#define _rrep2(i,n) for(int i = (n) - 1; i >= 0; i--)
#define _rrep3(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define _rrep4(i,a,b,c) for(int i = (b) - 1; i >= (a); i -= (c))
#define rrep(...) overload(__VA_ARGS__,_rrep4,_rrep3,_rrep2,_rrep1)(__VA_ARGS__)
template <class T> bool chmin(T& a, T b){ if(a > b){ a = b; return 1; } return 0; }
template <class T> bool chmax(T& a, T b){ if(a < b){ a = b; return 1; } return 0; }
struct Edge { int to; i64 cost; Edge(int to, i64 cost) : to(to), cost(cost) {} };
using Graph = vector<vector<Edge>>;
int main(){
    int n,k;
    ll ans = 0;
    cin >> n >> k;
    vector<ll> a(n), r(n);
    rep(n) cin >> a[i];
    ll sum = 0;
    rep(n-1){
        if(i == 0) {r[i] = 0; sum = a[0];}
        else{
            r[i] = r[i-1]; 
            sum -= a[i-1];
            if(r[i]<i) r[i] = i, sum = a[i];
            }
        while(r[i] < n - 1 && a[r[i]+1] + sum <= k){
            r[i]++;
            sum += a[r[i]];
        }
    }
    rep(n-1) ans += (r[i]-i);
    rep(n)if(a[i]<=k) ans++;//1個の場合
    cout << ans << endl;
    return 0;
}   