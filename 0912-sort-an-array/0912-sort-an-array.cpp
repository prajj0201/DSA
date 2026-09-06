class Solution {
public:
    void merge(vector<int>& nums,int s,int e)
    {
        int mid=s+((e-s)/2);
        int len1=mid-s+1;
        int len2=e-mid;
        int *first=new int[len1];
        int *second=new int[len2];
        int main=s;
        for(int i=0;i<len1;i++)
            first[i]=nums[main++];
        main=mid+1;
        for(int i=0;i<len2;i++)
            second[i]=nums[main++];
        int index1=0,index2=0;
        main=s;
        while(index1<len1 && index2<len2)
        {
            if(first[index1]<second[index2])
                nums[main++]=first[index1++];
            else
                nums[main++]=second[index2++];
        }
        while(index1<len1)
            nums[main++]=first[index1++];
        while(index2<len2)
            nums[main++]=second[index2++];
    }
    void mergeSort(vector<int>&nums,int s,int e)
    {
        if(s>=e)
            return;
        int mid=s+((e-s)/2);
        mergeSort(nums,s,mid);
        mergeSort(nums,mid+1,e);
        merge(nums,s,e);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};