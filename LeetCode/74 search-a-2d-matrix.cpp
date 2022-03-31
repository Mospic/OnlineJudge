class Solution {
private:
    bool BinarySearch(vector<vector<int>>& matrix, int target, int low, int high, int length)
    {
        if(low > high)
            return false;
        int mid = (low + high) / 2;
        if(matrix[mid / length][mid % length] == target)
            return true;
        return BinarySearch(matrix, target, low, mid - 1, length) || BinarySearch(matrix, target, mid + 1, high, length);
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int length = matrix[0].size();
        int array_length = length * matrix.size(); 
        return BinarySearch(matrix, target, 0, array_length - 1, length);
    }
};