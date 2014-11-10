/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/
class MinStack {
    stack<int> main;
    stack<int> min;
  public:
    void push(int x) {
        if (min.empty() || (!min.empty() && min.top() >= x)) {
            min.push(x);
        }
        main.push(x);
    }

    void pop() {
        if (!main.empty()) {
            if (min.top() == main.top()) {
                min.pop();
            }
            main.pop();
        }
    }

    int top() {
        if (!main.empty()) {
            return main.top();
        }
        return -1;
    }

    int getMin() {
        if (!min.empty()) {
            return min.top();
        }
        return -1;
    }
};
