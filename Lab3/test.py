def print_permutations(s, prefix=""):
    pre = ["H","h", "a","t","p","d","g","r","n"]
    mid = ["a","e","n",]
    if len(s) == 0:
        print("anhHoang" + ''.join(prefix))
    else:
        for i in range(len(s)):
            print_permutations(s[:i] + s[i+1:], prefix + s[i])

# Usage
print_permutations('tdripae')