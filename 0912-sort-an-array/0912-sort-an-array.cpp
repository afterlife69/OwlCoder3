class Solution {
public:
    void Merge(int low, int mid, int high, vector<int>&v){
        int i = low, j = mid + 1, k = 0;
        int temp[high - low + 1];
        while(i <= mid && j <= high){
            if(v[i] <= v[j])temp[k++]=v[i++];
            else temp[k++] = v[j++];
        }
        while(i <= mid)temp[k++]=v[i++];
        while(j <= high)temp[k++] = v[j++];
        for(int i=low;i<=high;i++)v[i] = temp[i-low];
    }
    void MS(int l, int r, vector<int>&v){
        if(l >= r)return;
        int mid = (l + r) / 2;
        MS(l, mid,v);
        MS(mid+1,r,v);
        Merge(l, mid, r, v);
    }
    vector<int> sortArray(vector<int>& nums) {
        MS(0, nums.size()-1, nums);
        return nums;
    }
};