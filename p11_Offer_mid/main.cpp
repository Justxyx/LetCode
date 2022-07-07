#include <iostream>
#include <stack>
using namespace std;
#include <vector>
#include <set>

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        int min_ele = x;
        if (!v.empty())
            min_ele = std::min(v.back().second, x);
        v.push_back(make_pair(x, min_ele));
    }

    void pop() {
        if (!v.empty())
            v.pop_back();
    }

    int top() {
        if (!v.empty())
            return v.back().first;
        return -1;
    }

    int min() {
        if (!v.empty())
            return v.back().first;
        return -1;
    }

private:
    vector<pair<int,int>> v;
};

int main() {

}