#include <stdio.h>

typedef long long ll;

// Function to check if it's possible to paint all boards within 'maxTime'
int isPossible(int arr[], int n, int k, ll maxTime) {
    int paintersUsed = 1;
    ll currentSum = 0;

    for (int i = 0; i < n; i++) {
        // If a single board is longer than maxTime, it's impossible
        if (arr[i] > maxTime) return 0;

        if (currentSum + arr[i] > maxTime) {
            // Assign to a new painter
            paintersUsed++;
            currentSum = arr[i];
            
            // If we exceed the number of available painters
            if (paintersUsed > k) return 0;
        } else {
            currentSum += arr[i];
        }
    }
    return 1;
}

ll solve() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int boards[n];
    ll low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        if (boards[i] > low) low = boards[i]; // Lower bound: Max element
        high += boards[i];                   // Upper bound: Sum of all elements
    }

    ll result = high;
    while (low <= high) {
        ll mid = low + (high - low) / 2;

        if (isPossible(boards, n, k, mid)) {
            result = mid;     // Try to find a smaller maximum
            high = mid - 1;
        } else {
            low = mid + 1;    // Need more time
        }
    }
    return result;
}

int main() {
    printf("%lld\n", solve());
    return 0;
}