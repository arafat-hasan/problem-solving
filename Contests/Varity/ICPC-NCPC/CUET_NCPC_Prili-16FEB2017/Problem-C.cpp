/*
 * FILE: Problem-C.cpp
 *
 * @author: Md. Arafat Hasan Jenin <Opendoor.Arafat@gmail.com>
 *
 * LINK: https://algo.codemarshal.org/contests/cuet-ncpc-2017-preli/problems/C
 *
 * Description:
 *
 *   DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    16 FEB 2017    New             1.0
 *
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>

#define FileIn(file) freopen(file"input.txt", "r", stdin)
#define FileOut(file) freopen(file"output.txt", "w", stdout)
#define FOR(i, a, b) for (int i=a; i<=b; i++)
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) (i & -i)

#define INF 500000000
#define maxN 32001
#define PI acos(-1.0)
#define maxS 100000000
#define g1 (1+sqrt(5))/2 // for fibbonacci
#define g2 (1-sqrt(5))/2 // for fibbonacci


typedef long long ll;
using namespace std;



int main() {

    int t, c = 0, N, R, pipe[2001], ed[2001], j, l, k, i;
    char str[2001], ch;

    cin >> t;
    while(c++ < t) {
		
        cin >> N >> R;
        for( i = 0; i < N; i++)
            cin >> pipe[i];
        scanf("%*c");
        
        for(i = 0, l = 0; i < N*2; i++) {
            scanf("%c", &ch);
            if(ch!=' ' && ch != '\n') str[l++] = ch;
        }
        
        str[l] = 0;
        //   printf("#%s\n", str);
        // int len = strlen(str);
        for(i = 1, l = 0; i <= N; i++) {
            k = 1;
            if(str[i] == str[i-1]) {
                for(j = i, k = 2; j < N; j++, k++) if(str[j] != str[j+1]) break;
                i = j + 1;
            }
            //   printf("$$%d\n", k);
            ed[l++] = pipe[i-1] * k;
        }

        //   for(i = 0; i < l; i++) printf("%d %d\n", i, ed[i]);
        //   printf("##############\n");

        int count = 0;
        for(i = 0; i < l; i++) {
            count += ed[i]/(R*2);
            if(ed[i] < (R*2)) count ++;
            //	printf("#%d %d %d\n", i, ed[i], count);
            if(ed[i]%(R*2) > 0 && ed[i] > (R*2)) {
                count++;
                ed[i+1] -= R;
            }
        }
        printf("Case %d: %d\n", c, count);
    }

    return 0;
}


