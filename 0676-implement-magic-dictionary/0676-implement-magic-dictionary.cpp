class MagicDictionary {
public:
    unordered_set<string> s;
    MagicDictionary() {
        ios_base::sync_with_stdio(false); cin.tie(0);
    }
    
    void buildDict(vector<string> dictionary) {
        s = unordered_set<string>(dictionary.begin(), dictionary.end());
    }
    
    bool search(string searchWord) {
        string tmp = searchWord;
        int n = searchWord.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 26; j++) {
                tmp[i] = 'a' + j;
                if(tmp[i] == searchWord[i]) continue;
                if(s.count(tmp)) return true;
            }
            tmp[i] = searchWord[i];
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */