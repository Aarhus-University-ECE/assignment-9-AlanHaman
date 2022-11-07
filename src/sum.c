#include "sum.h"

int sum(int a[], int n) {
    // if n we is equal 0, we return n, which is 0
    if (n == 0) {
        return n;
        // if n is not 0, we return the value of the element we are at plus the sum of the array from the element to the bottom.
    } else {
        return a[n - 1] + sum(a, n - 1);
    }
}
