#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<ll> dp(n + 1, 0);
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {

        ll val1 = INT_MAX;
        if (i + 1 <= n - 1)
        {
            val1 = dp[i + 1] + abs(arr[i] - arr[i + 1]);
        }
        ll val2 = INT_MAX;
        if (i + 2 <= n - 1)
        {
            val2 = dp[i + 2] + abs(arr[i] - arr[i + 2]);
        }
        dp[i] = min(val1, val2);
    }
    cout << dp[0] << endl;
}
