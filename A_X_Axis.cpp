
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int x1, x2, x3;
        cin >> x1 >> x2 >> x3;

        int points[3] = {x1, x2, x3};
        sort(points, points + 3);

        int median = points[1];

        int TD = abs(points[0] - median) + abs(points[1] - median) + abs(points[2] - median);

        cout << TD << endl;
    }

    return 0;
}
