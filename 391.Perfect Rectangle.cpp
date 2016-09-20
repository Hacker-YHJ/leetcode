struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 + 31 * h2;
    }
};

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_map<pair<int, int>, int, pair_hash> m;
        pair<int, int> topLeft(0x7FFFFFFF, 0x7FFFFFFF), bottomRight(0x80000000, 0x80000000);
        int accu = 0;
        for (auto i = rectangles.begin(), j = rectangles.end(); i < j; ++i) {
            pair<int, int> tl((*i)[0], (*i)[1]);
            pair<int, int> tr((*i)[2], (*i)[1]);
            pair<int, int> bl((*i)[0], (*i)[3]);
            pair<int, int> br((*i)[2], (*i)[3]);

            topLeft.first = topLeft.first > tl.first ? tl.first : topLeft.first;
            topLeft.second = topLeft.second > tl.second ? tl.second : topLeft.second;

            bottomRight.first = bottomRight.first < br.first ? br.first : bottomRight.first;
            bottomRight.second = bottomRight.second < br.second ? br.second : bottomRight.second;

            accu += (br.first - tl.first) * (br.second - tl.second);
            auto iter = m.find(tl);
            if (iter != m.end()) {
                if (iter -> second & 0x1) return false;
                iter -> second |= 0x1;
            }
            else m[tl] = 0x1;

            iter = m.find(tr);
            if (iter != m.end()) {
                if ((iter -> second) & 0x2) return false;
                iter -> second |= 0x2;
            }
            else m[tr] = 0x2;

            iter = m.find(bl);
            if (iter != m.end()) {
                if ((iter -> second) & 0x4) return false;
                iter -> second |= 0x4;
            }
            else m[bl] = 0x4;

            iter = m.find(br);
            if (iter != m.end()) {
                if ((iter -> second) & 0x8) return false;
                iter -> second |= 0x8;
            }
            else m[br] = 0x8;
        }
        int tlc = 0, trc = 0, blc = 0, brc = 0;
        for (auto i = m.begin(), j = m.end(); i != j; ++i) {
            switch (i -> second) {
                case 0x1: ++tlc;
                          break;
                case 0x2: ++trc;
                          break;
                case 0x4: ++blc;
                          break;
                case 0x8: ++brc;
                          break;
            }
        }
        if (tlc != 1 || trc != 1 || blc != 1 || brc != 1) return false;
        return (accu == (bottomRight.first - topLeft.first) * (bottomRight.second - topLeft.second));
    }
};
