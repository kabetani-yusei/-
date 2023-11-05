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
    int n,q;
    int x[100009], y[100009];
    int a[100009], b[100009], c[100009], d[100009];
    cin >> n;
    rep(n) cin >> x[i] >> y[i];
    cin >> q;
    rep(q) cin >> a[i] >> b[i] >> c[i] >> d[i];


    int map[1509][1509] = {0};
    rep(n){
        map[x[i]][y[i]]++;
    }
    for(int i=1;i<=1501;i++){
        for(int j=1; j<=1501; j++){
            map[i][j] += map[i-1][j];
        }
    }
    for(int j=1;j<=1501;j++){
        for(int i=1; i<=1501; i++){
            map[i][j] += map[i][j-1];
        }
    }
    rep(q){
        cout << map[c[i]][d[i]] - map[c[i]][b[i]-1] - map[a[i]-1][d[i]] + map[a[i]-1][b[i]-1] << endl;
    }
    return 0;
}   