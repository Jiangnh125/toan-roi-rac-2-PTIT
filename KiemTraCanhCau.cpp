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
    for(int u = 1; u < n; u++){
        for (int v = u+1; v <= n; v++){
            if (a[u][v]){
                a[u][v] = 0; a[v][u] = 0;
                DFS(1);
                if(TestLienThong())
                    cout << u << " " << v << endl;
                a[u][v] = 1; a[v][u] = 1;
                ReVisited();
            } 
        }
    }
}