#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
using namespace std;


const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
const char moves[4] = {'L', 'R', 'U', 'D'};

int n, m;
vector<string> labyrinth;
pair<int, int> start, fine;


bool isValid(int x, int y, const vector<vector<bool> > &visited) {
    return x >= 0 && x < n && y >= 0 && y < m && labyrinth[x][y] != '#' && !visited[x][y];
}

int main() {
    cin >> n >> m;
    labyrinth.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> labyrinth[i];
        for (int j = 0; j < m; j++) {
            if (labyrinth[i][j] == 'A') start = make_pair(i, j);
            if (labyrinth[i][j] == 'B') fine = make_pair(i, j);
        }
    }

    queue<pair<int, int> > q;
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int> > > parent(n, vector<pair<int, int> >(m, make_pair(-1, -1)));

    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        if (current == fine) break;

        for (int i = 0; i < 4; i++) {
            int nx = current.first + dx[i];
            int ny = current.second + dy[i];

            if (isValid(nx, ny, visited)) {
                visited[nx][ny] = true;
                parent[nx][ny] = current;
                q.push(make_pair(nx, ny));
            }
        }
    }

    if (!visited[fine.first][fine.second]) {
        cout << "NO" << endl;
        return 0;
    }

    string path;
    pair<int, int> current = fine;
    while (current != start) {
        pair<int, int> prev = parent[current.first][current.second];
        for (int i = 0; i < 4; i++) {
            if (prev.first + dx[i] == current.first && prev.second + dy[i] == current.second) {
                path += moves[i];
                break;
            }
        }
        current = prev;
    }

    reverse(path.begin(), path.end());
    cout << "YES" << endl;
    cout << path.length() << endl;
    cout << path << endl;

    return 0;
}