#include "graph.cpp"

double answer(int& V, string a, string b, map<string, list<pair<string,double>>>& adj){
    // run a dfs from a to b maintaining the current stack
    // answer is the multiplication of consecutive edges
    string s = a;
    map<string,double> ans;
    map<string,bool> visited;
    for(auto x : adj){
        visited[x.first] = false;
    }
    stack<string> wait;
    wait.push(s);
    ans[s] = 1;
    while(!wait.empty()){
        string tmp = wait.top(); wait.pop();
        if(!visited[tmp]){
            if(tmp == b){
                wait.push(tmp);
                break;
            }else{
                for(auto li : adj[tmp]){
                    wait.push(li.first);
                    ans[li.first] = ans[tmp] * li.second;
                }
            }
            visited[tmp] = true;
        }
    }
    return ans[b];
}

int main(){
    vector<vector<string>> equations = {{"a","b"},{"b","c"}};
    vector<double> values = {2.0, 3.0};
    vector<vector<string>> queries = {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
    set<string> v; // This set keeps track of the vertices
    map<string, list<pair<string,double>>> mp; // This map works as a weighted adjacency list
    int n = values.size(); // The no of equations
    for(int i = 0; i < n; i++){
        v.insert(equations[i][0]); v.insert(equations[i][1]); // Update the set of vertices
        // Update the adjacency list
        pair<string,double> tmp = {equations[i][1], values[i]};
        pair<string,double> revtmp = {equations[i][0], 1/values[i]};
        mp[equations[i][0]].push_back(tmp);
        mp[equations[i][1]].push_back(revtmp);
    }
    int nv = v.size();
    // Answer the queries
    for(auto q : queries){
        string a = q[0], b = q[1];
        if(v.find(a) != v.end() && v.find(b) != v.end()){
            if(a == b){
                cout << a << '/' << b << " is " << 1 << '\n';
            }else{
                cout << a << '/' << b << " is " << answer(nv, a, b, mp) << '\n';
            }
        }else{
            cout << -1.0 << '\n';
        }
    }
}