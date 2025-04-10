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
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n-1;j++){
                cout << setw(3) << abs(i-j)+1 << " ";
            }
            cout << setw(3) << abs(i-n) << endl;
        }
        cout << endl;
        cin >> n;
    }
 }