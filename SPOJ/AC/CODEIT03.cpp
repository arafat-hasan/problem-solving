/*
 * FILE: CODEIT03.cpp
 *
 * @author: Md. Arafat Hasan Jenin <Opendoor.Arafat@gmail.com>
 *
 * LINK: http://www.spoj.com/problems/CODEIT03/en/
 *
 * Description:
 *
 *
 *   DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    31 Jan 2017    New             1.0        Completed, AC
 *
 *
 */


#include <stdio.h>
#define REP(n) for (int i=0; i<n; i++)

using namespace std;

int dayofweek(int d, int m, int y);

int main() {
    char weekday[7][10] = {{"Sunday"}, {"Monday"}, {"Tuesday"}, {"Wednesday"}, {"Thursday"}, {"Friday"}, {"Saturday"}};

    int t, d, m, y;
    scanf("%d", &t);
    REP(t) {
        scanf("%d %d %d", &d, &m, &y);
        printf("%s\n", &weekday[dayofweek(d, m, y)][0]);
    }

    return 0;
}


int dayofweek(int d, int m,
              int y) { /* 1 <= m <= 12,  y > 1752 (in the U.K.) */
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}

