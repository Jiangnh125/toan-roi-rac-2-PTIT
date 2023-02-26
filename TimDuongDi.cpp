#include<bits/stdc++.h>
using namespace std;

int n, s, t, a[1001][1001];
bool visited[1001];
int truoc[1001];

void DFS (int u){
    visited[u] = true; 
    for (int i = 1; i <= n; i++){
        if (a[u][i] && !visited[i]){
            truoc[i] = u;
            DFS(i);
        }
    }
}

void BFS (int u){
    queue<int> q;
    visited[u] = true;
    q.push(u);
    while (!q.empty()){
        u = q.front();
        q.pop();
        for (int i = 1; i <= n; i++){
            if(a[u][i] && !visited[i]){
                q.push(i);
                visited[i] = true;
                truoc[i] = u;
            }
        }
    }
}

void TimDuong (int s, int t){
    // if(truoc[t] == 0)
    //     cout << "no path";
    // else{
        vector<int> path;
        while (t != s){
            path.push_back(t);
            t = truoc[t];
        }
        path.push_back(s);
        for (int x : path){
            cout << x << " ";
        }
    // }
}
int main(){
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++){
        visited[i] = false;
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    DFS(s);
    if (truoc[t] == 0)  
        cout << "no path";
    else{
        cout << "DFS path: ";
        TimDuong (s, t);
        cout << endl;
        for (int i = 1; i <= n; i++)
            visited[i] = false;
        BFS(s);
        cout << "BFS path: ";
        TimDuong (s, t);
    }
}