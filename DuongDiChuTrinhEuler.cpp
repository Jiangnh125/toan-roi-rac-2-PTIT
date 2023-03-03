// dau vao la ma tran ke vo huong

#include<bits/stdc++.h>
using namespace std;

int n, k, a[1001][1001];
bool visited[10001];

void DFS(int u){
    visited[u] = true;
    for (int i = 1; i <= n; i++){
        if(a[u][i] && !visited[i]){
            DFS(i);
        }
    }
}

// kiem tra xem do thi co lien thong hay khong
int TestLienThong(){
    for (int i = 1; i <= n; i++){
        if (!visited[i]) return 0;
    }
    return 1;
}

// kiem tra do thi co duong di or chu trinh euler khong
int check(){
    int d = 0;
    for (int i = 1; i <= n; i++){
        int s = 0;
        for (int j = 1; j <= n; j++){
            s += a[i][j];
        }
        if (s%2 == 1) d++;
    }
    if (d == 0 || d == 2) return 1;
    return 0;
}
void Euler(int k){
    stack<int> s; 
    vector<int> el; // luu duong di euler
    s.push(k);
    while (!s.empty()){
        int u = s.top();
        for (int i = 1; i <= n; i++){
            if (a[u][i]){ // neu co canh (u,i) // ke(u) != 0
                // xoa canh (u,i)
                a[u][i] = 0;
                a[i][u] = 0;

                // push i vao stack
                s.push(i);
                break; 
            }
        }
        if (u == s.top()){ // ke(u) == 0
            el.push_back(u);
            s.pop();
        }
    }
    for (int i = el.size() - 1; i >= 0; i--)
        cout << el[i] << " ";
}

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        visited[i] = false;
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    DFS(1);
    if (TestLienThong() && check())
        Euler(k);
    // // else cout << " ko co euler"; 
    return 0;
}