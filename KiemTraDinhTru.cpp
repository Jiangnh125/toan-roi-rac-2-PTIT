#include<bits/stdc++.h>

using namespace std;

int n, a[1001][1001];
bool visited[1001];

void DFS(int u){
    visited[u] = true;
    for(int i = 1; i <= n; i++){
        if (a[u][i] && !visited[i]){
            DFS(i);
        }
    }
}

void ReVisited(){
    for (int i = 1; i <= n; i++)
        visited[i] = false;
}

int TestLienThong(){
    for (int i = 1; i <= n; i++){
        if (!visited[i]) return 1;
    }
    return 0;
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        visited[i] = false;
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        visited[i] = true;
        DFS(1);
        // cout << TestLienThong() << " ";
        if (TestLienThong())  
            cout << i << " ";
        ReVisited();
    }
}