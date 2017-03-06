#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <climits>
#include <queue>
#include <map>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Codec {
public:
    
    // string conv(int val){
    //     map<int,char> hexmap={{0,'0'},{1,'1'},{2,'2'},{3,'3'},{4,'4'},{5,'5'},{6,'6'},{7,'7'},{8,'8'},{9,'9'},{10,'A'},{11,'B'},{12,'C'},{13,'D'},{14,'E'},{15,'F'}};
    //     int mask = 0x000f;
    //     string s = "";
    //     for(int i = 0; i < 4; i++){
    //         int temp = (mask & val);
    //         s = hexmap[temp] + s;
    //         val = val >> 4;
    //     }
    //     return s;
    // }
    // int conv_int(string s){
    //      map<char,int> hexmap={{'0',0},{'1',1},{'2',2},{'3',3},{'4',4},{'5',5},{'6',6},{'7',7},{'8',8},{'9',9},{'A',10},{'B',11},{'C',12},{'D',13},{'E',14},{'F',15}};
    //     int res = 0;
    //     for(int i = 0; i < 4; i++){
    //     	int mask = hexmap[s[i]] << (3 - i)*4;
    //         res = res | mask;
    //     }
    //     return res;
    // }
    // Encodes a tree to a single string.

    void serializeUtil(TreeNode* root, string& s){
        if(!root){
            // s = s + "#" + ",";
            return;
        }
        s = s + to_string(root->val) + ",";        
        serializeUtil(root->left,s);
        serializeUtil(root->right,s);
    }
    string serialize(TreeNode* root) {
        string s ="";
        serializeUtil(root,s);
        return s;
    }
    // Decodes your encoded data to tree.

    TreeNode* deserializeUtil(string& data, int& cur, int low, int high){
    	if(cur == data.length()){
    		return NULL;
    	}
        int len = 1;
        while(data[cur+len - 1] != ','){
        	len++;
        }
        int temp = stoi(data.substr(cur,len-1));
        if(temp < low || temp > high){
        	return NULL;
        }
        TreeNode* root = new TreeNode(temp);
        cur = cur + len;
        root->left = deserializeUtil(data,cur,low,temp);
        root->right = deserializeUtil(data,cur,temp,high);
        return root;
    }
     TreeNode* deserialize(string data) {
     	int cur = 0;
        return deserializeUtil(data,cur,INT_MIN,INT_MAX);
    }
};

int main(){
	Codec codec;
//	cout << codec.conv_int(codec.conv(785)) << endl;

	return 0;
}