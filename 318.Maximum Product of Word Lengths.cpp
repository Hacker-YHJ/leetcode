class Solution {
public:
    int maxProduct(vector<string>& words) {
        int size = words.size();
        vector<unsigned int> sign(size);
        vector<unsigned int> len(size);
        int m = 0;
        int index = 0;
        for (auto i = words.begin(); i != words.end(); ++i) {
          sign[index] = 0;
          len[index] = (*i).length();
          for (auto j = (*i).begin(); j != (*i).end(); ++j) {
            sign[index] |= 1 << (*j - 'a');
          }
          ++index;
        }
        for (auto i = 0; i < size; ++i) {
            for (auto j = i+1; j < size; ++j) {
                if (sign[i] & sign[j]) continue;
                m = len[i]*len[j] > m ? len[i]*len[j] : m; 
            }
        }
        return m;
    }
};

// 128ms
