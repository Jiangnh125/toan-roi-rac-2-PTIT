
#include <bits/stdc++.h>
using namespace std;

int n;
int a[1001][1001];
bool visited[1001];

void DFS_Stack(int u){
    stack<int> s;
    cout << u << " ";
    visited[u] = true;
    s.push(u);
    while (!s.empty()){
        u = s.top();
        s.pop();
        for (int i = 1; i <= n; i++){
            if (a[u][i] && !visited[i]){
                s.push(u);
                s.push(i);
                cout << i << " ";
                visited[i] = true;
                break;
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
    DFS_Stack(1);

}



// #include <bits/stdc++.h>
// using namespace std;

// int n;
// int a[1001][1001];
// vector<int> dsk[1001];
// bool visited[1001];
// stack<int> s;

// void DSK(){
//     for (int i = 1; i <= n; i++){
//         for (int j = 1; j <= n; j++){
//             if (a[i][j])
//                 dsk[i].push_back(j);
//         }
//     }
// }

// void DFS_Stack(int u){
//     cout << u << " ";
//     visited[u] = true;
//     s.push(u);
//     while (!s.empty()){
//         u = s.top();
//         s.pop();
//         for (int x : dsk[u]){
//             if (!visited[x]){
//                 s.push(u);
//                 s.push(x);
//                 cout << x << " ";
//                 visited[x] = true;
//                 break;
//             }
       
//         }
//     }
// }
// int main(){
//     cin >> n;
//     for (int i = 1; i <= n; i++){
//         visited[i] = false;
//         for (int j = 1; j <=n; j++){
//             cin >> a[i][j];
//         }
//     }
//     DSK();
//     DFS_Stack(1);

// }


