// Link - https://cses.fi/problemset/task/1650

#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout<<fixed;cout.precision(10);
#define endl "\n"
#define tc ll T; cin >> T; while(T--)
#define pb push_back
#define mod 1000000007
#define S second
#define F first
using namespace std;
typedef long long ll;
const ll N = 4e5+5;
 
ll n, t[N];
 
void build(){
    for(int i = n-1; i > 0; i--) t[i] = (t[i<<1] ^ t[i<<1|1]);
}
 
void modify(int pos, ll x){
    for(t[pos += n] = x; pos > 1; pos >>= 1) t[pos>>1] = (t[pos] ^ t[pos^1]);
}
 
ll query(int low, int high){
    ll ans = 0;
    for(low += n, high += n; low < high; low >>= 1, high >>= 1){
        if(low&1) ans = (ans ^ t[low++]);
        if(high&1) ans = (ans ^ t[--high]);
    }
    return ans;
}
 
int main() {
 
    fastio;
    int q; cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> t[i + n];
    build();
    int a, b;
    while(q--){
        cin >> a >> b; a--;
        cout << query(a, b) << endl;
    }    
 
 
    return 0;
 
}