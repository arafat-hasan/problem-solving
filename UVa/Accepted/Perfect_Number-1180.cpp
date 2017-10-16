/*
 * FILE: Perfect_Number-1180.cpp
 *
 * @author: Md. Arafat Hasan Jenin <Opendoor.Arafat@gmail.com>
 *
 * LINK:
 *
 * Description:
 *
 * DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * -------------------------------------------------------------------
 *    22 Feb 2017    New             1.0        AC
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


/***************____________BIT_OPERATIONS____________***************/
#define bit(n) (1 << (n)) //2^n
//check ith bit of integer n, 0 or 1
#define bitchk(n, i) ((n & (1 << i))? 1 : 0)
#define bit_on(n, i) (n | (1 << i)) //set ith bit ON of the integer n
#define bit_off(n, i) (n & ~(1 << i)) //set ith bit OFF of the intger n
//toggle ith bit of integer n, set 0 if 1, set 1 if 0
#define bit_toggle(n, i) (n ^ ( 1 << i))
//set ith bit to x (x is bool, 1 or 0) of the integer n
#define bit_setx(n, x, i) (n ^ ((-x ^ n) & (1 << i)))


#define nl cout << endl;
#define lck cout << "______________" << endl;

#define INF INT_MAX
#define MAXN 32001
#define PI acos(-1.0)
#define MAXS 1000000000


typedef long long ll;
using namespace std;

int isprime(int num) {
    int i,root=sqrt(num);
    if(num<2)			return 0;
    if(num==2)			return 1;
    if(num%2==0)		return 0;

    for(i=3; i<=root; i+=2)
        if(num%i==0)	return 0;

    return 1;
}

int main() {

    int T, n, x;
    cin >> T;
    while(T--){
        cin >> n; cin.ignore();
        if(isprime(n)){
            x = pow(2, n) - 1;
            if(isprime(x)) cout << "Yes" << endl;
            else  cout << "No" << endl;
        }
        else  cout << "No" << endl;

     }
    return 0;

}




// int main() {
// 
//     int T, n;
//     scanf("%d", &T);
//     while(T--){
//         scanf("%d%*c", &n);
//         if(n == 2 || n == 3 || n == 5 || n == 7 || n == 13 || n == 17 || n == 19)
//             cout << "Yes" << endl;
//         else  cout << "No" << endl;
// 
//      }
//     return 0;
// 
// }


