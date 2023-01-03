
class Solution {
public:
    
        int threeSumClosest(vector<int>& nums, int target) {
    
    int n=nums.size();
    int Res;
    int diff=INT_MAX;
    
    if(n<3) return {};
    
    sort(nums.begin(),nums.end());
    
    for(int i=0;i<n;i++)
    {
        int j=i+1;
        int k=n-1;
    
        while(j<k)
        {
             int sum=nums[i]+nums[j]+nums[k];
            
            if(abs(sum-target) < diff)
            {
                diff=abs(sum-target);
                Res=sum;
            }
            
            if(sum > target) k--;
            
            else j++;
        }
    }        
    
   return Res;
}
    
};
