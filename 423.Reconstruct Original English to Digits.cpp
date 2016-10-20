class Solution {
public:
    string originalDigits(string s) {
        int arr[26];
        int count[10];
        memset(count, 0, sizeof(count));
        memset(arr, 0, sizeof(arr));
        for (auto const& c : s) {
            arr[c - 'a']++;
        }
        // 0
        count[0] = arr['z' - 'a'];
        arr['e' - 'a'] -= arr['z' - 'a'];
        arr['r' - 'a'] -= arr['z' - 'a'];
        arr['o' - 'a'] -= arr['z' - 'a'];
        arr['z' - 'a'] = 0;
        // 2
        count[2] = arr['w' - 'a'];
        arr['t' - 'a'] -= arr['w' - 'a'];
        arr['o' - 'a'] -= arr['w' - 'a'];
        arr['w' - 'a'] = 0;
        // 4
        count[4] = arr['u' - 'a'];
        arr['f' - 'a'] -= arr['u' - 'a'];
        arr['o' - 'a'] -= arr['u' - 'a'];
        arr['r' - 'a'] -= arr['u' - 'a'];
        arr['u' - 'a'] = 0;
        // 5
        count[5] = arr['f' - 'a'];
        arr['e' - 'a'] -= arr['f' - 'a'];
        arr['i' - 'a'] -= arr['f' - 'a'];
        arr['v' - 'a'] -= arr['f' - 'a'];
        arr['f' - 'a'] = 0;
        // 7
        count[7] = arr['v' - 'a'];
        arr['e' - 'a'] -= 2*arr['v' - 'a'];
        arr['s' - 'a'] -= arr['v' - 'a'];
        arr['n' - 'a'] -= arr['v' - 'a'];
        arr['v' - 'a'] = 0;
        // 6
        count[6] = arr['s' - 'a'];
        arr['i' - 'a'] -= arr['s' - 'a'];
        arr['x' - 'a'] -= arr['s' - 'a'];
        arr['s' - 'a'] = 0;
        // 8
        count[8] = arr['g' - 'a'];
        arr['e' - 'a'] -= arr['g' - 'a'];
        arr['i' - 'a'] -= arr['g' - 'a'];
        arr['h' - 'a'] -= arr['g' - 'a'];
        arr['t' - 'a'] -= arr['g' - 'a'];
        arr['g' - 'a'] = 0;
        // 9
        count[9] = arr['i' - 'a'];
        arr['n' - 'a'] -= 2*arr['i' - 'a'];
        arr['e' - 'a'] -= arr['i' - 'a'];
        arr['i' - 'a'] = 0;
        // 1
        count[1] = arr['o' - 'a'];
        arr['n' - 'a'] -= arr['o' - 'a'];
        arr['e' - 'a'] -= arr['o' - 'a'];
        arr['o' - 'a'] = 0;
        // 3
        count[3] = arr['r' - 'a'];
        arr['t' - 'a'] -= arr['r' - 'a'];
        arr['h' - 'a'] -= arr['r' - 'a'];
        arr['e' - 'a'] -= 2*arr['r' - 'a'];
        arr['r' - 'a'] = 0;

        string res;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < count[i]; ++j) {
                res += to_string(i);
            }
        }
        return res;
    }
};
