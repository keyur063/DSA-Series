#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> s(wordList.begin(), wordList.end());
    queue<vector<string>> q;
    q.push({beginWord});

    vector<string> levelVec;
    levelVec.push_back(beginWord);

    int level = 0;
    vector<vector<string>> ans;

    while(!q.empty()){
        //vec inside queue
        vector<string> vec = q.front();
        q.pop();

        //delete words from set if level ++ and clear levelVec
        if(vec.size() > level){
            level++;
            for(auto it: levelVec){
                s.erase(it);
            }
            levelVec.clear();
        }

        string word = vec.back();
        if(word == endWord){
            if((ans.size() == 0) || (ans[0].size() == vec.size())){
                ans.push_back(vec);
            }
        }

        for(int i=0; i<word.size(); i++){
            char org = word[i];

            for(char ch='a'; ch<='z'; ch++){
                word[i] = ch;

                if(s.find(word) != s.end()){
                    vec.push_back(word);
                    q.push(vec);
                    levelVec.push_back(word);
                    vec.pop_back();
                }
                word[i] = org;
            }
        }
    }
    return ans;
}

int main(){
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    vector<vector<string>> ans = findLadders("hit", "cog", wordList);

    for(auto it: ans){
        for(string s: it){
            cout<<s<<" ";
        }
        cout<<endl;
    }
}