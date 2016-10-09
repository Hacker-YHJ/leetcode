class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        res += to_string(strs.size()) + ",";
        for (auto const& s : strs) { res += to_string(s.size()) + ","; }
        for (auto const& s : strs) { res += s; }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        stringstream ss(s);
        string v;
        vector<string> res;

        getline(ss, v, ',');
        int size = stoi(v);
        cout << size << endl;

        vector<int> sizes(size);
        for (int i = 0; i < size; ++i) {
            getline(ss, v, ',');
            sizes[i] = stoi(v);
            cout << sizes[i] << ' ';
        }
        cout << endl;

        getline(ss, v);
        int idx = 0;
        for (int i = 0; i < size; ++i) {
            res.push_back(v.substr(idx, sizes[i]));
            idx += sizes[i];
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
