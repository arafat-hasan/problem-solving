/*
 * FILE: The_Dragon_of_Loowater-11292.cpp
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


int binarysearch (int *array, int end,int key) {
    //array must be sorted, if key is found return 0 based index,
    //else -1;
    int start = 0, mid;
    end--;
    while (start <= end) {
        mid = (start + end) / 2;
        if (key == array[mid]) return mid;
        else if (key < array[mid]) end = mid - 1;
        else start = mid + 1;
    }
    return -1;
}


void merge(int *a, int low, int high, int mid) { //used by merge_sort

    int i, j, k, c[20001];
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
    int n, m, i, j, sum, knight_remain, head[20001], knight[20001];
    bool flag;

    while(cin >> n >> m && (n || m)){
        REP(i, n) cin >> head[i];
        REP(i, m) cin >> knight[i];

        if(n > m){
            cout << "Loowater is doomed!\n";
            continue;
        }

        merge_sort(head, 0, n-1);
        merge_sort(knight, 0, m-1);
        knight_remain = m;
        sum = 0;
        flag = true;
        for(i = 0, j = 0; i < n; i++, j++){
            if(head[i] > knight[j]){
                i--;
                knight_remain--;
                if(knight_remain < n){
                    cout << "Loowater is doomed!\n";
                    flag = false;
                    break;
                }
            }
            else sum += knight[j];
        }

        if(flag) cout << sum << "\n";
    }

    return 0;
}


