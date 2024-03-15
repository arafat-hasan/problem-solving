class Solution {
public:
    string reverseWords(string s) {
        string res;
        for(int i = 0; i < (int) s.length();){
            int j = i;
            while(j < (int) s.length()){
                if(s[j] == ' ') break;
                j++;
            }

            i = j + 1;

            for(j--; j >= 0; j--){
                if(s[j] == ' ') break;
                res.push_back(s[j]);
            }

            if(i < s.length()) res.push_back(' ');
        }
        return res;
    }
};