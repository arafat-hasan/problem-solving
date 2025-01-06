#include<bits/stdc++.h>

using namespace std;

int traillingZeros(int n)
{
    int cnt = 0;
    for(int i = 5; n / i >= 1; i *= 5)
    {
        cnt += n / i;
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << traillingZeros(n) << endl;
    }
    return 0;
}
