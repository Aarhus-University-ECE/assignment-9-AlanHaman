#include "search.h"
#include <stdbool.h>

bool search(int a[], int n, int x) {
    // If n is 0, then we return false, because we cant find the x in an empty array
    if (n == 0) {
        return false;
        //If n > 0 and the element we are at is x, we return true, because we have found x
    } else if (n > 0 && a[n - 1] == x) {
        return true;
        // If n is not 0 and we havnt foundt x, we need to keep searching
    } else {
        search(a, n - 1, x);
    }
}
