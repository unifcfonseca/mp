#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
set<int> vlrs;
void search(int dia, int vlr1, vector<int> barn1, int vlr2, vector<int> barn2) {
    if (dia >= 4) {
        vlrs.insert(vlr1);
    } else {
        for (int i = 0; i < 10; i++) {
            int balde = barn1[i];
            vector<int> nbarn1 = barn1;
            vector<int> nbarn2 = barn2;
            nbarn1.erase(begin(nbarn1)+i);
            nbarn2.push_back(balde);
            search(dia+1,vlr2+balde,nbarn2,vlr1-balde,nbarn1);
        }
    }
}


int main() {
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);

	vector<int> barn1(10);
    vector<int> barn2(10);

    for(int i = 0;i<10;i++){
        cin >> barn1[i];
    }
    for(int i = 0;i<10;i++){
        cin >> barn2[i];
    }


    search(0,1000,barn1,1000,barn2);

    cout << vlrs.size() << endl;
}