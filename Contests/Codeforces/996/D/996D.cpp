/*
 * FILE: 996D.cpp
 *
 * @author: Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK: https://codeforces.com/contest/996/problem/D
 *
 * DATE CREATED: 24-06-18 23:50:02 (+06)
 * LAST MODIFIED: 25-06-18 00:19:46 (+06)
 *
 * VERDICT:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 24-06-18     1.0         Deleted code is debugged code.
 *
 *               _/  _/_/_/_/  _/      _/  _/_/_/  _/      _/
 *              _/  _/        _/_/    _/    _/    _/_/    _/
 *             _/  _/_/_/    _/  _/  _/    _/    _/  _/  _/
 *      _/    _/  _/        _/    _/_/    _/    _/    _/_/
 *       _/_/    _/_/_/_/  _/      _/  _/_/_/  _/      _/
 */

///////////////////////////////////////////////////////////////////////

#include <iostream>
#include <climits>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <utility>
#include <sstream>
#include <algorithm>
#include <stack>
#include <set>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <vector>
#include <tuple>
#include <stdint.h> //uint32_t
#include <functional>
#include <bitset>
#include <unistd.h> // unsigned int sleep(unsigned int seconds);

using namespace std;

typedef long long           ll;
typedef double              lf;
typedef long double         llf;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef vector<pii>         vpii;
typedef vector<int>         vi;
typedef vector<long long>   vl;

#define _USE_MATH_DEFINES

#define _FastIO        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define forr(i, a, b)   for (__typeof (a) i = (a); i <= (b); i++)
#define rof(i, b, a)    for (__typeof (a) i = (b); i >= (a); i--)
#define rep(i, n)       for (__typeof (n) i = 0; i < (n); i++)
#define forit(i, s)     for (__typeof ((s).end()) i = (s).begin(); i != (s).end(); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(a, val)    memset((a), (val), sizeof((a)))
#define clr(a)          memset((a), 0, sizeof((a)))
#define sz(a)           (int) a.size()

#define pb              push_back

#ifndef ONLINE_JUDGE
    #define nl              cerr << '\n'
    #define sp              cerr << ' '
    #define ckk             cerr << "###############\n"
    #define debug1(x)       cerr << #x << ": " << (x) << '\n'
    #define debug2(x, y)    cerr << #x << ": " << (x) << '\t' << #y << ": " << (y) << '\n'
    #define debug3(x, y, z) cerr << #x << ": " << (x) << '\t' << #y << ": " << (y) << '\t' << #z << ": " << (z) << '\n'
#else
    #define nl
    #define sp
    #define ckk
    #define debug1(x)
    #define debug2(x, y)
    #define debug3(x, y, z)
#endif

#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             10000007 //1e7+7

////////////////////////// START HERE //////////////////////////

int merge (int arr[], int temp[], int left, int mid, int right) {
    int i, j, k;
    int inv_count = 0;
    i = left;
    j = mid;
    k = left;

    while ( (i <= mid - 1) && (j <= right) ) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];

        } else {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

int _mergeSort (int arr[], int temp[], int left, int right) {
    int mid, inv_count = 0;

    if (right > left) {
        mid = (right + left) / 2;
        inv_count  = _mergeSort (arr, temp, left, mid);
        inv_count += _mergeSort (arr, temp, mid + 1, right);
        inv_count += merge (arr, temp, left, mid + 1, right);
    }

    return inv_count;
}

int mergeSort (int arr[], int array_size) {
    int *temp = (int *) malloc (sizeof (int) * array_size);
    return _mergeSort (arr, temp, 0, array_size - 1);
}

int main () {
    _FastIO;
    int n, arr[200];
    cin >> n;
    rep (i, 2 * n) cin >> arr[i];
    map<int, int> mp;
    int maxi = 1;

    for (int i = 0; i < n * 2; i++) {
        if (mp.find (arr[i]) == mp.end() ) {
            mp[arr[i]] = maxi;
            arr[i] = maxi;
            maxi++;

        } else {
            arr[i] = mp[arr[i]];
        }
    }

    cout << mergeSort (arr, n * 2) << endl;
    return 0;
}
