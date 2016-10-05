class MedianFinder {
public:
    vector<int> maxH, minH;
    // Adds a number into the data structure.
    void addNum(int num) {
        auto comp = [](int const& a, int const& b) { return a > b; };
        if (minH.empty()) {
            minH.push_back(num);
            return;
        }
        if (num > minH.front()) {
            minH.push_back(num);
            push_heap(minH.begin(), minH.end(), comp);
        } else {
            maxH.push_back(num);
            push_heap(maxH.begin(), maxH.end());
        }
        adj();
    }

    // Returns the median of current data stream
    double findMedian() {
        if (minH.size() > maxH.size()) {
            return minH.front();
        } else {
            return (maxH.front() + minH.front()) / 2.0;
        }
    }

    void adj() {
        auto comp = [](int const& a, int const& b) { return a > b; };
        while (minH.size() > maxH.size() + 1) {
            pop_heap(minH.begin(), minH.end(), comp);
            maxH.push_back(minH.back());
            minH.pop_back();
            push_heap(maxH.begin(), maxH.end());
        }
        while (maxH.size() > minH.size()) {
            pop_heap(maxH.begin(), maxH.end());
            minH.push_back(maxH.back());
            maxH.pop_back();
            push_heap(minH.begin(), minH.end(), comp);
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
