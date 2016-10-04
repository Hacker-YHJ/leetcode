class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    auto add = [](const int &a, const int &b) -> int { return a + b; };
    auto sub = [](const int &a, const int &b) -> int { return a - b; };
    auto multi = [](const int &a, const int &b) -> int { return a * b; };
    auto div = [](const int &a, const int &b) -> int { return a / b; };
    unordered_map<char, function<int(int,int)> > ops({{'+', add}, {'-', sub}, {'*', multi}, {'/', div}});
    stack<int> s;
    for (auto const& i : tokens) {
      if (i.length() == 1 && ops.find(i[0]) != ops.end()) {
        auto a = s.top(); s.pop();
        auto b = s.top(); s.pop();
        s.push(ops[i[0]](b, a));
      } else {
        s.push(stoi(i));
      }
    }
    return s.top();
  }
};
