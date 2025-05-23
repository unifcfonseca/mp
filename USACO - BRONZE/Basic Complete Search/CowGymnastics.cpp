#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int idx(vector<int>aula, int vlr){
    for(int i = 0;i<aula.size();i++){
        if(aula[i]==vlr){
            return i;
        }
    }
    return -1;
}

int main() {
    std::ifstream read("gymnastics.in");
    int k,n;
    read >> k >> n;

    vector<vector<int>>aulas;

    for(int i = 0;i<k;i++){
        vector<int> aula;
        for(int j = 0;j<n;j++){
            int x;
            read  >> x;
            aula.push_back(x-1);
        }
        aulas.push_back(aula);
    }
    int paresConsistentes = 0;
    for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
            if(i==j){continue;}
            bool mlr = true;
			for(int l = 0;l<aulas.size();l++){
                if(idx(aulas[l],i)<idx(aulas[l],j)){
                    mlr = false;
                    break;
                }
            }
            if(mlr){
                paresConsistentes++;
            }
		}
	}
    std::ofstream("gymnastics.out") << paresConsistentes << endl;

return 0;
}