#include <bits/stdc++.h>
int main() {
char str[10000];
int i = 0;
char c;
freopen(".cpp", "r", stdin);
while ((c = (char) getchar()) != EOF) {
str[i] = c;
i++;
}
i -= 2;
for (; i >= 0; i--) {
std::cout << str[i];
}
fclose(stdin);
return 0;
}
