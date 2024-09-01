#include <iostream>
#include <vector>


using namespace std;


#define ll long long
#define vll vector<long long>
#define lli long long int
lli n, k;

lli a[10];
vector<vll> ans;

void f(int ind, int sum, vll &current){


    if(ind == n){
        if(sum % k == 0){
            ans.push_back(current);
        }
    }

    for (auto ele = 1; ele <= a[ind]; ele++){
        current.push_back(ele);
        f(ind + 1, sum + ele, current);
        current.pop_back();
    }
}




void solve(){

    
    cin >> n >> k;

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    vll current;

    f(0, 0, current);


    for(auto it : ans){
        for(auto i : it){
            cout << i << " ";
        }
        cout << endl;
    }
}



int main(){
    lli t = 1;
    while(t--){
        solve();
    }
    return 0;
}