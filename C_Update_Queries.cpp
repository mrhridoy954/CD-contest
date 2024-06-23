#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        string s;
        cin >> s;

        vector<int> indices(m);
        for (int i = 0; i < m; ++i)
        {
            cin >> indices[i];
            indices[i]--;
        }

        string c;
        cin >> c;

        vector<pair<int, char>> updates(m);
        for (int i = 0; i < m; ++i)
        {
            updates[i] = {indices[i], c[i]};
        }

        sort(updates.begin(), updates.end(), [](pair<int, char> a, pair<int, char> b)
             {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first; });

        for (int i = 0; i < m; ++i)
        {
            s[updates[i].first] = updates[i].second;
        }

        cout << s << endl;
    }

    return 0;
}
