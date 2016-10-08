class PhoneDirectory {
public:
    vector<bool> m;
    deque<int> q;
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) : m(maxNumbers, true) {
        for (int i = 0; i < maxNumbers; ++i) q.push_back(i);
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (q.empty()) return -1;
        auto r = q.front();
        q.pop_front();
        m[r] = false;
        return r;
    }

    /** Check if a number is available or not. */
    bool check(int number) {
        return m[number];
    }

    /** Recycle or release a number. */
    void release(int number) {
        if (m[number]) return;
        m[number] = true;
        q.push_back(number);
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
