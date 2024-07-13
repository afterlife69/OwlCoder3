class Solution {
public:
    void merge(vector<int>& v, int m, vector<int>& b, int n) {
        int i = m - 1, j = n - 1, k = n + m - 1;
        while(k >= 0){
            if(i >= 0 && j >= 0){
                if(v[i] >= b[j])v[k--] = v[i--];
                else v[k--] = b[j--];
            }
            else if(i >= 0){
                v[k--] = v[i--];
            }
            else if(j >= 0){
                v[k--] = b[j--];
            }
            else break;
        }
    }
};