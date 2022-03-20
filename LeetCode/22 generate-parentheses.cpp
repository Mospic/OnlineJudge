class Solution {
    vector<string> vec;
    void generate(int n, int m, string str)
    {
        if(n == 0 && m == 0)
        {
            vec.push_back(str);
            return ;
        }
        if(n > 0)
        {
            generate(n - 1, m, str + "(");
        }
        if(m > n)
        {
            generate(n, m - 1, str + ")");
        }
        return ;
    }
public:
    vector<string> generateParenthesis(int n) {
        generate(n, n, "");
        return vec;
    }
};