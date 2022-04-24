#include <iostream>
using namespace std;
#include <vector>
#include <numeric>
#include <sstream>

class Solution {
public:
    vector<int> path;
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        backtracking(s,0);
        return res;
    }

    void backtracking(string &s,int index){
        if (path.size() == 4 && index == s.size()){
            res.push_back(toIp(path));
            return;
        }
        if (path.size() > 4 || index > s.size())
            return;

        for (int i = index; (i < s.size()) && ((i-index) <= 4); ++i) {
            string str(s.begin()+index,s.begin()+i+1);
            if (i != index + 1 && atoi(string(s.begin()+index,s.begin()+index+1).c_str()) == 0){
                cout << i << ":" << index;
                return;
            }
            int num = atoi(str.c_str());
            if ( num > 255){
                break;
            } else{
                path.push_back(num);
                backtracking(s,i+1);
                path.pop_back();
            }

        }
        return;
    }

    string toIp(vector<int> &path){
        string s("");
        for (const auto &item : path){
            int aa = item;
            stringstream ss;
            ss<<aa;
            string s1 = ss.str();
            s += s1;
            s += ".";
        }
        s = string(s.begin(),s.end()-1);
        return s;
    }
};


int main() {
    string s("0123");

    int i = 123;

    stringstream  ss;
    ss << i;
    string s2 = ss.str();
    cout << s2 << endl;

}
