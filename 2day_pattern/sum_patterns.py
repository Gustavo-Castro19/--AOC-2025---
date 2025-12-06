import re 

def sum_repeated_twice_ranges(ranges_line):
    def is_repeated_twice(n):
        s = str(n)
        if len(s) % 2 == 1: return False
        k = len(s) // 2
        if s[0] == '0': return False
        return s[:k] == s[k:]
    total = 0
    for part in ranges_line.split(','):
        lo, hi = map(int, part.split('-'))
        for n in range(lo, hi+1):
            if is_repeated_twice(n):
                total += n
    return total

def sum_repeats(ranges_line):
    def is_repeated_thrice(n):
        s=str(n)
        return bool(re.search(r"^(\d+)\1+$", s))
    total = 0 
    for part in ranges_line.split(','):
        lo, hi = map(int, part.split('-'))
        for n in range(lo, hi+1):
            if is_repeated_thrice(n):
                total += n
    return total

def main()->void:
    with open("input.txt", "r") as file: 
        patterns = file.readline();
        sum=sum_repeated_twice_ranges(patterns)
        print(f"the sum is equal {sum}")
        next_sum = sum_repeats(patterns)
        print(f"{next_sum=}")

if(__name__ == "__main__"): 
    main();
