/*
 * FILE: Longest_Word-12543.cpp
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
 *    19 Feb 2017    New             1.0
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
#define REP(i, n) for (int i=0; i<n; i++)
#define Fill(ar, val) memset(ar, val, sizeof(ar))
#define uint64 unsigned long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define bit(n) (1<<(n))
#define Last(i) (i & -i)
#define nl cout << endl
#define INF 500000000

typedef long long ll;
using namespace std;

int main() {

    int max = INT_MIN, len;
    bool flag;
    char str[10000], ans[5000];
    while(1){

        cin >> str;
		if(!strcmp(str, "E-N-D")) break;
        len = strlen(str);

        do{
            if(!isalpha(str[len - 1]) && str[len - 1] != '-'){
                len--;
                str[len] = '\0';
            }
        }while(!isalpha(str[len - 1]) && len > 0 && str[len - 1] != '-');

        do if(!isalpha(str[0]) && str[0] != '-') strcpy(str, str+1);
        while(!isalpha(str[0]) && len > 0 && str[0] != '-');
       
       len = strlen(str);
        flag = true;
        REP(i, len){
            if(isalpha(str[i])){
                flag = false;
                break;
            }    
        }

        if(flag) continue;

        if(max < len){
            max = len;
            strcpy(ans, str);
        }
    }
    
    REP(i, max) printf("%c", tolower(ans[i]));
    nl;
    return 0;
}
