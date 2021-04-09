/*
 * @lc app=leetcode id=913 lang=cpp
 *
 * [913] Cat and Mouse
 */

struct state{
    int mouse;
    int cat;
    int turn;
};
// return 1: mouse win
// return 2: cat win
// turn 1 mouse, 2 cat
class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        queue<state>q;
        int n = graph.size();
        vector<vector<vector<int>>>color(n, vector<vector<int>>(n, vector<int>(3,0)));
        for(int i = 1; i < n; ++i){
            for(int j = 1; j < 3; ++j){
                color[0][i][j] = 1;
                q.push(state{0, i, j});
                // 节点状态push到q中
                color[i][i][j] = 2;
                q.push(state{i, i, j});
            }
        }
        while(!q.empty()){
            state s = q.front();q.pop();
            // 找parent节点进队列
            for(auto parent: getParent(graph, s)){
                if(color[parent.mouse][parent.cat][parent.turn]!=0) continue;
                if(color[s.mouse][s.cat][s.turn] == 3 - s.turn){
                    // 如果当前节点的值为1，mouse win，3-2 = 1，turn = 2,说明上一次父节点的turn是1，mouse walk
                    // 则 parent可以win
                    color[parent.mouse][parent.cat][parent.turn] = parent.turn;
                    q.push(parent);
                }
                else{
                    if(childrenWin(graph, parent, color)){
                        // 对手赢 当前状态都输 比如当前turn是1，则是1来走，下一步是2
                        color[parent.mouse][parent.cat][parent.turn] = 3-parent.turn;
                        q.push(parent); 
                    }
                }
                
            }
        }
        return color[1][2][1];
    }
    vector<state>getParent(vector<vector<int>>& graph, state s){
        // if mouse win and s parent.turn = mouse =>s parent mouse win
        // if cat win and s parent.turen = cat => s parent cat win 
        vector<state>allparent;
        if(s.turn == 1){
            // mouse 走
            for(int i= 0;i<graph[s.cat].size(); ++i){
                int mp = graph[s.cat][i];
                if(mp==0) continue;
                allparent.push_back(state{s.mouse, mp, 2});
            }
        }else{
            for(int i = 0; i<graph[s.mouse].size(); ++i){
                int cp = graph[s.mouse][i];
                allparent.push_back(state{cp, s.cat, 1});
            }
        }
        return allparent;
    }
    
    bool childrenWin(vector<vector<int>>& graph, state s, vector<vector<vector<int>>>& color){
        if(s.turn == 1){
            // mouse walks
            for(int i = 0; i<graph[s.mouse].size(); ++i){
                int mc = graph[s.mouse][i];
                if(color[mc][s.cat][2]!=2){
                    return false;
                }
            }
        }
        else{
            // cat walks
            for(int i = 0; i<graph[s.cat].size(); ++i){
                int cc = graph[s.cat][i];
                if(cc==0) continue;
                if(color[s.mouse][cc][1]!=1){
                    return false;
                }
            }
        }
        return true;

    }
};

