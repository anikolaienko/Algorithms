class Solution {
    vector<string> splitStr(string& s) {
        vector<string> res;
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '*') {
                if (i - j) res.push_back(s.substr(j, i - j));
                while (i < s.size() && s[i] == '*') i++;
                j = i;
            }
        }
        
        if (s.size() && s.back() != '*')
            res.push_back(s.substr(j, s.size() - j));
        
        return res;
    }
    
    bool findSubstr(string& s, int& pos, string& part) {
        // TODO: implement Boyer-Moore algorithm
        if (s.size() < part.size()) return false;
        int i = pos, j = 0;
        cout << "Searching for: " << part << " in: " << s << " starting: " << pos << endl;
        for (; i < s.size() - part.size() && j < part.size(); ++i, ++j) {
            if (part[j] != '.' && part[j] != s[i]) j = -1;
        }
        cout << "Part found result: " << (j == part.size()) << endl;
        pos = i;
        return j == part.size();
    }
    
public:
    bool isMatch(string s, string p) {
        cout << "Splitting: " << p << endl;
        vector<string> parts = splitStr(p);
        cout << "Successfully split" << endl;
        int pos = 0;
        for (int i = 0; i < parts.size(); ++i) {
            if (!findSubstr(s, pos, parts[i]))
                return false;
            if (i == 0 && p[0] != '*' && pos != parts[i].size())
                return false;
        }
        cout << "Returning the result!" << endl;
        return pos == s.size() || p.size() && p.back() == '*';
    }
};