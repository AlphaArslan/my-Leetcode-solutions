class Solution {
public:
    int maxArea(vector<int>& height) {
        
        /*
            two pointers algorithm.
        */
        
        int n = height.size();
        //cout << "length: " << n << endl;
        int max_area = 0, area, shorter;
        
        // start with the widest container
        int left_idx = 0, right_idx = n - 1, w = n - 1;
        while(w)
        {
            if(height[left_idx] <= height[right_idx])
            {
                shorter = height[left_idx++];
            }
            else
            {
                shorter = height[right_idx--];
            }
            
            area = shorter * w--;
            if(area > max_area) max_area = area;
        }
        
        return max_area;
    }
};