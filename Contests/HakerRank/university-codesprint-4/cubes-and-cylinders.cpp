/*
 * FILE: cubes-and-cylinders.cpp
 *
 * @author: Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 23-02-18 23:56:27 (+06)
 * LAST MODIFIED: __last_modified
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------------
 * 23-02-18     1.0         {{File Created}}
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
#include <queue>
#include <deque>
#include <vector>
#include <tuple>
#include <stdint.h> //uint32_t
#include <functional>
#include <bitset>

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

#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define forr(i, a, b)   for (__typeof (a) i = (a); i <= (b); i++)
#define rof(i, b, a)    for (__typeof (a) i = (b); i >= (a); i--)
#define rep(i, n)       for (__typeof (n) i = 0; i < (n); i++)
#define forit(i, s)     for (__typeof ((s).end()) i = (s).begin(); i != (s).end(); ++i)
#define all(ar)         ar.begin(), ar.end()
#define fill(ar, val)   memset((ar), (val), sizeof((ar)))
#define clr(a)          memset((a), 0, sizeof((a)))
#define sz(a)           (int) a.size()

#define pb              push_back

#ifndef ONLINE_JUDGE
    #define nl              cerr << '\n';
    #define sp              cerr << ' ';
    #define ckk             cerr << "###############\n"
    #define debug1(x)       cerr << #x << ": " << (x) << endl
    #define debug2(x, y)    cerr << #x << ": " << (x) << '\t' << #y << ": " << (y) << endl
    #define debug3(x, y, z) cerr << #x << ": " << (x) << '\t' << #y << ": " << (y) << '\t' << #z << ": " << (z) << endl
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

 
char* readline();
char** split_string(char*);


/*
 * Complete the function below.
 */
int maximumPackages(int S_size, int* S, int K_size, int* K, int R_size, int* R, int C_size, int* C) {
    // Return the maximum number of packages that can be put in the containers.


}


int main()
{
    FILE *f = fopen(getenv("OUTPUT_PATH"), "w");

    char** nm = split_string(readline());

    char* n_endptr;
    char* n_str = nm[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }
    char* m_endptr;
    char* m_str = nm[1];
    int m = strtol(m_str, &m_endptr, 10);

    if (m_endptr == m_str || *m_endptr != '\0') { exit(EXIT_FAILURE); }

    char* S_size_endptr;
    char* S_size_str = readline();
    int S_size = strtol(S_size_str, &S_size_endptr, 10);

    if (S_size_endptr == S_size_str || *S_size_endptr != '\0') { exit(EXIT_FAILURE); }

    char** S_str = split_string(readline());

    int S[S_size];
    for (int S_i = 0; S_i < S_size; S_i++) {
        char* S_item_endptr;
        char* S_item_str = S_str[S_i];
        int S_item = strtol(S_item_str, &S_item_endptr, 10);

        if (S_item_endptr == S_item_str || *S_item_endptr != '\0') { exit(EXIT_FAILURE); }

        S[S_i] = S_item;
    }

    char* K_size_endptr;
    char* K_size_str = readline();
    int K_size = strtol(K_size_str, &K_size_endptr, 10);

    if (K_size_endptr == K_size_str || *K_size_endptr != '\0') { exit(EXIT_FAILURE); }

    char** K_str = split_string(readline());

    int K[K_size];
    for (int K_i = 0; K_i < K_size; K_i++) {
        char* K_item_endptr;
        char* K_item_str = K_str[K_i];
        int K_item = strtol(K_item_str, &K_item_endptr, 10);

        if (K_item_endptr == K_item_str || *K_item_endptr != '\0') { exit(EXIT_FAILURE); }

        K[K_i] = K_item;
    }

    char* R_size_endptr;
    char* R_size_str = readline();
    int R_size = strtol(R_size_str, &R_size_endptr, 10);

    if (R_size_endptr == R_size_str || *R_size_endptr != '\0') { exit(EXIT_FAILURE); }

    char** R_str = split_string(readline());

    int R[R_size];
    for (int R_i = 0; R_i < R_size; R_i++) {
        char* R_item_endptr;
        char* R_item_str = R_str[R_i];
        int R_item = strtol(R_item_str, &R_item_endptr, 10);

        if (R_item_endptr == R_item_str || *R_item_endptr != '\0') { exit(EXIT_FAILURE); }

        R[R_i] = R_item;
    }

    char* C_size_endptr;
    char* C_size_str = readline();
    int C_size = strtol(C_size_str, &C_size_endptr, 10);

    if (C_size_endptr == C_size_str || *C_size_endptr != '\0') { exit(EXIT_FAILURE); }

    char** C_str = split_string(readline());

    int C[C_size];
    for (int C_i = 0; C_i < C_size; C_i++) {
        char* C_item_endptr;
        char* C_item_str = C_str[C_i];
        int C_item = strtol(C_item_str, &C_item_endptr, 10);

        if (C_item_endptr == C_item_str || *C_item_endptr != '\0') { exit(EXIT_FAILURE); }

        C[C_i] = C_item;
    }

    int result = maximumPackages(S_size, S, K_size, K, R_size, R, C_size, C);

    fprintf(f, "%d\n", result);


    fclose(f);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}


