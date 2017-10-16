/*
 * FILE: Big_Number_of_Teams_will_Solve_This-11734.cpp
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
#include <string>
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

int main() {

    std::ios::sync_with_stdio(false);
    int T, cs = 0, j, team_len, judge_len;
    bool flag;
    string team, judge;
    cin >> T;
    cin.ignore();

    while(cs++ < T){
        getline(cin, team);
        getline(cin, judge);

        team_len = team.length(); 
        j = 0;
        REP(i, team_len){
            if(team[i] == ' ') continue;
            team[j++] = team[i];
        }
        team.resize(j);

        judge_len = judge.length(); 
        j = 0;
        REP(i, judge_len){
            if(judge[i] == ' ') continue;
            judge[j++] = judge[i];
        }
        judge.resize(j); 

        flag = judge == team;
        if(flag && team_len == judge_len) cout << "Case " << cs << ": Yes\n";
        else if(flag) cout << "Case " << cs << ": Output Format Error\n";
        else cout << "Case " << cs << ": Wrong Answer\n";

    }

    return 0;
}


