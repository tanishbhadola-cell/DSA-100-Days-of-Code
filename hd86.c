#include <stdio.h>

// Function to find integer square root using Binary Search
int integerSqrt(int n)
{
    int low = 0, high = n;
    int ans = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Use long long to prevent overflow
        long long square = (long long)mid * mid;

        if (square == n)
        {
            return mid;  // exact square root found
        }
        else if (square < n)
        {
            ans = mid;      // store current best answer
            low = mid + 1;  // search right side
        }
        else
        {
            high = mid - 1; // search left side
        }
    }

    return ans;
}

int main()
{
    int n;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    int result = integerSqrt(n);

    printf("Integer square root: %d\n", result);

    return 0;
}