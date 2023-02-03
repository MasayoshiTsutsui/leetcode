
from typing import List, Tuple
DEBUG = 1


class Solution:
    def lengthLongestPath(self, input: str) -> int:
        maxlen = 0
        pathlen_depth = {0: 0}

        for line in input.splitlines():
            name = input.lstrip('\t')
            depth = len(input) - len(name)
            if '.' in name:
                maxlen = max(maxlen, pathlen_depth[depth] + len(name))
            else:
                pathlen_depth[depth + 1] = pathlen_depth[depth]+ len(name) + 1

        return maxlen