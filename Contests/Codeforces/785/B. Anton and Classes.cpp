/*
 * FILE: B. Anton and Classes.cpp.cpp
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
#define MX 200000
typedef long long ll;
using namespace std;



void merge(int *a, int low, int high, int mid) { //used by merge_sort

    int i, j, k, c[MX];
    i = low;
    k = low;
    j = mid + 1;

    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            c[k] = a[i];
            k++;
            i++;
        }
        else {
            c[k] = a[j];
            k++;
            j++;
        }
    }

    while (i <= mid) {
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++) a[i] = c[i];
}

void merge_sort(int *a, int low, int high) { //low and high inclusive

    int mid;
    if (low < high) {
        mid=(low+high)/2;
        merge_sort(a,low,mid);
        merge_sort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
}




int main() {

    std::ios::sync_with_stdio(false);
    int n, m, cs[MX], ce[MX], ps[MX], pe[MX];
    cin >> n;
    REP(i, n){
        cin >> cs[i] >> ce[i];
    }

    cin >> m;
    REP(i, m){
        cin >> ps[i] >> pe[i];
    }
    
    merge_sort(ps, 0, m-1);
    merge_sort(pe, 0, m-1);
    merge_sort(cs, 0, n-1);
    merge_sort(ce, 0, n-1);
    int c2p = ps[m-1] - ce[0];
    int p2c = cs[n-1] - pe[0];
    if(c2p >= 0 || p2c >= 0){
        cout << max(c2p, p2c) << "\n";
    }
    else cout << "0\n";

    return 0;
}


