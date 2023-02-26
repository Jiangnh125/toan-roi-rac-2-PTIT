#include<bits/stdc++.h>
using namespace std;

int n;
int a[1001][1001];
bool visited[1001];
queue<int> q;

void BFS_Queue(int u){
    cout << u << " ";
    visited[u] = true;
    q.push(u);
    while (!q.empty()){
        u = q.front();
        q.pop();
        for (int i = 1; i <= n; i++){
            if (a[u][i] && !visited[i]){
                q.push(i);
                cout << i << " ";
                visited[i] = true;
            }
        }
    }
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        visited[i] = false;
        for (int j = 1; j <=n; j++){
            cin >> a[i][j];
        }
    }
    BFS_Queue(1);

}


