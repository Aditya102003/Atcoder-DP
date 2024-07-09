#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, k;
    cin >> n >> k;
    ll arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<ll> dp(n + 1, 0);
    dp[0] = 0;
    for (ll i = 1; i < n; i++)
    {
        ll val = LONG_MAX;
        for (int j = 1; j <= min(i, k); j++)
        {

            ll sum = dp[i - j] + abs(arr[i] - arr[i - j]);

            val = min(val, sum);
        }
        dp[i] = val;
    }
    cout << dp[n - 1] << endl;
}
