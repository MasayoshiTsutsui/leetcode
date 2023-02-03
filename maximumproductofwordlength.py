

LETTER_NUM = 26

class Solution:
    @staticmethod
    def char2ascii_num(c: str) -> int:
        if len(c) != 1:
            raise ValueError("only one char can be converted to ascii num.")
        return ord(c) - ord("a")
    
    @staticmethod
    def has_common_char(bm1: int, bm2: int) -> bool:
        or_bitmap = bm1 | bm2
        xor_bitmap = bm1 ^ bm2
        if or_bitmap == xor_bitmap:
            return False
        else:
            return True


    def maxProduct(self, words: List[str]) -> int:
        letter_bitmap = []

        for s in words:
            bitmap = 0
            for c in s:
                bitmap |= 2 ** Solution.char2ascii_num(c)
            letter_bitmap.append(bitmap)
        
        max_product = 0
        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                if not Solution.has_common_char(letter_bitmap[i], letter_bitmap[j]):
                    max_product = max(max_product, len(words[i]) * len(words[j]))

        return max_product

