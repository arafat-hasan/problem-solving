/*
 * FILE: C. Maximum Number.c
 *
 * @author: Md. Arafat Hasan Jenin <arafathasanjenin[at]gmail[dot]com>
 *
 * LINK: http://codeforces.com/contest/795/problem/C
 *
 * Description:
 *
 * DEVELOPMENT HISTORY:
 *       Date        Change          Version     Description
 * --------------------------------------------------------------
 *    ** *** 2017    New             0.0
 *
 */


/*
    ___          ___           ___                       ___
   /  /\        /  /\         /__/\        ___          /__/\
  /  /:/       /  /:/_        \  \:\      /  /\         \  \:\
 /__/::\      /  /:/ /\        \  \:\    /  /:/          \  \:\
 \__\/\:\    /  /:/ /:/_   _____\__\:\  /__/::\      _____\__\:\
    \  \:\  /__/:/ /:/ /\ /__/::::::::\ \__\/\:\__  /__/::::::::\
     \__\:\ \  \:\/:/ /:/ \  \:\~~\~~\/    \  \:\/\ \  \:\~~\~~\/
     /  /:/  \  \::/ /:/   \  \:\  ~~~      \__\::/  \  \:\  ~~~
    /__/:/    \  \:\/:/     \  \:\          /__/:/    \  \:\
    \__\/      \  \::/       \  \:\         \__\/      \  \:\
                \__\/         \__\/                     \__\/
*/


#include <stdio.h>

#define nn 6
#define et 7
#define sv 3
#define sx 6
#define fv 5
#define fr 4
#define th 5
#define tw 5
#define wn 2
#define zr 6

typedef long long ll;
typedef double lf;



int main() {

    int n, tmp;
    int sg[] = {6, 7, 3, 6, 5, 4, 5, 5, 2, 6};
    char str[25] = "";
    scanf("%d", &n);
    tmp = n;
    for (int i; tmp > 0; i++) {
        for (int j = 0; j < 10; j++) {
            tmp = n
        }

        if (n / nn > 0) {
            t = n / nn;
            for (j = 0; j < t; j++) {
                strcat(str, "9");
            }
            n %= nn;
            continue;
        }


        if (n / et > 0) {
            t = n / et;
            for (j = 0; j < t; j++) {
                strcat(str, "8");
            }
            n %= et;
            continue;
        }
        if (n / sv > 0) {
            t = n / sv;
            for (j = 0; j < t; j++) {
                strcat(str, "7");
            }
            n %= sv;
            continue;
        }


        if (n / sx > 0) {
            t = n / sx;
            for (j = 0; j < t; j++) {
                strcat(str, "6");
            }
            n %= sx;
            continue;
        }

        if (n / fv > 0) {
            t = n / fv;
            for (j = 0; j < t; j++) {
                strcat(str, "5");
            }
            n %= fv;
            continue;
        }


        if (n / fr > 0) {
            t = n / fr;
            for (j = 0; j < t; j++) {
                strcat(str, "4");
            }
            n %= fr;
            continue;
        }

        if (n / th > 0) {
            t = n / th;
            for (j = 0; j < t; j++) {
                strcat(str, "3");
            }
            n %= th;
            continue;
        }

        if (n / tw > 0) {
            t = n / tw;
            for (j = 0; j < t; j++) {
                strcat(str, "2");
            }
            n %= tw;
            continue;
        }

        if (n / wn > 0) {
            t = n / wn;
            for (j = 0; j < t; j++) {
                strcat(str, "1");
            }
            n %= wn;
            continue;
        }

        if (n / zr > 0) {
            t = n / zr;
            for (j = 0; j < t; j++) {
                strcat(str, "0");
            }
            n %= zr;
            continue;
        }

    }

    return 0;
}

