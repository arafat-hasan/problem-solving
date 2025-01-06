/*
 * FILE: Knight-MOves-439.cpp
 *
 * @author: Md. Arafat Hasan Jenin <opendoor.arafat[at]gmail[dot]com>
 *
 * LINK:
 *
 * Description:
 *
 * DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * -------------------------------------------------------------------
 *    01 Mar 2017    New             1.0        AC
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


/***************____________BIT_OPERATIONS____________***************/
#define bit(n) (1 << (n))
//check ith bit of integer n, 0 or 1
#define bitchk(n, i) ((n & (1 << i))? 1 : 0)
#define bit_on(n, i) (n | (1 << i)) //set ith bit ON of the integer n
#define bit_off(n, i) (n & ~(1 << i))//set ith bit OFF of the intger n
//toggle ith bit of integer n, set 0 if 1, set 1 if 0
#define bit_toggle(n, i) (n ^ ( 1 << i))
//set ith bit to x (x is bool, 1 or 0) of the integer n
#define bit_setx(n, x, i) (n ^ ((-x ^ n) & (1 << i)))


#define nl cout << endl;
#define chk cout << "##########" << endl;

#define INF INT_MAX
#define MAXN 32001
#define PI acos(-1.0)
#define MAXS 100000000


typedef long long ll;
using namespace std;


vector<int> adj [100]; // for BFS & bfs_vis
int cost[100]; // for BFS & bfs_vis
int visited [100]; //for bfs_vis


int bfs(int s, int d) {
    int i, cn, v, sz;
    if(s == d) return 0;
    for(i = 0; i < 64; i++)
        cost[i] = INT_MAX;

    queue<int> Q;
    Q.push(s);
    cost[s] = 0;
    while(!Q.empty()) {
        cn = Q.front();
        Q.pop();
        sz = adj[cn].size();
        for(i = 0; i < sz; i++) {
            v = adj[cn][i];
            if(cost[cn] + 1 < cost[v]) {
                Q.push(v);
                cost[v] = cost[cn] + 1;
                if(v == d) return cost[d];
            }
        }
    }

    return 0;
}


bool isvalid(int x, int y){
    if((x >= 0 && x < 8) && (y >=0 && y < 8)) return 1;
    return 0;
}


int main() {

    int i, j;
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            if(isvalid(i-2, j-1)) adj[i*8+j].push_back((i-2)*8+j-1);
            if(isvalid(i-2, j+1)) adj[i*8+j].push_back((i-2)*8+j+1);
            if(isvalid(i-1, j-2)) adj[i*8+j].push_back((i-1)*8+j-2);
            if(isvalid(i-1, j+2)) adj[i*8+j].push_back((i-1)*8+j+2);
            if(isvalid(i+1, j-2)) adj[i*8+j].push_back((i+1)*8+j-2);
            if(isvalid(i+1, j+2)) adj[i*8+j].push_back((i+1)*8+j+2);
            if(isvalid(i+2, j-1)) adj[i*8+j].push_back((i+2)*8+j-1);
            if(isvalid(i+2, j+1)) adj[i*8+j].push_back((i+2)*8+j+1);
        }
    }

//     for(i = 0; i < 4; i++){
//         sz = adj[i].size();
//         for(j = 0; j < sz; j++)
//             printf("%d ", adj[i][j]);
//         nl
//     }
//   
// 
//     for(i = 0; i < 64; i+=8){
//         for(j = 0; j < 8; j++)
//             cout << i+j << "\t" ;
//             nl nl
//   }


    char a[3], b[3];
    while(cin >> a >> b){
//         cout <<  abs((a[1]-'0'-8))*8+(a[0] - 'a') << " " << (abs(b[1]-'0'-8))*8+(b[0] - 'a')    << endl;
        cout <<  "To get from " << a << " to " << b << " takes ";
        cout << bfs(abs((a[1]-'0'-8))*8+(a[0]-'a'), (abs(b[1]-'0'-8))*8+(b[0]-'a')) << " knight moves." <<endl;
    }



    return 0;

}



/*********************************************************************
  __________________________BUILT_IN FUNCTIONS__________________________


#
int sprintf(char *restrict buffer, const char *restrictformat, ...);
This function convert number to string with specified format.
Defined in header <stdio.h>
Example:
int aInt = 368;
char str[15];
sprintf(str, "%d", aInt);
cout << str << endl;


#
std::cin.getline();
getline can be provided a third argument--a "stop" character. This
character ends getline's input. The character is eaten and the
string is terminated. Example: std::cin.getline(str, 100, '|')
If std::cin.getline() is not provided a "stop" character as a third
argument, it will stop when it reaches a newline.
Example: std::cin.getline(str, 100)


#
std::cin.ignore()
can be called three different ways:
1. No arguments: A single character is taken from the input buffer
and discarded:
std::cin.ignore(); //discard 1 character
2. One argument: The number of characters specified are taken from
the input buffer and discarded:
std::cin.ignore(33); //discard 33 characters
3. Two arguments: discard the number of characters specified, or
discard characters up to and including the specified delimiter
(whichever comes first):
std::cin.ignore(26, '\n');
//ignore 26 characters or to a newline, whichever comes first



#
Formated I/O
Example: std::cout << std::right << setw(5) << 123 << endl;
//output:"  123"
std::cout.fill('X');
std::cout << setw(2) << one << std::endl.;
//output: "X4"
#include <iomanip>


#
strcpy(char* des, char* src) //Copies src into des.


#
double a = 18.12385;
cout << fixed << setprecision(3);
cout << a << endl;
//output: 18.124
#include <iomanip>
std::fixed, std::setprecision()


#
next_permutation(str, str+strlen(str));
return non-zero if next permutation found, otherwise 0
char str[] = "arafat";
if(next_permutation(str, str+strlen(str)))
cout << str << endl;
//output: arafta
#include <algorithm>



********************************************************************/

