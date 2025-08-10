#include <iostream>
#include <vector>
#include <map>
using namespace std;

int longestSubstring(string& s, int k){
    int n = s.length();
    int l=0, r=0, maxLen=0;
    map<char, int> m;

    while(r < n){
        m[s[r]]++;

        if(m.size() > k){
            m[s[l]]--;

            if(m[s[l]]  == 0)
                m.erase(s[l]);
            l++;
        }

        if(m.size() <= k)
            maxLen = max(maxLen, r-l+1);
        r++;
    }
    return maxLen;
}

int main(){
    string s = "aaabbccd";

    cout << longestSubstring(s, 2) << endl;
}