#include <stack>
using namespace std;

class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        while (!data.empty()) {
            aux.push(data.top());
            data.pop();
        }
        aux.push(x);

        while (!aux.empty()) {
            data.push(aux.top());
            aux.pop();
        }
        
    }
    
    int pop() {
        if (data.empty()) {
            return -1;
        }
        int res = -1;
        res = data.top();
        data.pop();
        return res;
    }
    
    int peek() {
        return data.empty() ? -1 : data.top();
    }
    
    bool empty() {
        return data.empty();
    }

private:
    stack<int> aux;
    stack<int> data;
};