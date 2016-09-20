class MinStack {
private:
    stack<int> ele;
    stack<int> minEle;
public:
    void push(int x) {
        int currMin = minEle.empty() ? 0x7FFFFFFF : minEle.top();
        currMin = currMin < x ? currMin : x;
        minEle.push(currMin);
        ele.push(x);
    }

    void pop() {
        ele.pop();
        minEle.pop();
    }

    int top() {
        return ele.top();
    }

    int getMin() {
        return minEle.top();
    }
};

// 48ms 5%
