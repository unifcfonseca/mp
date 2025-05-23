#include <bits/stdc++.h>
using namespace std;

int n = 8;

int contar = 0;

vector<int> column;
vector<int> diag1;
vector<int> diag2;
vector<string>mapa;

void search(int y) {
    if (y == n) {
        contar++;
        return;
    }
    for (int x = 0; x < n; x++) {
        if (column[x] || diag1[x+y] || diag2[x-y+n-1] || mapa[x][y] == '*') continue;
        column[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
        search(y+1);
        column[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
    }
}



int main() {
	column.resize(8,0);
    diag1.resize(15,0);
    diag2.resize(15,0);
    mapa.resize(n);

    for(int i = 0;i<n;i++){cin >> mapa[i];}
    
    search(0);

    cout << contar << endl;
}