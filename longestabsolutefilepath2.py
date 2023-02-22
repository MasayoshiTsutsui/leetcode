class Solution:
    def lengthLongestPath(self, input: str) -> int:
        lines = input.split(sep='\n')
        cur_ancestors = []
        longest = 0
        
        for line in lines:
            depth = line.count('\t') 
            name = line.replace('\t', '')
            while depth < len(cur_ancestors):
                cur_ancestors.pop()
            cur_ancestors.append(name)
            
            if '.' in name:
                longest = max(longest, len('/'.join(cur_ancestors)))
        
        return longest

s = "a"
print(Solution().lengthLongestPath(s))

