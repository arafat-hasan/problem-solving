#include <stdio.h>

#define S(x, y) {t = x; x = y; y = t;}

char z[] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
char o[9];

int v(int c, int y, int m, int d)
{
  if (m > 12 || m == 0 || d > z[m] || d == 0 || (m == 2 && d > 28 && (y & 3 || (y == 0 && c))))
    return 0;
  o[0] = '0' + y / 10;
  o[1] = '0' + y % 10;
  o[3] = '0' + m / 10;
  o[4] = '0' + m % 10;
  o[6] = '0' + d / 10;
  o[7] = '0' + d % 10;
  puts(o);
  return 1;
}

int g(void)
{
  int r = 0;
  char c;
  c = getc(stdin);
  r = c - '0';
  while ((c = getc(stdin)) >= '0')
    r = r * 10 + c - '0';
  return r;
}

int main(void)
{
  int n, c, d, m, y, t;

  o[5] = o[2] = ' ';
  o[8] = 0;
  n = g();

  while (n--) {
    c = g();
    y = g();
    m = g();
    d = g();

    c &= 3;

    if (m < y)
      S(m, y);
    if (d < m) {
      S(d, m);
      if (m < y)
        S(m, y);
    }

    if (v(c, y, m, d) || v(c, y, d, m) ||
        v(c, m, y, d) || v(c, m, d, y) ||
        v(c, d, y, m) || v(c, d, m, y))
      continue;
    puts("-1");
  }

  return 0;
}
