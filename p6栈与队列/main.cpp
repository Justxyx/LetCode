#include <iostream>
#include <stack>
using namespace std;
#include <queue>


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        string symbol = "+-*/";
        stack<int> stack;
        int x,y;
        for (const string &item : tokens){
//            cout << item << endl;
            int i = symbol.find(item);
            if (i < 0){  // 数字
                stack.push(atoi(item.c_str()));
            } else{
                x = stack.top();
                stack.pop();
                y = stack.top();
                stack.pop();
                if (item == "+")
                    stack.push(x+y);
                else if ( item == "-")
                    stack.push(y-x);
                else if (item == "*")
                    stack.push(x*y);
                else
                    stack.push(y/x);
            }
        }
        return stack.top();
    }
};



int main() {

    string symbol = "+-*/";
    int i =  symbol.find("2");
    int s;
    if (( symbol.find("2")) > 0){
        cout << "h" << endl;
    }
    cout << i ;
}
