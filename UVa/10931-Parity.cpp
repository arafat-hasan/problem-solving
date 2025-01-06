/*
 * FILE: Parity-10931.cpp
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
#define bitchk(n, i) ((n&(1 << i))? 1 : 0)
#define nl cout << endl
#define INF 500000000



typedef long long ll;
using namespace std;

int main() {
    
    int n, parity, j; char B[33]; bool flag, tmp;
    while(cin >> n && n){
     
        parity = 0; j = 0; flag = false;
        ROF(i, 31, 0){
            tmp = bitchk(n, i);
            if(tmp) flag = true;
            if(!flag) continue;
            parity += tmp;
            B[j++] = tmp+48;
        }

        B[j] = '\0';
        cout << "The parity of " << B << " is " << parity << " (mod 2)."; nl;  
    }

    return 0;
}

