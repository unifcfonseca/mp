#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include<algorithm>

 using namespace std;

 int main(){
    int n;
    cin >> n;
    while(n>0){
        int matriz[n][n];
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                matriz[i][j]=1;
            }
        }
        for(int i = n;i>0;i--){
            for(int j = i; j<n-i;j++){
                for(int k = i; k<n-i;k++){
                    matriz[j][k]++;
                }
            }
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n-1;j++){
                cout << setw(3) << matriz[i][j] << " ";
            }
            cout << setw(3) << matriz[i][n-1] << endl;
        }
        cout << endl;
        cin >> n;
    }
 }