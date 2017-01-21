#include <cmath>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int findMax (int first, int second, int third);
bool isEqualHeights (int x, int y, int z);

int main() {
    
    //* stackXHeight | stackXArray | stackX  *//
    
    //* Grab max heights *//
    int stack1Height, stack2Height, stack3Height;
    cin >> stack1Height >> stack2Height >> stack3Height;
    
    //* Insert cylinder heights into array in reverse since this problem is stupid. *//
    int stack1Array[stack1Height];
    for (int i=stack1Height-1; i>=0; i--) {cin >> stack1Array[i];}
    
    int stack2Array[stack2Height];
    for (int i=stack2Height-1; i>=0; i--) {cin >> stack2Array[i];}
    
    int stack3Array[stack3Height];
    for (int i=stack3Height-1; i>=0; i--) {cin >> stack3Array[i];}
    
    //* Create stack of current heights so we know the total height at/after each cylinder *//
    stack <int> stack1, stack2, stack3;
    int currentHeight = 0;
    for (int i=0; i<stack1Height; i++) {
        currentHeight += stack1Array[i];
        stack1.push(currentHeight);
    }
    currentHeight = 0;
    for (int i=0; i<stack2Height; i++) {
        currentHeight += stack2Array[i];
        stack2.push(currentHeight);
    }
    currentHeight = 0;
    for (int i=0; i<stack3Height; i++) {
        currentHeight += stack3Array[i];
        stack3.push(currentHeight);
    }
    
    //* Find max common total height *//
    bool found = false;
    while (!stack1.empty() && !stack2.empty() && !stack3.empty()) {
        found = isEqualHeights (stack1.top(), stack2.top(), stack3.top());
        if (found) {
            cout << stack1.top();
            return 0;
        }
        int max = findMax (stack1.top(), stack2.top(), stack3.top());
        if (max == 1)       stack1.pop();
        else if (max == 2)  stack2.pop();
        else                stack3.pop();
    }
    
    cout << 0; // if one of them is empty
    return 0;
}

bool isEqualHeights (int x, int y, int z) {
    if (x == y && x == z) return true;
    else return false;
}

int findMax (int first, int second, int third) {
    int max;
    max = first>second ? first:second;
    max = max>third ? max:third;
    
    if (max == first) return 1;
    else if (max == second) return 2;
    else return 3;
}