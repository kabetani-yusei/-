#include <bits/stdc++.h>
using namespace std;
#define i64 int64_t
#define f64 double
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
    int n,d;
    int a[100009], l[100009], r[100009];
    int max1[100009] = {0}, max2[100009] = {0};
    cin >> n;
    rep(i,1,n+1) cin >> a[i];
    cin >> d;
    rep(d) cin >> l[i] >> r[i];
    rep(i,1,n+1) max1[i] = max(max1[i - 1], a[i]);
    for(int i = n; i >= 1; i--) max2[i] = max(max2[i+1], a[i]);
    rep(d){
        cout << max(max1[l[i]-1], max2[r[i]+1]) << endl;
    }
    return 0;
}   