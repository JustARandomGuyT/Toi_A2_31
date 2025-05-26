#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m;
    cin >> k;

    map<pair<int, int>, int> pokemon;

    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        pokemon[{x, y}]++;
    }

    vector<pair<int, int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},          {0, 1},
        {1, -1},  {1, 0}, {1, 1}
    };

    int maxCatch = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (pokemon.count({i, j}) == 0) { 
                int catchCount = 0;
                for (auto d : directions) {
                    int ni = i + d.first;
                    int nj = j + d.second;

                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        catchCount += pokemon[{ni, nj}];
                    }
                }
                maxCatch = max(maxCatch, catchCount);
            }
        }
    }

    cout << maxCatch << endl;

    return 0;
}
