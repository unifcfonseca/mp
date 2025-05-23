#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
set<vector<string>> permutation;
vector<string> ordem = {" "};
vector<bool> escolhida;
vector<pair<string,string>> regras;
vector<string> vacas = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};

void search() {
    if (ordem.size()-1 == vacas.size()) {
        bool obdc = true;
        ordem.push_back(" ");
        for(int i = 1;i< ordem.size()-1;i++){
            for(pair<string,string> dupla : regras){
                if(ordem[i] == dupla.first && (ordem[i-1]!=dupla.second && ordem[i+1]!=dupla.second)){
                    obdc = false;
                    break;
                }
            }
            if(!obdc){
                break;
            }
        }
        if(obdc){
            permutation.insert(ordem);
        }
        ordem.pop_back();
    } else {
        for (int i = 0; i < vacas.size(); i++) {
            if (escolhida[i]) continue;
            escolhida[i] = true;
            ordem.push_back(vacas[i]);
            search();
            escolhida[i] = false;
            ordem.pop_back();
        }
    }
}


int main() {
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
	cin >> n;
	escolhida.resize(8,false);

    for(int i = 0;i<n;i++){
        string x,vacA,vacB;
        cin >> vacA >> x >> x >> x >> x >> vacB;
        regras.push_back(make_pair(vacA,vacB));
    }

    search();

    auto x = *permutation.begin();
    for(int i = 1;i<x.size()-1;i++)cout<<x[i]<<endl;
}