/*
 * FILE: C. Bear and Differen. Names.cpp
 *
 * @author: Md. Arafat Hasan Jenin <opendoor.Arafat[at]gmail[dot]com>
 *
 * LINK: http://codeforces.com/contest/791/problem/C
 *
 * Description:
 *
 * DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    18 Mar 2017    New             1.0        NC
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
    char note[4], nm1[] = "abc", nm2[] = "bcd", nm3[] = "cde";
    char arr1[4], arr2[4], arr3[4], arr4[4], tmp[4];
    int n, k, lst;
    cin >> n >> k;
    lst = n - k;
    cin >> note;
    if(!strcmp(note, "NO")){
        cout << nm1 << " " << nm2 << " " << nm1 << " ";
        strcpy(arr1, nm1);
        strcpy(arr2, nm2);
        strcpy(arr3, nm1);
    }
    else{
        cout << nm3 << " " << nm2 << " " << nm1 << " ";
        strcpy(arr1, nm3);
        strcpy(arr2, nm2);
        strcpy(arr3, nm1);
    }
    strcpy(arr4, nm3);

    while(lst--){
        cin >> note;
        if(!strcmp(note, "NO")){
            cout << arr2 << " ";
            strcpy(tmp, arr2);
            strcpy(arr1, arr2);
            strcpy(arr2, arr3);
            strcpy(arr3, tmp);
            if(!strcmp(arr1, nm1)){
                if(!strcmp(arr2, nm2)) strcpy(arr4, nm3);
                else strcpy(arr4, nm2);
            }
            else if(!strcmp(arr1, nm2)){
                if(!strcmp(arr2, nm1)) strcpy(arr4, nm3);
                else strcpy(arr4, nm1);
            }
            else{
                if(!strcmp(arr2, nm1)) strcpy(arr4, nm2);
                else strcpy(arr4, nm1);
            }
        }
        else{
            cout << arr4 << " ";
            strcpy(arr1, arr2);
            strcpy(arr2, arr3);
            strcpy(arr3, arr4);
            strcpy(arr4, arr1);
        }
    }
    return 0;
}


