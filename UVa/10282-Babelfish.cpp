/*
 * FILE: Babelfish-10282.cpp
 *
 * @author: Md. Arafat Hasan Jenin <opendoor.Arafat<at>gmail<dot>com>
 *
 * LINK:
 *
 * Description:
 *
 * DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    02  Mar 2017    New             1.0
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
#include <map>
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

int main() {

    std::ios::sync_with_stdio(false); 

    char eng[100], dlct[100], str[100], eh[] = "eh";
    std::map<std::string, std::string> dic;
    while(std::cin.getline(str, 100)){
            if(str[0] == '\0') break;
            sscanf(str, "%s %s", eng, dlct );
            dic[dlct] = eng;
    }
    while(std::cin >> dlct){
        std::cout << (dic.count(dlct)? dic[dlct] : eh)  << std::endl;
    }

    return 0;
}



