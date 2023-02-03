int shortestPathLength(vector<vector<int>>& graph) {
        if(graph.size()==1) return 0;
        string allvisited(graph.size(),'1');
        queue<pair<int,string>> q;
        string curr(graph.size(),'0');
        set<pair<int,string>> vis;
        for(int i=0;i<graph.size();i++){
            curr[i]='1';
            q.push({i,curr});
            vis.insert({i,curr});
            curr[i]='0';
        }
        int step=0,v;
        char tempchr;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                v=q.front().first;
                curr=q.front().second;
                q.pop();
                for(int i=0;i<graph[v].size();i++){
                    tempchr=curr[graph[v][i]];
                    curr[graph[v][i]]='1';
                    if(curr==allvisited) return step+1;
                    if(!vis.count({graph[v][i],curr})) {
                        q.push({graph[v][i],curr});
                        vis.insert({graph[v][i],curr});
                        }
                        curr[graph[v][i]]=tempchr;
                }
            }
            step++;
        }
        return -1;
    }
