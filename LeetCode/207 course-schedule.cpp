class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);       //拓扑排序
        vector<vector<int>> map(numCourses);
        int count = 0;   
        for(auto vec: prerequisites)        //创建邻接表，创建入度表
        {
            indegree[vec[0]]++;
            map[vec[1]].push_back(vec[0]);
        }
        queue<int> q;
        for(auto i = 0; i < numCourses; i++)    //初始化队列，使入度为0的结点进入队列
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int i = q.front();
            q.pop();
            count++;
            for(auto k:map[i])
            {
                indegree[k]--;
                if(indegree[k] == 0)
                {
                    q.push(k);
                }
            }        
        }
        if(count == numCourses)
            return true;
        else return false;
    }
};