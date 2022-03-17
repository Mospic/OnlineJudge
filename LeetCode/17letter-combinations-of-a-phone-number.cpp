class Solution {
private:
    int num_mapping[8] = {3,3,3,3,3,4,3,4};
    pair<char, string> mapping[8] ={{'2', "abc"},{'3',"def"},{'4', "ghi"}, {'5', "jkl"}, {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    vector<string> ans;
    
    void DFS(int index, string digits, string str)
    {
        if(index == digits.size())
        {
            ans.push_back(str);
            return ;
        }
        else
        {
            for(auto i = 0; i < num_mapping[digits[index] - '0' - 2]; i++)
            {
                str.push_back(mapping[digits[index] - '0' - 2].second[i]);
                DFS(index + 1, digits ,str);
                str.pop_back();
            }
        }
            
    }

public:
    vector<string> letterCombinations(string digits) {
        string str;
        if(digits.size() == 0)
            return ans;
        DFS(0, digits, str);
        return ans;
    }
};