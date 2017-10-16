/*
 * FILE: Maximum_GCD-11827.cpp
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
 *   08 Mar 2017    New             1.0          AC
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
#include <sstream>

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

int gcd(int a, int b){
    if(b) return gcd(b, a % b);
    return a;
}



//verdict WA, may have extra spaces between two integers
// int main() {
// 
//     std::ios::sync_with_stdio(false);
//     int T, arr[100], j, i, max, k;
//     char ch;
//     scanf("%d", &T);
//     while(T--){
//         j=0;
//         for(i = 0; i < 100; i++){
//             j++;
//             scanf("%d%c", &arr[i], &ch);
//             if(ch == '\n') break;
//         }
//         max = -1;
//         for(i = 0; i < j; i++){
//             for(k = i+1; k < j; k++){
//                 max = max(gcd(arr[i], arr[k]), max);
// 
//             }
//         }
//         printf("%d\n", max);
// 
//     }
// 
//     return 0;
// }




int main() {

    std::ios::sync_with_stdio(false);
    int T, arr[100], j, i, max, k;
    string str;
    cin >> T; cin.ignore();
    while(T--){
        getline(cin, str);
        istringstream iss(str);
        j = 0;
        while(iss >> arr[j++]);
        j--;
        max = -1;
        for(i = 0; i < j; i++){
            for(k = i+1; k < j; k++){
                max = max(gcd(arr[i], arr[k]), max);

            }
        }
        printf("%d\n", max);
    }
    return 0;
}


