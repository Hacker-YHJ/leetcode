class PhoneDirectory {
public:
    bool *m;
    int *q;
    int s = 0;
    int e = 0;
    int capa;
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        m = new bool[maxNumbers];
        capa = maxNumbers + 1;
        q = new int[capa];
        for (int i = 0; i < maxNumbers; ++i) {
            q[i] = i;
            m[i] = true;
        }
        s = 0;
        e = maxNumbers;
    }

    ~PhoneDirectory() {
        delete[] m;
        delete[] q;
    }

    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (e == s) return -1;
        auto r = q[s++ % capa];
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
        q[e++ % capa] = number;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
