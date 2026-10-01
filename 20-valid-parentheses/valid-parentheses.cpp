class Solution {
public:
    bool isValid(string s) {
        bool changed = true;
        while (changed) {
            changed = false;
            for (int i = 0; i + 1 < s.size(); i++) {
                if ((s[i] == '(' && s[i+1] == ')') ||
                    (s[i] == '{' && s[i+1] == '}') ||
                    (s[i] == '[' && s[i+1] == ']')) {
                    s.erase(i, 2); 
                    changed = true;
                    break; 
                }
            }
        }
        return s.empty();
    }
};

 
