/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());
        if(!st.count(endWord)) return 0;
        queue<string>q{{beginWord}};
        int res = 0;
        while(!q.empty()){
            for(int qlen = q.size()-1; qlen>=0; --qlen){
                auto word = q.top(); q.pop();
                for(int i = 0; i<t.size(); ++i){
                    string newword = word;
                    for(char j = 'a'; j<='z'; ++j){
                        newword[i] = j;
                        if(newword==endWord) return res+1;
                        if(st.count(newword)){
                            q.push(newword);
                            st.erase(newword);
                        }
                    }
                }
            }
            res++;
        }
        return 0;
    }
};

