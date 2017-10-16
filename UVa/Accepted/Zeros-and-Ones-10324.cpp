/*
 * FILE: Zeros-and-Ones-10324.cpp
 *
 * @author: Md. Arafat Hasan Jenin <opendoor.Arafat<at>gmail<dot>com>
 *
 * LINK: https://uva.onlinejudge.org/external/103/10324.pdf
 *
 * Description:
 *
 * DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    01 Mar 2017    New             1.0        AC
 *    03 Mar 2017    New             1.1        AC
 *    04 Mar 2017    New             1.2        AC
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


#define nl cout << endl;
#define lck cout << "#############" << endl;

typedef long long ll;
using namespace std;



void swap(int *x, int *y) {
    // Code to swap 'x' and 'y'
    *x = *x * *y; // x now becomes 15
    *y = *x / *y; // y becomes 10
    *x = *x / *y; // x becomes 5
}

// 
// ver 1.0
// int main() {
// 
//     char str[1000001];
//     int i, j, k, T = 0, n;
//     while(cin >> str){
//         if(str[0] == '\n') return 0;    
//         cout << "Case " << ++T << ":" << endl;
//         cin >> n;
//         while(n--){
//             cin >> i >> j;
//             if(i > j) swap(i, j);
//             for(k = i+1; k <= j; k++){
//                 if(str[i] != str[k]) {
//                     break;
//                 }
//             }
//             if(k-1!=j) cout << "No" << endl;
//             else cout << "Yes" << endl;
// 
//         }
//     } 
//     return 0;
// }
// 
// 


//ver 1.1
// int main(){
// 
//     std::ios::sync_with_stdio(false);
//     int T=0, n, i, j, arr[1005000];
//     char ch;
//     while(scanf(" %c", &ch)==1){
//         if(ch == '\n' || ch == '\0') break;
//         i = 2;
//         arr[0] = 0; arr[1] = ch - '0';
//         while(scanf("%c", &ch)==1){
//             if(ch == '\n' || ch == '\0') break;
//             arr[i] = arr[i-1] + ch - '0';
//             i++;
//         }
//         if(scanf("%d", &n)==1)
//             printf("Case %d:\n", ++T);
// 
//         while(n-- && scanf("%d %d", &i, &j) ==2){
//             if(i > j) swap(i, j);
//             if(arr[i] + 1 == arr[i+1]){
//                 printf("%s\n", (arr[i+1] + j-i == arr[j+1])? "Yes" : "No");
//             }
//             else 
//                 printf("%s\n", (arr[i+1] == arr[j+1])? "Yes" : "No");
//         }
//     }
//     return 0;
// }



//ver 1.2
int main(){

    std::ios::sync_with_stdio(false);
    int T=0, n, i, j, arr[1005000], len;
    string str;
    while(getline(cin, str)){
        if(str[0] == '\n' || str[0] == '\0') break;
        cin >> n;
        cout << "Case " << ++T << ":\n";
        len = str.length(); i = 1;
        len--;
        arr[0] = str[0]-'0';
        while(len--){
            arr[i] = arr[i-1] + str[i] - '0';
            i++;
        }
        while(n--){
            cin >> i >> j;
            if(i > j) swap(i, j);
            if(str[i] == '1') cout << ((arr[i] + j-i == arr[j])? "Yes\n" : "No\n");
            else cout << ((arr[i] == arr[j])? "Yes\n" : "No\n");
        }
        cin.ignore();
    }
    return 0;
}



