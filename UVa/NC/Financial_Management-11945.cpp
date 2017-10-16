/*
 * FILE: Financial_Management-11945.cpp
 *
 * @author: Md. Arafat Hasan Jenin <opendoor.Arafat[at]gmail[dot]com>
 *
 * LINK: https://uva.onlinejudge.org/external/119/11945.pdf
 *
 * Description:
 *
 * DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    17 Mar 2017    New             1.0        AC
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
#define max(a, b)  (a < b ? b : a)
#define min(a, b)  (a > b ? b : a)


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

int main() {

    std::ios::sync_with_stdio(false);
    int T, cs = 0;
    double ac, sum, num;
    ll avg, en;
    cin >> T;
    while(T--){
        sum = 0;
        REP(i, 12) cin >> ac, sum += ac;
        sum /= 12.00;
        avg = sum;
        en = avg % 1000;
        avg /= 1000;
        num = sum - ll (sum);
        cout << ++cs << " $";
        if( avg > 0 ) cout << avg << ",";
//         cout << fixed << setprecision(2);
        cout << en + sum << "\n";
    }

    return 0;
}

// int main(){
//     int i , test , cs = 1 ;
//     scanf("%d",&test);
//     while(test--){
//         double x , sum = 0 , num ;
//         for(i = 0 ; i < 12 ; i++ ){
//             scanf("%lf",&x);
//             sum += x ;
//         }
//         sum /= 12.00 ;
//         ll avg = sum ;
//         ll en = avg % 1000 ;
//         avg /= 1000 ;
//         num = sum - ll( sum ) ;
//         printf("%d $",cs++);
//         if( avg > 0 ) printf("%lld,",avg);
//         printf("%.2lf\n",en + num );
//     }
// }
