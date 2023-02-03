class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        sign = ""
        if numerator * denominator < 0:
            sign = "-"
        numerator = abs(numerator)
        denominator = abs(denominator)
        integer = str(numerator // denominator)
        numerator %= denominator
        numerator_appeared_idx = {}
        floating = ""
        for i in range(10000):
            if numerator == 0:
                break
            if numerator in numerator_appeared_idx:
                idx = numerator_appeared_idx[numerator]
                repeat_unit = floating[idx:]
                floating = floating[:idx] + "(" + repeat_unit + ")"
                break

            numerator_appeared_idx[numerator] = i

            numerator *= 10
            floating += str(numerator // denominator)
            assert len(str(numerator // denominator)) == 1
            numerator %= denominator
        if len(floating) == 0:
            return sign + integer
        return sign + integer + "." + floating
        

            




