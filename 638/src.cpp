#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;

class Solution {
public:
    int min_cost;
    int compare(vector<int>& needs, vector<int>& offer){
        int n = needs.size();
        for(int i = 0; i < n; i++){
            if(needs[i] < offer[i]){
                return -1;
            }
        }
        return offer[n];
    }
    void dfs(vector<int>& price, vector<vector<int> >& special, vector<int> needs, int offer_num, int cost){
        int n = price.size();
        vector<int> offer = special[offer_num];
        int compare_re = compare(needs,offer);
        if(compare_re == -1){
            int sum = cost;
            for(int i = 0; i < n; i++){
                sum += price[i] * needs[i];
            }
            if(sum < min_cost){
                min_cost = sum;
            }
            return;
        }

        // vector<int> needs_new = needs;
        for(int i = 0; i < n; i++){
            needs[i] = needs[i] - offer[i];
        }

        for(int i = offer_num; i < special.size(); i++){
            dfs(price, special, needs, i, cost + compare_re);
        }
        // needs = needs_new;
        return;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int> >& special, vector<int>& needs) {
        
        min_cost = 0;
        for(int i = 0; i < needs.size(); i++){
            min_cost += price[i] * needs[i];
        }
        for(int i = 0; i < special.size(); i++){
            dfs(price, special, needs, i, 0);           
        }
        return min_cost;
    }
};

int main(){

    vector<int> price = {0,0,0};
    vector<vector<int> > special = {{1,1,0,4},{2,2,1,9}};
    vector<int> needs = {2,2,1};
    Solution solution;
    int result = solution.shoppingOffers(price, special, needs);
    cout << result << endl; 


    
    return 0;
}