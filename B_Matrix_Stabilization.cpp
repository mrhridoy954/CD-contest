#include<bits/stdc++.h>

using namespace std;

bool isLocalMaximum(const vector<vector<int>>& matrix, int n, int m, int i, int j) {
    int val = matrix[i][j];
    if (i > 0 && val <= matrix[i-1][j]) return false;
    if (i < n-1 && val <= matrix[i+1][j]) return false;
    if (j > 0 && val <= matrix[i][j-1]) return false;
    if (j < m-1 && val <= matrix[i][j+1]) return false;
    return true;
}

void stabilizeMatrix(vector<vector<int>>& matrix, int n, int m) {
    bool foundLocalMax;
    do {
        foundLocalMax = false;
        int maxVal = -1;
        int best_i = -1, best_j = -1;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (isLocalMaximum(matrix, n, m, i, j)) {
                    if (matrix[i][j] > maxVal) {
                        maxVal = matrix[i][j];
                        best_i = i;
                        best_j = j;
                        foundLocalMax = true;
                    } else if (matrix[i][j] == maxVal) {
                        if (i < best_i || (i == best_i && j < best_j)) {
                            best_i = i;
                            best_j = j;
                        }
                    }
                }
            }
        }

        if (foundLocalMax) {
            matrix[best_i][best_j]--;
        }

    } while (foundLocalMax);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> matrix[i][j];
            }
        }
        stabilizeMatrix(matrix, n, m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
