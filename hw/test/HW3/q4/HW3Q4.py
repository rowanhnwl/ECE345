import math

def PrintSubArraySums(m):
    for i in range(len(m)):
        for j in range(i, len(m)):
            print(str(i + 1) + " to " + str(j + 1) + ": " + str(m[i][j]))

# Q4. b)
# This function is a bottom-up dynamic solution to find the sums of all subarrays in an array of integers
# Running time: O(n^2)
# Space complexity: O(n^2)
def SubArraySums(d):
    N = len(d)

    # Set up an empty N x N array for the sums
    # Each space (i, j) represents the sum of elements i through j in array d
    m = [[0 for x in d] for y in d]

    # Fill in the minimal singular values (sums of 1 element)
    for i in range(N):
        m[i][i] = d[i]

    for l in range(2, N + 1): # l represents the length of a subarray, for lengths 2 to N
        for i in range(1, N - l + 2): # represents the total number of subarrays of length l that exist within d (length N)
            j = i + l - 1

            m[i - 1][j - 1] = m[i - 1][j - 2] + m[j - 1][j - 1] # Ones are subtracted for 0-based indexing

    return m

def Q4bWorst(d, i, N, D, Xsum, Worker, s, calls):
    calls[0] += 1
    
    # Base case
    if N - i <= 3*D:
        add = 0
        if Worker == "Xun":
            add = s[i][N - 1]
        return Xsum + add
    
    # If Xun is working
    if Worker == "Xun":
        maxDeadlines = -math.inf

        for X in range(3*D):  
            deadlines = Q4bWorst(d, i + X + 1, N, max(X + 1, D), Xsum + s[i][i + X], "Yuntao", s, calls)
            maxDeadlines = max(maxDeadlines, deadlines)

        return maxDeadlines
    
    if Worker == "Yuntao":
        minDeadlines = math.inf

        for X in range(3*D):
            deadlines = Q4bWorst(d, i + X + 1, N, max(X + 1, D), Xsum, "Xun", s, calls)
            minDeadlines = min(minDeadlines, deadlines)
        return minDeadlines
    
    return 0

# Implementation of the "better" function
def Q4bBetter(d, i, N, D, Xsum, Worker, s, m, calls):
    calls[0] += 1
    # Base case
    if N - i <= 3*D:
        add = 0
        if Worker == "Xun":
            add = s[i][N - 1]
        return Xsum + add
    
    # If Xun is working
    if Worker == "Xun":
        maxDeadlines = -math.inf

        for X in range(3*D):
            deadlines = 0

            if ("Yuntao", max(X + 1, D), i + X + 1) in m:
                deadlines = m[("Yuntao", max(X + 1, D), i + X + 1)] + Xsum + s[i][i + X]
            else:
                deadlines = Q4bBetter(d, i + X + 1, N, max(X + 1, D), Xsum + s[i][i + X], "Yuntao", s, m, calls)
                m[("Yuntao", max(X + 1, D), i + X + 1)] = deadlines - Xsum - s[i][i + X]
                m[("Xun", max(X + 1, D), i + X + 1)] = s[i + X + 1][N - 1] - m[("Yuntao", max(X + 1, D), i + X + 1)]

            maxDeadlines = max(maxDeadlines, deadlines)

        return maxDeadlines
    
    if Worker == "Yuntao":
        minDeadlines = math.inf

        for X in range(3*D):
            deadlines = 0

            if ("Xun", max(X + 1, D), i + X + 1) in m:
                deadlines = m[("Xun", max(X + 1, D), i + X + 1)] + Xsum
            else:
                deadlines = Q4bBetter(d, i + X + 1, N, max(X + 1, D), Xsum, "Xun", s, m, calls)
                m[("Xun", max(X + 1, D), i + X + 1)] = deadlines - Xsum
                m[("Yuntao", max(X + 1, D), i + X + 1)] = s[i + X + 1][N - 1] - m[("Xun", max(X + 1, D), i + X + 1)]
            
            minDeadlines = min(minDeadlines, deadlines)

        return minDeadlines
    
    return 0

def main():
    calls = [0]

    d = [2, 3, 4, 6, 7, 8, 9, 30, 2, 5, 6, 83, 2, 6, 2, 49, 30]
    print("\nDeadline array length: " + str(len(d)) + "\n")

    s = SubArraySums(d)
    m = dict()

    xunDeadlinesWorst = Q4bWorst(d, 0, len(d), 1, 0, "Xun", s, calls)
    print("Raw minimax: ")
    print(str(xunDeadlinesWorst) + " deadlines handled by Xun")
    print(str(calls[0]) + " recursive calls made\n")

    calls = [0]
    xunDeadlinesBetter = Q4bBetter(d, 0, len(d), 1, 0, "Xun", s, m, calls) 
    print("Optimized minimax: ")
    print(str(xunDeadlinesBetter) + " deadlines handled by Xun")
    print(str(calls[0]) + " recursive calls made\n")

if __name__ == "__main__":
    main()