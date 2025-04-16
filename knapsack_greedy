#include <stdio.h>

int main() {
    float weight[50], profit[50], ratio[50];
    float capacity, total = 0.0, temp;
    int n, i, j;

    printf("Enter number of items: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter weight and profit for item[%d]: ", i);
        scanf("%f %f", &weight[i], &profit[i]);

        ratio[i] = profit[i] / weight[i];
    }

    printf("Enter capacity of knapsack: ");
    scanf("%f", &capacity);

    // Sorting the items based on the profit/weight ratio in descending order
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    printf("Greedy algorithm knapsack:\n");

    for (i = 0; i < n; i++) {
        if (weight[i] > capacity) {
            break;
        } else {
            total = total + profit[i];
            capacity = capacity - weight[i];
        }
    }

    if (i < n) {
        total = total + (ratio[i] * capacity);  // Add fractional profit for the last item
    }

    printf("Total profit: %f\n", total);

    return 0;
}
