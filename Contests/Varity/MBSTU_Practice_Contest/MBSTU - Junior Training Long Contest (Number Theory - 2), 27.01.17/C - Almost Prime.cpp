/*
 * C - Almost Prime.cpp
 *
 * @author: Md. Arafat Hasan Jenin <Opendoor.Arafat@gmail.com>
 *
 * Description:
 *
 *
 *   DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    ** *** 2017    New             0.0
 *
 *
 */


#include <iostream>
//~ #include <vector>
//~ #include <algorithm>
//~ #include <queue>
//~ #include <climits>
#include <cmath>
typedef long long ll;
using namespace std;




int primefactor(long long n);
//~ int BFS(int s, int n) ;
//~ void bfs_visited(int s, int n);
void sieve(int n);
//~ void swap(int *x, int *y) ;
//~ long double fibbonacci(long double f);
//~ int IsPrime(int num);

#define maxS 3000
//~ #define g1 (1+sqrt(5))/2 // for fibbonacci
//~ #define g2 (1-sqrt(5))/2 // for fibbonacci

//~ vector<int> adj [100]; // for BFS & bfs_vis
//~ int cost[100]; // for BFS & bfs_vis
//~ int visited [100]; //for bfs_vis

int prime[maxS], primelst[maxS], maxprime; //for sieve
//int fact[100][2]; //for prime factor, 100 will be replaced with max number of factors
//int almost_prime[maxS];

int main() {

    sieve(maxS);

    int i, n,count=0;
    cin >> n;
    for(i=0; i<=n; i++) {
        if(primefactor(i) == 2)
            count++;
    }

    cout << count;



    return 0;
}


//~ int BFS(int s, int n) {
//~ int i, cn, v, sz;
//~ for(i = 0; i < n; i++)
//~ cost[i]=INT_MAX;

//~ queue<int> Q;
//~ Q.push(s);
//~ cost[s]=0;
//~ while(!Q.empty()) {
//~ cn = Q.front();
//~ Q.pop();
//~ sz = adj[cn].size();
//~ printf("#%i ", cn);
//~ for(i=0; i<sz; i++) {
//~ v = adj[cn][i];
//~ if(cost[cn]+1<cost[v]) {
//~ Q.push(v);
//~ cost[v]= cost[cn]+1;
//~ }
//~ }
//~ }
//~ return 0;
//~ }



//~ void bfs_visited(int s, int n) {

//~ int u, v, i, m;
//~ for(i=0; i < n; i++) {
//~ visited[i] = 0;
//~ cost[i] = -1;
//~ }

//~ queue<int> Q;
//~ Q.push(s);
//~ visited[s] = 1;
//~ cost[s] = 0;

//~ while(!Q.empty()) {
//~ u = Q.front();
//~ Q.pop();
//~ m = adj[u].size();

//~ for(i = 0; i < m; i++) {
//~ if(visited[adj[u][i]] == 0) {
//~ v = adj[u][i];
//~ visited[v] = 1;
//~ Q.push(v);
//~ cost[v] = cost[u]+1;
//~ }
//~ }
//~ }
//~ }



int primefactor(long long n) {

    long long i,j;

    if(n==0||primelst[n]==0)
        return 0;

    for(i=0, j=0; i < maxprime; i++) {
        if(n%prime[i]==0) {
            while(n%prime[i]==0) {
                n/=prime[i];
            }
            j++;
        }
    }

    return j;
}


void sieve(int n) {

    int i,j;
    double root=sqrt(n);

    primelst[0]=primelst[1]=1;

    for(i=4; i<n; i+=2)
        primelst[i]=1;

    for(i=3, j=0; i<=root; i+=2) {
        if(!primelst[i]) {
            for(j=i*i; j<n; j+=2*i)
                primelst[j]=1;
        }
    }


    for(i=0, j=0; i<n; i++) {
        if(primelst[i]==0) {
            prime[j++]=i;
        }
    }

    maxprime=j;

}



//~ void swap(int *x, int *y) {
//~ // Code to swap 'x' and 'y'
//~ *x = *x * *y; // x now becomes 15
//~ *y = *x / *y; // y becomes 10
//~ *x = *x / *y; // x becomes 5
//~ }


//~ long double fibbonacci(long double f) {
//~ return (pow(g1,f)-pow(g2,f))/sqrt(5);
//~ }


//~ int IsPrime(int num) {
//~ int i,root=sqrt(num);
//~ if(num<2)			return 0;
//~ if(num==2)			return 1;
//~ if(num%2==0)		return 0;

//~ for(i=3; i<=root; i+=2)
//~ if(num%i==0)	return 0;

//~ return 1;
//~ }



