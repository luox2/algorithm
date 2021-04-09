/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>>res;
        unordered_set<string>dict(wordList.begin(), wordList.end());
        vector<string>p{beginWord};
        queue<vector<string>>paths;
        paths.push(p);
        int level = 1, minLevel = INT_MAX;
        unordered_set<string>words;
        // ?
        while(!path.empty()){
            auto t = path.front();
            path.pop();
            if(t.size()>level){
                for(auto word: words){
                    dict.erase(word);
                }
                words.clear();
                level = t.size();
                // 少了
                if(level>minLevel) break;
            }
            else{
                auto last = t.back();
                for(int i = 0; i<last.size(); ++i){
                    string newword = last;
                    for(char j = 'a'; j<='z'; ++j){
                        newword[i] = j;
                        if(!dict.count(newword) || newword==last) continue;
                        words.insert(newword);
                        vector<string>nextpath = t;
                        nextpath.push_back(newword);
                        if(newword==endWord){
                            res.push_back(nextpath);
                            minLevel = level;
                        }
                        else paths.push(nextpath);
                    }
                }

            }
        }
        return res;    
    }
};

