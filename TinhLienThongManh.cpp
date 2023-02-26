#include<bits/stdc++.h>
using namespace std;

int n , a[1001][1001];
bool visited[1001];
int dem = 1;

int DFS (int u){
    visited[u] = true;
    for (int i = 1; i <= n; i++){
        if (a[u][i] && !visited[i]){
            dem++;
            DFS(i);
        }
    }
    return(dem);
}

void ReVisited(){
    for (int i = 1; i <= n; i++)
        visited[i] = false;
}

int LienThongManh(){
    for (int u = 1; u <= n; u++){
        int x = DFS(u);
        dem = 1;
        if(x != n){
            cout << "not strongly connected";
            return 0;
        }
        ReVisited();
    }  
    cout << "strongly connected";
    return 0;
}

int main(){
    cin >> n; 
    for (int i = 1; i <= n; i++){
        visited[i] = false;
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    } 
    LienThongManh();
    return 0;
}