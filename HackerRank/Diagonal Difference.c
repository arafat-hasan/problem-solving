#include <stdio.h>
#include <stdlib.h>
int main()
{
    int            n,
                    i,
                    j,
                    r = 0,
	t = 0;
    scanf("%d", &n);
    int             a[n][n];
    for (i = 0; i < n; i++) {
	for (j = 0; j < n; j++) {
	    scanf("%d", &a[i][j]);
	}
    }
    for (i = 0; i < n; i++)
	r = a[i][i] + r;
    for (i = 0; i < n; i++)
	t = a[i][n - i - 1] + t;
    printf("%d",abs(r - t));
    return 0;
}

