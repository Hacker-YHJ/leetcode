class MovingAverage {
  deque<int> q;
  double avg = 0;
  int mSize;
public:
  /** Initialize your data structure here. */
  MovingAverage(int size) : mSize(size) {
  }

  double next(int val) {
    double n = avg * (q.size()) + val;
    if (q.size() == mSize) {
      n -= q.front();
      q.pop_front();
    }
    q.push_back(val);
    avg = n / q.size();
    return avg;
  }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
