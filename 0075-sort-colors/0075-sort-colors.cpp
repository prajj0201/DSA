class Solution {
public:
    int partition(vector<int> &nums,int s,int e)
    {
        int pivot=nums[s];
        int count=0;
        for(int i=s+1;i<=e;i++)
        {
            if(nums[i]<=pivot)
                count++;
        }
        int pivotIndex=count+s;
        swap(nums[pivotIndex],nums[s]);
        int i=s,j=e;
        while(i<pivotIndex && j>pivotIndex)
        {
            while(nums[i]<=pivot)
                i++;
            while(nums[j]>pivot)
                j--;
            if(i<pivotIndex && j>pivotIndex)
                swap(nums[i++],nums[j--]);
        }
        return pivotIndex;
    }
    void quickSort(vector<int> &nums,int s,int e)
    {
        if(s>=e)
            return;
        int p=partition(nums,s,e);
        quickSort(nums,0,p-1);
        quickSort(nums,p+1,e);
    }
    void sortColors(vector<int>& nums) {
        quickSort(nums,0,nums.size()-1);
    }
};