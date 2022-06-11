#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        arr[i] += ((arr[arr[i]]) % n) * n;
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] / 5 << " ";
    return 0;
}