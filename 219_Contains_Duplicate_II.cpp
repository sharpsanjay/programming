class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        /* internet solution that looks very simple*/
                unordered_map<int,int> mp;
        int n = nums.size();
        
        for(int i=0; i<n; i++)
        {
            // mp.count() will tell whatever ith index that I want, have I seen it before?
            if(mp.count(nums[i]))
            {
                // if I have already seen this number, then check for condition abs(i - j) <= k
                if(abs(i-mp[nums[i]])<=k)
                    return true;
            }
            // if I have not seen this number before, insert the number with its position in the map
            // and if the number is already present in the map, then update the position of that number
            mp[nums[i]] = i;
        }
        // after the complete traversal, if we don't find a pair to satisfy the condition, return false
        return false;
    }
        
        /* Sliding window Method where we maintain the set of K*/

        /*std::map<int, int>window;
        if (k==0)
        return false;
        for (int i=0;i < nums.size(); i++){
            if(window.find(nums.at(i)) != window.end()){
                return true;
            }else{
                if(window.size()==k){
                    window.erase(nums.at(i-k));
                }
                window.insert(make_pair(nums.at(i),i));
                }
            }
            return false;


        }*/

        
        /* hashmap Method to see if we already visited the number 
        std::map<int,int>scanned_numbers;
        scanned_numbers.insert(std::make_pair(nums.at(0),0));
        for (int i=1; i < nums.size(); i++){
            if(scanned_numbers.find(nums.at(i)) != scanned_numbers.end()){
                int index = scanned_numbers[nums.at(i)];
                if (i-index <=k)
                    return true;
            }
            scanned_numbers[nums.at(i)] = i;
        } 
        return false;
    }*/
        
        
        
        /* Brute Force method that is not acceptable 
        int size = nums.size();
        for(int i = 0; i < size;i++){
            int j = i+1;
            while (j-i <= k && j>i && j< size ){
                if(nums.at(i) == nums.at(j)){
                    return true;   
                }
                j++;           
            }
        }
        return false;
    } */
};
