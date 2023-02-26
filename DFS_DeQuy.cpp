// input la ma tran ke

#include<bits/stdc++.h>

using namespace std;

int n;
int a[1001][1001];
// vector<int> adj(1001);
bool visited[1001];


void DFS(int u){
    cout << u << " ";
    visited[u] = true; // dinh u da duoc duyet
    for (int i = 1; i <= n; i++){
        if (a[u][i] && !visited[i])
            DFS(i);
    }
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        visited[i] = false; // dinh i chua duoc duyet
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    DFS(1);
}