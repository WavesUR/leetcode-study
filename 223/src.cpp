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
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    	int s = (C-A) * (D - B) + (G - E) * (H - F);
        if(A >= G || C <= E || B >= H || F >= D){
        	return s;
        }else{
        	int x = min(C,G) - max(A,E);
        	int y = min(D,H) - max(B,F);
        	return s = x*y;
        }
    }
};
int main(){

  int A = -3;
  int B = 0;
  int C = 3;
   int D = 4;
   int E = 0;
   int F = -1;
   int G = 9;
   int H = 2;
  Solution solution;
  int result = solution.computeArea(A,B,C,D,E,F,G,H);

  cout << result << endl;


    
  return 0;
}