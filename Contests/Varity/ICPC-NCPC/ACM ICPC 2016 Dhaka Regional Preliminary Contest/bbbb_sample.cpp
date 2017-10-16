#include<bits/stdc++.h>
using namespace std;
#define MX 1002
int stock_prices[MX], nDay, marked[MX];

int getMaximum(int start, int end) {
    int ret = -1, mx = 0;
    for(int i = start; i <= end; i++) {
        if(!marked[i] && mx <= stock_prices[i]) {
            mx = stock_prices[i];
            ret = i;
        }
    }
    return ret;
}

int getMinimum(int start, int end) {
    int ret = -1, mn = 1000000000;
    for(int i = start; i <= end; i++) {
        if(!marked[i] && mn > stock_prices[i]) {
            mn = stock_prices[i];
            ret = i;
        }
    }
    return ret;
}


int getProfit(int start, int end) {
    int profit = 0, i;
    for(i = start; i <= end; i++) marked[i] = 0;
    while(1) {
        int X = getMaximum(start, end);
        int Y = getMinimum(start, X - 1);
        if(X==-1 || Y==-1)break;
        profit += stock_prices[X] - stock_prices[Y];
        marked[X] = marked[Y] = 1;
    }
    return profit;
}


int main() {

    while(scanf("%d", &nDay)==1) {
        for(int i = 1; i <= nDay; i++)
            scanf("%d", &stock_prices[i]);

        int profit = getProfit(1, nDay);
        printf("%d\n", profit);
    }
    return 0;
}
