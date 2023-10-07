# Q 1. a)
# Return two values that sum to the target
# Sorting -> O(n*logn)
# Iterating -> O(n)
# Total -> O(n*logn)

def find_vals_exact(a, t):
    lp = 0
    rp = len(a) - 1

    a_sorted = sorted(a)

    while lp < rp:
        sum = a_sorted[lp] + a_sorted[rp]

        if sum < t:
            lp += 1
        elif sum > t:
            rp -= 1
        else:
            return (a_sorted[lp], a_sorted[rp])

    return (None, None)

# Q 1. c)
# Return the two values with the CLOSEST (<=) sum to the target
# Sorting -> O(n*logn)
# Iterating -> O(n)
# Total -> O(n*logn)

def find_vals_closest(a, t):
    lp = 0
    rp = len(a) - 1

    a_sorted = sorted(a)

    current_best = ()
    min_diff = 65536

    while lp < rp:
        sum = a_sorted[lp] + a_sorted[rp]

        diff = t - sum

        if diff >= 0 and diff < min_diff:
            min_diff = diff
            current_best = (a_sorted[lp], a_sorted[rp])

        if sum < t:
            lp += 1
        elif sum > t:
            rp -= 1
        else:
            return (a_sorted[lp], a_sorted[rp])

    return current_best

def main():
    arr = [4, 2, 9, 3, 1, 7, 8]

    target = 14

    (c1, c2) = find_vals_closest(arr, target)

    print(c1, c2)

if __name__ == "__main__":
    main()