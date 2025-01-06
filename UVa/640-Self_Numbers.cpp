/*
 * FILE: Self_Numbers-640.cpp
 *
 * @author: Md. Arafat Hasan Jenin <opendoor.Arafat[at]gmail[dot]com>
 *
 * LINK:
 *
 * Description:
 *
 * DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    07 Mar 2017    New             1.0        AC
 *    07 Mar 2017    Eff             1.1        AC, faster
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


/*****************____________BIT_OPERATIONS____________****************/
#define bit(n) (1 << (n)) //2^n
//check ith bit of integer n, 0 or 1
#define bitchk(n, i) ((n & (1 << i))? 1 : 0)
#define bit_on(n, i) (n | (1 << i)) //set ith bit ON of the integer n
#define bit_off(n, i) (n & ~(1 << i)) //set ith bit OFF of the intger n
//toggle ith bit of integer n, set 0 if 1, set 1 if 0
#define bit_toggle(n, i) (n ^ ( 1 << i))
//set ith bit to x (x is bool, 1 or 0) of the integer n
#define bit_setx(n, x, i) (n ^ ((-x ^ n) & (1 << i)))


#define nl cout << endl
#define lck cout << "#########" << endl

typedef long long ll;
using namespace std;

int arr[1000002];

// int main() {
// 
//     std::ios::sync_with_stdio(false);
//    int sum, len;
//    char str[20];
//    FOR(i, 1, 1000002) {
//         sprintf(str, "%d", i);
//         len = strlen(str);
//         sum  = 0;
//         REP(i, len) sum += str[i] - 48;
//         arr[i+sum] = 1;
//     }
//     arr[0] = 1;
//     REP(i, 1000001) if(!arr[i]) cout << i << "\n";
// 
//     return 0;
// }
// 



// ver 1.1

int main() {

    std::ios::sync_with_stdio(false);
    int sum, tmp, n;
    FOR(i, 1, 1000002) {
        sum = 0;
        n = i;
        while(n > 0){
            tmp = n % 10;
            n /= 10;
            sum += tmp;
        }
        arr[i+sum] = 1;
    }

    arr[0] = 1;
    REP(i, 1000002) if(!arr[i]) cout << i << "\n";

    return 0;
}

