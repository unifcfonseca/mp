#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string n;
set<vector<char>> perm;
vector<char> letras;
vector<bool> escolhido;

void search() {
    if (letras.size() == n.size()) {
        perm.insert(letras);
    } else {
        for (int i = 0; i < n.size(); i++) {
            if (escolhido[i]) continue;
            escolhido[i] = true;
            letras.push_back(n[i]);
            search();
            escolhido[i] = false;
            letras.pop_back();
        }
    }
}


int main() {
	cin >> n;
	escolhido.resize(n.size(),false);

    search();
    cout << perm.size() << endl;
    for(vector<char> x:perm){
        for(char l: x){
            cout << l;
        }
        cout << endl;
    }


}