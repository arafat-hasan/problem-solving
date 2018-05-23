/// https://toph.co/c/buet-iupc-2018/arena#!/s/127218
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define _FastIO  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MOD 1000000007

#define MAXS 100000



ll big_mod (ll base, ll power, ll mod)
{
    if (power == 0) return 1;
    else if (power % 2 == 1)
    {
        ll p1 = base % mod;
        ll p2 = (big_mod (base, power - 1, mod) ) % mod;
        return (p1 * p2) % mod;
    }
    else if (power % 2 == 0)
    {
        ll p1 = (big_mod (base, power / 2, mod) ) % mod;
        return (p1 * p1) % mod;
    }
}

int main()
{

    _FastIO;
    ll t, n, a, b, c, cs = 0;
    cin >> t;
    while(t--)
    {
        cin >> n >> a >> b >> c;
        cout << "Case " << ++cs << ": ";
        ll b_a = b - a;
        ll c_b = c - b;
        ll x = c_b - 1;
        ll tmp = (x  % MOD * (x+1) % MOD) % MOD;
        ll s = (((b_a % MOD) * (c_b % MOD) % MOD) + (tmp/2)) % MOD;
        if(s == 1){
            cout << "1\n";
        }else{
            ll ans = (big_mod(n-1, c-3, MOD) * s) % MOD;
            cout << ans << '\n';
        }
    }


    return 0;
}
