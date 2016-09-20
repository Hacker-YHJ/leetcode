class Solution {
private:
    int count;
    int major;
public:
    int majorityElement(vector<int>& nums) {
        count = 1;
        major = nums[0];
        for (auto i = nums.begin()+1, j = nums.end(); i != j; ++i) {
            if (*i == major) ++count;
            else if (count && *i != major) --count;
            else major = *i, ++count;
        }
        return major;
    }
};

//16ms 85%
