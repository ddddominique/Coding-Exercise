
class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        nums.sort()
        result = []

        for i in range(len(nums)):
            if nums[i] < target:
                continue
            if nums[i] > target:
                break
            result.append(i)

        return result
