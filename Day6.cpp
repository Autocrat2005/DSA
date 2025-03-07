#JPMorgan
#LC(Q4)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) 
            return findMedianSortedArrays(nums2, nums1);  
        
        int m = nums1.size(), n = nums2.size();
        int begin1 = 0, end1 = m;

        while (begin1 <= end1) {
            int i1 = (begin1 + end1) / 2;
            int i2 = (m + n + 1) / 2 - i1;

            int max1 = (i1 == 0) ? INT_MIN : nums1[i1 - 1];
            int min1 = (i1 == m) ? INT_MAX : nums1[i1];

            int max2 = (i2 == 0) ? INT_MIN : nums2[i2 - 1];
            int min2 = (i2 == n) ? INT_MAX : nums2[i2];

            if (max1 <= min2 && max2 <= min1) {
                if ((m + n) % 2 == 0) 
                    return ((double)max(max1, max2) + min(min1, min2)) / 2;
                else 
                    return (double)max(max1, max2);
            } 
            else if (max1 > min2) {
                end1 = i1 - 1;
            } 
            else {
                begin1 = i1 + 1;
            }
        }
        
        throw invalid_argument("Input arrays are not sorted or valid.");
    }
};

#TC : O(min(log(m), log(n)) and SC : O(1)

#LC(Q273)
class Solution:
    def numberToWords(self, num: int) -> str:
        if num == 0:
            return "Zero"
        
        scales = ["", "Thousand", "Million", "Billion"]
        groups = []
        while num > 0:
            groups.append(num % 1000)
            num = num // 1000
        
        groups = groups[::-1] 
        result = []
        
        for i in range(len(groups)):
            group = groups[i]
            if group == 0:
                continue
            group_words = self.three_digits_to_words(group)
            scale_index = len(groups) - 1 - i
            scale = scales[scale_index]
            if scale:
                group_words += " " + scale
            result.append(group_words)
        
        return ' '.join(result).strip()
    
    def three_digits_to_words(self, n: int) -> str:
        if n == 0:
            return ""
        parts = []
        hundreds = n // 100
        remainder = n % 100
        if hundreds > 0:
            parts.append(self.ones[hundreds] + " Hundred")
        if remainder > 0:
            parts.append(self.two_digits_to_words(remainder))
        return ' '.join(parts)
    
    def two_digits_to_words(self, n: int) -> str:
        if n == 0:
            return ""
        if n < 20:
            return self.ones[n]
        tens_part = self.tens[n // 10]
        ones_part = self.ones[n % 10]
        return tens_part + (" " + ones_part if ones_part else "")
    
    ones = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
            "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
            "Eighteen", "Nineteen"]
    tens = ["", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
