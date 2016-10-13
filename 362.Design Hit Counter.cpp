class HitCounter {
    int count = 0;
    deque<pair<int, int> > stamps;
public:
    /** Initialize your data structure here. */
    HitCounter() {

    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        if (!stamps.empty() && stamps.back().first == timestamp) {
            stamps.back().second++;
        } else {
            stamps.push_back(make_pair(timestamp, 1));
        }
        count++;
        return;
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!stamps.empty() && stamps.front().first + 300 <= timestamp) {
            count -= stamps.front().second;
            stamps.pop_front();
        }
        return count;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
