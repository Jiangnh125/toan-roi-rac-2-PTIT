#include<bits/stdc++.h>
using namespace std;

int n, k, a[1001][1001];
bool visited[10001];

int DFS(int u){
    int dem = 1;
    visited[u] = true;
    for (int i = 1; i <= n; i++){
        if(a[u][i] && !visited[i]){
            dem++;
            DFS(i);
        }
    }
    return(dem);
}

void Euler(){
    
}

int main(){
    cin >> n >> k;
    for(int i = 1; i < n; i++){
        visited[i] = false;
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }

}