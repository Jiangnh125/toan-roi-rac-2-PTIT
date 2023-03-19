#include<iostream>
using namespace std;

int n, k, a[1001][1001], circuit[1000];
bool visited[1001];

void result(){
    cout << circuit[n] << " ";
    for (int i = 1 ; i <= n; i++)
        cout << circuit[i] << " ";
    cout << endl;
}

void Hamilton(int k, int circuit[1000]){
    // chon cach dinh v lien ke truoc va chua tham
    for (int v = 1; v <= n; v++){
        if (!visited[v] && a[circuit[k-1]][v]){
            circuit[k] = v;     // ghi nhan v vao chu trinh 
            visited[v] = true;
            if(k < n){
                Hamilton(k+1, circuit);
            }
            else if (circuit[k] == circuit[0])
                result();
            visited[v] = false;
        }
        
    }
}

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        visited[i] = false;
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    circuit[0] = 1;
    Hamilton(k, circuit);
}