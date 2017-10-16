/*
 * FILE: Molar-Mass-1586.cpp
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
 *    20 Feb 2017    New             1.0
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
#include <cstdlib>

#define FileIn(file) freopen("input.txt", "r", stdin)
#define FileOut(file) freopen("output.txt", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define ROF(i, b, a) for (int i=b; i>=a; i--)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define uint64 unsigned long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1 << (n)) //2^n
#define bitchk(n, i) ((n & (1 << i))? 1 : 0) //check ith bit of integer n, 0 or 1
#define bit_on(n, i) (n | (1 << i)) //set ith bit ON of the integer n
#define bit_off(n, i) (n & ~(1 << i)) //set ith bit OFF of the intger n
#define bit_toggle(n, i) (n ^ ( 1 << i)) //toggle ith bit of integer n, set 0 if 1, set 1 if 0
#define bit_setx(n, x, i) (n ^ ((-x ^ n) & (1 << i))) //set ith bit to x (x is bool, 1 or 0) of the integer n
#define nl cout << endl;
#define lck cout << "______________" << endl

typedef long long ll;
using namespace std;

int main() {
  
    int T, k, j, i, len;
    double molar, atom;
    char str[1000], num[500];
    cin >> T;
    while(T--){
        cin >> str;
        len = strlen(str);
        molar = 0.0F;
        for(i = 0; i < len;){
            if(isalpha(str[i])){
                k = 0;
                for(j = i+1; j < len && !isalpha(str[j]); j++)
					num[k++] = str[j]; 
                num[k] = '\0';
                if(k ==0) num[0] = '1', num[1] = '\0';
                atom = atof(num);
                if(str[i] == 'C')       molar += 12.01F * atom;          
                else if(str[i] == 'H')  molar += 1.008F * atom;          
                else if(str[i] == 'O')  molar += 16.00F * atom;          
                else if(str[i] == 'N')  molar += 14.01F * atom;          
                i = j;
            }  
        }
        cout << fixed << setprecision(3);
        cout << molar << endl;
    }

    return 0;
}


