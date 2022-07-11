class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int middle_idx = (nums1.size() + nums2.size()) / 2;
        
        // two iterators to help in search
        int nums1_idx = 0, nums2_idx = 0;
        
        int middle_val1 = 0 , middle_val2 = 0;
        
        for(int i = 0; i <= middle_idx; i++)
        {
            middle_val2 = middle_val1;
            
            if( nums1_idx == nums1.size() )
            {
                middle_val1 = nums2[nums2_idx++];
            }
            else if( nums2_idx == nums2.size() )
            {
                middle_val1 = nums1[nums1_idx++];
            }
            else if( nums1[nums1_idx] <= nums2[nums2_idx] )
            {
                middle_val1 = nums1[nums1_idx++];
            }
            else
            {
                middle_val1 = nums2[nums2_idx++];
            }
            
            //cout << middle_val1 << "  " << middle_val2 << endl;
        }
        
        
        // if n+m is odd 
        if( (nums1.size() + nums2.size()) % 2 != 0 )
        {
            return middle_val1;
        }
        // if it's even
        else
        {
            return ( middle_val1 + middle_val2) / 2.0;
        }
        
    }
};