#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

class StackNode{
public:
    int val;
    int curMax;
    
    StackNode(int value, int currentMax);
};

StackNode::StackNode(int value, int currentMax){
    val = value;
    curMax = currentMax;
}

int main() {
    
    int n;
    cin >> n;
    
    int input;
    int element;
    int max = 0;
    stack<StackNode> s;
    
    for (int i = 0; i < n; i++){
        cin >> input;
        if (input == 1){
            cin >> element;
            max = std::max(max, element);
            s.push(StackNode(element, max));
        }
        else if (input == 2){
            if (!s.empty()){
                s.pop();
            }
            if (s.empty()){
                max = 0;
            }
            else{
                max = s.top().curMax;
            }
        }
        else{
            if (!s.empty()){
                cout << s.top().curMax << endl;
            }
            
        }
    }
    return 0;
}