int threeSumClosest(int* nums, int numsSize, int target) {
    sortArray(nums, numsSize);
    int closest = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == target) {
                continue;
            }
            if (abs(sum - target) < abs(closest - target)) {
                closest = sum;
            }
            if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    return closest;
}