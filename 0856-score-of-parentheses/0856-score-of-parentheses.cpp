class Solution {
public:
    int scoreOfParentheses(string s) {
        vector<int> vec;

        int score=0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                vec.push_back(score);
                score = 0;
            }
            else{
                if(s[i-1]=='('){   // () -> simple case
                    score= vec.back()+1;
                }
                else{              // (()) -> nested case
                    score=vec.back() +( 2*score );
                }
                vec.pop_back();
            }
        }
        return score;
    }
};