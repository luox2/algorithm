/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quick_sort(nums, 0, nums.size()-1);
        return nums;

        
    }
    void quick_sort(vector<int>&nums, int start, int end){
        if(start>=end) return;
        int pivot = nums[start], i = start+1, j = end;
        while(i<=j){
            if(nums[i]>pivot && nums[j]<pivot){
                swap(nums[i++], nums[j--]);
            }
            if(nums[i]<=pivot) i++;
            if(nums[j]>=pivot) j--;
        }
        swap(nums[start], nums[j]);
        quick_sort(nums, start, j-1);
        quick_sort(nums, j+1, end);
    }
};

