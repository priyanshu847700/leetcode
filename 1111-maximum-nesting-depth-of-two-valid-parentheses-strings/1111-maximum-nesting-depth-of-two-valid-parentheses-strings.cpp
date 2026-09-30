class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> ans;

        int depth=0;
        for(int i=0;i<seq.size();i++){
            char ch=seq[i];

            if(ch=='('){
                depth++;
                if(depth % 2 == 0){
                    ans.push_back(1);
                }
                else{
                    ans.push_back(0);
                }
                
            }
            else{
                if(depth % 2 == 0){
                    ans.push_back(1);
                }
                else{
                    ans.push_back(0);
                }
                depth--;
            }
        }
        return ans;
    }
};