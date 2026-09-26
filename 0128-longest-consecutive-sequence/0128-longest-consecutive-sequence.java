class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> numSet=new HashSet<>();
        for(int i: nums) numSet.add(i);
        int maxLen=0;
        for (int num : numSet) {
            if (!numSet.contains(num-1)){
                int currentNum=num;
                int currentLen=1;
                while (numSet.contains(++currentNum)){
                    currentLen++;
                }
                maxLen=Math.max(maxLen, currentLen);
            }
        }
        return maxLen;
    }
}