//127 µ¥´Ê½ÓÁú 
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set;
        
        for(auto str: wordList)
            set.insert(str);

        queue<pair<string, int>> queue;
        queue.push({beginWord, 1});

        string tmp;
        int step;
        while(!queue.empty()) {
             int len = queue.size();

             for(int i = 0; i < len; ++i) {
                 tmp = queue.front().first;
                 step = queue.front().second;
                 queue.pop();

                 if(tmp == endWord)
                    return step;

                 for(int j = 0; j < tmp.size(); ++j) {
                     char ch = tmp[j];
                     for(char c = 'a'; c <= 'z'; ++c) {
                         if(ch == c)
                            continue;

                        tmp[j] = c;
                        if(set.find(tmp) != set.end()) {
                            queue.push({tmp, step + 1});
                            set.erase(tmp);
                        }
                     }
                     tmp[j] = ch;
                 }
             }
        }
        return 0;
    }
};