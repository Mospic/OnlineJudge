class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
        {
            return s;
        }
        string str_ans;
        int pos = 0, length = s.size(), temp = length;
        int numCols = 0;
        while(temp >= 0)
        {
            if(temp >= 2 * numRows - 2)
            {
                numCols += numRows - 1;
                temp -= 2 * numRows - 2;
            }
            else if(temp > numRows)
            {
                numCols += 1 + (temp - numRows);
                temp = -1;
            }
            else
            {
                numCols += 1;
                temp = -1;
            }
        }
        char A[numRows][numCols];
        memset(A, 0, numRows * numCols);

        for(auto i = 0; i < numCols; i++)
        {
            if(i % (numRows - 1) == 0)
            {
                for(auto j = 0; j < numRows; j++)
                {
                    if(pos < length)
                    {
                        A[j][i] = s[pos];
                        pos++;
                    }
                }
            }
            else
            {
                if(pos < length)
                {
                    A[numRows - 1 - i % (numRows - 1)][i] = s[pos];
                    pos++;
                }
            }
        }
        
        for(auto i = 0; i < numRows; i++)
        {
            for(auto j = 0; j < numCols; j++)
            {
                if(A[i][j] > 0)
                    str_ans.push_back(A[i][j]);
            }
        }
        return str_ans;
    }
};