/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        //We could either do dfs or bfs to get the value!
        int res=0;
        //This saves the id of subordinate
        queue<int> q;
        q.push(id);
        while(!q.empty()){
            int ID = q.front(),found;
            //Now finding this ID in employees vector
            for(int i=0;i<employees.size();i++){
                if(employees[i]->id==ID){
                    found = i;
                    break;
                }
            }
            res += employees[found]->importance;
            q.pop();
            for(int i=0;i<(employees[found]->subordinates).size();i++)
                q.push(employees[found]->subordinates[i]);
        }
        return res;
    }
};