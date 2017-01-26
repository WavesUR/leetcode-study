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
	vector<string> contain_dot(string IP){
		vector<string> seg4;
		vector<string> seg6;
		string s4;
		string s6;
		int i = 0;
		while(i<IP.length()){
			if(IP[i] == '.'){
				if(s4 == ""){
					return {};
				}
				seg4.push_back(s4);
				s4 = "";
			}else if(isdigit(IP[i])){
				s4 = s4 + IP[i];

			}
			
			if(IP[i] == ':'){
				if(s6 == ""){
					return {};
				}
				seg6.push_back(s6);
				s6 = "";
			}else if(isdigit(IP[i]) || (IP[i] - 'A' >= 0 && IP[i] - 'F' <= 0) || (IP[i] - 'a' >= 0 && IP[i] - 'f' <= 0)){
				s6 = s6 + IP[i];
			}		
			i++;
		}
		seg4.push_back(s4);
		seg6.push_back(s6);
		if(seg4.size()== 4 && seg6.size() == 1){
			return seg4;
		}else if(seg4.size()== 1 && seg6.size() == 8){
			return seg6;
		}else{
			return {};
		}
	}
	bool ipv4_check(string IP){
		vector<string> seg;
		string s4;
		string s6;
		int i = 0;
		while(i<IP.length()){
			if(IP[i] == '.'){
				if(s4 == ""){
					return false;
				}
				seg.push_back(s4);
				s4 = "";
			}else if(isdigit(IP[i])){
				s4 = s4 + IP[i];

			}else{
				return false;
			}
			i++;
		}
		seg.push_back(s4);
		if(seg.size() != 4){
			return false;
		}


		for(int i = 0; i < seg.size(); i++){
			if(seg[i].length()>3 || (seg[i].length() != 1 && seg[i][0] == '0') || seg[i] =="" || stoi(seg[i])>255){
				return false;
			}
		}
		return true;
	}
	bool ipv6_check(string IP){
		vector<string> seg;
		string s6;
		int i = 0;
		while(i<IP.length()){			
			if(IP[i] == ':'){
				if(s6 == ""){
					return false;
				}
				seg.push_back(s6);
				s6 = "";
			}else if(isdigit(IP[i]) || (IP[i] - 'A' >= 0 && IP[i] - 'F' <= 0) || (IP[i] - 'a' >= 0 && IP[i] - 'f' <= 0)){
				s6 = s6 + IP[i];
			}else{
				return false;
			}		
			i++;
		}

		seg.push_back(s6);
		if(seg.size() != 8){
			return false;
		}

		for(int i = 0; i < seg.size(); i++){
			if(seg[i].length()>4 ){
				return false;
			}
		}
		return true;
	}
    string validIPAddress(string IP) {

        	if(ipv4_check(IP)){
        		return "IPv4";
        	}
        	if(ipv6_check(IP)){
        		return "IPv6";
        	}

        	return "Neither";
    }
};


int main(){

string IP = "2001:0db8:85a3:033:0:8A2E:0370:7334";
Solution solution;
string result = solution.validIPAddress(IP);
cout << result << endl;

vector<string> count = solution.contain_dot(IP);
for(int i = 0; i < count.size();i++){
	cout << count[i] << endl << endl;
}

cout << ('G' - 'A' >= 0 && 'G'  - 'F' <= 0) << endl;
    
return 0;
  
}