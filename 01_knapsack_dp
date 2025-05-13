#include <stdio.h>

// Function to get the maximum of two numbers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve 0/1 Knapsack problem using Dynamic Programming
int knapsack(int W, int wt[], int val[], int n) {
    int dp[n+1][W+1]; // dp[i][w] stores max value for i items and weight limit w

    // Build the dp table in bottom-up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;  // Base case: no items or no weight capacity
            else if (wt[i-1] <= w)
                dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w]);
                // Include the item or skip it, take the max
            else
                dp[i][w] = dp[i-1][w];  // Can't include the item, skip it
        }
    }

    return dp[n][W];  // Return max value for n items and total weight W
}

int main() {
    int val[] = {60, 100, 120}; // Values of items
    int wt[] = {10, 20, 30};    // Weights of items
    int W = 50;                 // Maximum weight capacity
    int n = sizeof(val)/sizeof(val[0]);  // Number of items

    int maxValue = knapsack(W, wt, val, n);  // Call the knapsack function
    printf("Maximum value in knapsack = %d\n", maxValue);

    return 0;
}
