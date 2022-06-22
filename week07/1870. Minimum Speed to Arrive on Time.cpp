// https://leetcode.com/problems/minimum-speed-to-arrive-on-time/
// Time Complexity: O(N*log(M)) // N for dist array, M is for answer range 1 to 10^7
// Space Complexity: O(1)

class Solution
{
    bool canReachInTime(const vector<int>& dist, const double hour, int speed)
    {
        double time = 0;
        
        for (int i = 0; i<dist.size() - 1; ++i)
            time += ((dist[i] + speed - 1) / speed);
        
        time += ((double)dist.back()) / speed;
        
        return time <= hour;
    }
    
public:
    int minSpeedOnTime(vector<int>& dist, double hour)
    {
        int n = dist.size();
        
        if (hour <= (double)(n - 1))
            return -1;
        
        int low = 1, high = 1e7, mid;
        while (low < high)
        {
            mid = (low + high)/2;
            
            if (canReachInTime(dist, hour, mid))
                high = mid;
            else
                low = mid + 1;
        }
        
        return high;
    }
};