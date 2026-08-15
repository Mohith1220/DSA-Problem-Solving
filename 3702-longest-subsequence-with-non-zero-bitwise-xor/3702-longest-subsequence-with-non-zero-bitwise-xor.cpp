class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
     bool t = false;
     int to = 0;
     for(int i =0;i<nums.size();i++)
     {
        to ^= nums[i];
        if(nums[i]!=0)
        {
            t = true;
        }
     }   
     if(!t)
     {
        return 0;
     }
     if(to !=0)
     {
        return nums.size();
     }
     return nums.size()-1;
    }
};