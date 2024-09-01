#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

#define lli long long int
using namespace std;

int dx[] = {0,0,-1, 1};
int dy[] = {1,-1,0,0};
char dir[] = {'R', 'L', 'U', 'D'};

bool in_range(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}


void  bfs(){
    lli n, m;
    cin >> n >> m;
    vector<string> v(n);
    for(auto &x : v) cin >> x;

    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    vector<vector<char>> moveDir(n, vector<char>(m));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    pair<int, int> start, end;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(vis[i][j] || v[i][j] == '#') continue;

            if(v[i][j] == 'A') {
                q.push({{i, j},0});
                vis[i][j] = 1;
                start = {i, j};
                break;
            }
        }
    }

            while(!q.empty()){
                pair<pair<int, int>, int> front = q.front();
                pair<int, int> corr = front.first;
                int dist = front.second;
                int x = corr.first;
                int y = corr.second;
                q.pop();

                if(v[x][y] == 'B'){
                    cout << "YES" << endl;
                    cout << dist << endl;
                    end = {x, y};
                    string path;
                    pair<int, int> step = {x, y};
                    while (step != start)
                    {
                        char dir = moveDir[step.first][step.second];
                        path.push_back(dir);
                        int prevX = parent[step.first][step.second].first;
                        int prevY = parent[step.first][step.second].second;
                        step = {prevX, prevY};
                    }
                    reverse(path.begin(), path.end());

                    cout << path << endl; // Print the path as a string of directions
                    return;
                }

                for (int a = 0; a < 4; a++){
                    int nx = x + dx[a];
                    int ny = y + dy[a];
                    

                    if(in_range(nx, ny, n, m) && !vis[nx][ny] && v[nx][ny] != '#'){
                        vis[nx][ny] = vis[x][y] + 1;
                        q.push({{nx, ny}, dist + 1});
                        parent[nx][ny] = {x, y};
                        moveDir[nx][ny] = dir[a];
                    }

                }
            }
        
    
    cout << "NO" << endl;
}


int main(){
    lli t = 1;
    while(t--){
        bfs();
    }
    return 0;
}
