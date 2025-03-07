//Time Complexity - O(N^3)
//Space Complexity - O(N)

class Solution {
public:
vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();  
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;  
        set<vector<int>> store;
		
        for(int i = 0 ; i < n; i++){
		
            for(int j = i + 1; j < n ; j++){
			
                int new_target  =  target - nums[i] - nums[j];
                
                int lp = j+1 , rp = n-1;
                
                while(lp < rp){
				
                    int sum = nums[lp] + nums[rp];
                    
                    if(sum > new_target) 
                        rp--;
                    else if(sum < new_target ) 
                        lp++;
                    else  {
                        store.insert({nums[i] , nums[j] , nums[lp] , nums[rp]});
                        lp++;
                        rp--;
                    };
                }
            }
        }
		
    for(auto i : store){
        ans.push_back(i); 
    }
    
    return ans;
  }
};