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

    PrintSubArraySums(m)    

def main():
    d = [1, 3, 3, 2, 5, 2, 6, 5, 2, 7, 8, 3, 4, 6]

    SubArraySums(d)

if __name__ == "__main__":
    main()