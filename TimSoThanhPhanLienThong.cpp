#include<iostream>
using namespace std;

int n, a[1001][1001];
bool visited[1001];

void DFS (int u){
    // cout << u << " ";
    visited[u] = true;
    for (int i = 1; i <= n; i++)
        if (a[u][i] && !visited[i])
            DFS(i);
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        visited[i] = false;
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    int dem = 0;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            dem++;
            DFS(i);
        }
    }
    cout << dem; 
}