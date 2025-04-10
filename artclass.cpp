#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<pair<int, int> > &lowHigh, vector<vector<bool> > &beenTo, vector<vector<char> > &grid, int r, int c);
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<bool> > beenTo(n, vector<bool>(m, false));
    vector<vector<char> > grid(n, vector<char>(m));
    vector<pair<int, int> > lowHigh; // lowest x + y, highest x + y, lowest x - y, highest x - y;
    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> grid[i][j];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            lowHigh = {{2000, 2000}, {-1, -1}, {2000, -1}, {-1, -1}};
            if (beenTo[i][j] or grid[i][j] == '.') continue;
            dfs(lowHigh, beenTo, grid, i, j);
            int first = 0, second = 0;
            if (lowHigh[0].first != 2000 and lowHigh[0].second != 2000 and lowHigh[1].first != -1 and lowHigh[1].second != -1)
                first = abs(lowHigh[0].first - lowHigh[1].first) + abs(lowHigh[0].second - lowHigh[1].second);
            if (lowHigh[2].first != 2000 and lowHigh[2].second != -1 and lowHigh[3].first != -1 and lowHigh[3].second != -1)
                second = abs(lowHigh[2].first - lowHigh[3].first) + abs(lowHigh[2].second - lowHigh[3].second);
            ans = max(ans, max(first, second));
        }
    }
    cout << ans;
}

void dfs(vector<pair<int, int> > &lowHigh, vector<vector<bool> > &beenTo, vector<vector<char> > &grid, int r, int c){
    if (r > grid.size() - 1 or r < 0 or c > grid[0].size() - 1 or c < 0) return;
    if (grid[r][c] == '.') return;
    if (beenTo[r][c]) return;
    beenTo[r][c] = true;
    dfs(lowHigh, beenTo, grid, r + 1, c);
    dfs(lowHigh, beenTo, grid, r - 1, c);
    dfs(lowHigh, beenTo, grid, r, c + 1);
    dfs(lowHigh, beenTo, grid, r, c - 1);
    if (r + c < lowHigh[0].first + lowHigh[0].second) lowHigh[0] = {r, c};
    if (r + c > lowHigh[1].first + lowHigh[1].second) lowHigh[1] = {r, c};
    if (r - c < lowHigh[2].first - lowHigh[2].second) lowHigh[2] = {r, c};
    if (r - c > lowHigh[3].first - lowHigh[3].second) lowHigh[3] = {r, c};
    return;


}

