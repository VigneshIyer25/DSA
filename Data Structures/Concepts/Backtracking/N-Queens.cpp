// given and nxn chess board, print number of ways n queens can be placed that no queen can attack any other queen.
#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> solve(int n){
    vector<vector<string>> board(n,vector<string>(n));
    
}

int main(){
    int n = 8;
    vector<vector<string>> ans = solve(n);
    cout<<"Valid Solutions for an "<<n<<"x"<<n<<" board are:";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}