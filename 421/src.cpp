#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <unordered_map>
#include <utility>
using namespace std;

class TrieNode{
public:
  int val;
  bool isEnd;
  vector<TrieNode* > children;
  TrieNode(){
    val = 0;
    isEnd = false;
    children = vector<TrieNode*>(2,NULL);
  }
};

class Solution {
public:
    TrieNode* root;
    int max_xor;
    void add(int num){
        TrieNode* cur = root;
        unsigned int mask = 1 << 31;
        int i = 0;
        while(i < 32){
          int bit = mask & num ? 1 : 0;

          i++;
          mask = mask >> 1;
          if(cur->children[bit] == NULL){
            TrieNode* node = new TrieNode();
            node->val = bit;
            cur->children[bit] = node;
            cur = node;
          }else{
            cur = cur->children[bit];
          }
        }
        cur->isEnd = true;
    }
    int comp(int num){
      TrieNode* cur = root;
      unsigned mask = 1 << 31;
      int i = 0;
      int result = 0;
      while(i < 32){
        int bit = mask & num ? 0 : 1;
        if(cur->children[bit]){
          cur = cur->children[bit];
          result = result | mask;
        }else{
          cur = cur->children[1-bit];
        }
        mask = mask >> 1;
        i++;    
      }

      return result;
    }
    int findMaximumXOR(vector<int>& nums) {
        root = new TrieNode();
        for(int i = 0; i < nums.size(); i++){
          add(nums[i]);
        }
        max_xor = 0;
        for(int i = 0; i < nums.size(); i++){
          max_xor = max(max_xor,comp(nums[i]));
        }
        return max_xor;
    }
};

int main(){

  vector<int> nums = {3, 10, 5, 25, 2, 8};
  Solution solution;
  int result = solution.findMaximumXOR(nums);

  cout << result << endl;


    
  return 0;
}