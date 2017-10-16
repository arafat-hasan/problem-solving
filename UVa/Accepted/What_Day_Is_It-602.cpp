/*
 * FILE: What_Day_Is_It-602.cpp
 *
 * @author: Md. Arafat Hasan Jenin <Opendoor.Arafat@gmail.com>
 *
 * LINK: https://uva.onlinejudge.org/external/6/602.pdf
 *
 * Description:
 *
 *
 *   DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    31 Jan 2017    New             1.0		WA
 *
 *
 */


#include <stdio.h>
#define REP(n) for (int i=0; i<n; i++)

using namespace std;

int isleapyear(int year);
int dayofweek(int m, int d, int y);

int main() {

    char weekday[7][10] = {{"Sunday"}, {"Monday"}, {"Tuesday"}, {"Wednesday"}, {"Thursday"}, {"Friday"}, {"Saturday"}};
    char month[12][20] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int d, m, y;
    int month_len[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    while(scanf("%d %d %d", &m, &d, &y), m||d||y) {
		
		if(isleapyear(y)) month_len[1] = 29;
		else month_len[1] = 28;
		
		if((m>12||m<1) || (d>month_len[m-1]||d<1)) printf("%d/%d/%d is an invalid date.\n", m, d, y);
		else printf("%s %i, %i is a %s\n", &month[m-1][0], d, y, &weekday[dayofweek(m, d, y)][0]);
    }

    return 0;
}


int dayofweek(int m, int d, int y) { 	/* 1 <= m <= 12,  y > 1752 (in the U.K.) */
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}


int isleapyear(int year) {
    /*Is year divided by 4? After every 100 years a leap year is not counted
    and after every 400 years we count leap year*/
    if(((year%4==0) && (year%100!=0)) || (year%400==0))
        return 1;
    return 0;
}




