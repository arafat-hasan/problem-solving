/*
 * FILE: AndOr-12898.cpp
 *
 * @author: Md. Arafat Hasan Jenin <Opendoor.Arafat@gmail.com>
 *
 * LINK:
 *
 * Description:
 * 
 * DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    ** *** 2017    New             0.0
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iomanip>

#define FileIn(file) freopen("input.txt", "r", stdin)
#define FileOut(file) freopen("output.txt", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define ROF(i, b, a) for (int i=b; i>=a; i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define uint64 unsigned long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) (i & -i)
#define bitchk(n, i) ((n&(1LL << i))? 1 : 0)
#define bit_on(n, i) (n | (1LL << i))
#define bit_off(n, i) (n & ~(1LL << i)) //set ith bit OFF of the intger n
#define nl cout << endl
#define INF 500000000



typedef long long ll;
using namespace std;

int main() {

    int T, Case = 0;
    ll n, m, or_, and_, i;
    cin >> T;
    while(Case < T && cin >> n >> m){
        or_ = n, and_ = m;
        if(n != m){
            for(i = 63; i>= 0; i--){
                if(bitchk(n, i) != bitchk(m, i)) break;     
            }
            for(; i>=0; i--){
                or_ = bit_on(or_, i);
                and_ = bit_off(and_, i);
            }
        }
        cout << "Case " << ++Case << ": " << or_ << " " << and_ << endl; 
    }

    return 0;
}

