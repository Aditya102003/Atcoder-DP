
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    vector<vector<ll>> dp(n + 1, vector<ll>(3, 0));
    vector<vector<ll>> arr;
    for (int i = 0; i < n; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        vector<ll> vv;
        vv.push_back(a);
        vv.push_back(b);
        vv.push_back(c);
        arr.push_back(vv);
    }
    for (ll i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            dp[i][0] = max(arr[i][1], arr[i][2]);
            dp[i][1] = max(arr[i][0], arr[i][2]);
            dp[i][2] = max(arr[i][0], arr[i][1]);
        }
        else
        {
            dp[i][0] = max(dp[i + 1][1] + arr[i][1], dp[i + 1][2] + arr[i][2]);
            dp[i][1] = max(dp[i + 1][0] + arr[i][0], dp[i + 1][2] + arr[i][2]);
            dp[i][2] = max(dp[i + 1][1] + arr[i][1], dp[i + 1][0] + arr[i][0]);
        }
    }
    cout << max({dp[0][0], dp[0][1], dp[0][2]}) << endl;
}
