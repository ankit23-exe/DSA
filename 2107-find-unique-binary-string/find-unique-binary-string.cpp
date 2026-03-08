class Solution {
public:
    string stringformer(string &temp,vector<string>& nums){
        if(temp.size()==nums.size()){
            if(find(nums.begin(),nums.end(),temp) == nums.end()){
                return  temp;
            } 
            return "";   
        }
        
        temp.push_back('0');
        string res = stringformer(temp, nums);
        if(res != "") return res;
        temp.pop_back();

        temp.push_back('1');
        res = stringformer(temp, nums);
        if(res != "") return res;
        temp.pop_back();

        return "";
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string  temp="";
        return stringformer(temp,nums);
    }
};