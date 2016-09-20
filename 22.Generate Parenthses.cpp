class Solution {
private:
    vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        res.clear();
        addingpar("", n, 0);
        return res;
    }
    void addingpar(string str, int n, int m){
        if(n==0 && m==0) {
            res.push_back(str);
            return;
        }
        if(m > 0){ addingpar(str+")", n, m-1); }
        if(n > 0){ addingpar(str+"(", n-1, m+1); }
    }
};
//0ms 36%
