// Program that takes a string and returns if its a palindrome or not

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char *s);

int main(int argc, char **argv) {
    if (argc == 2) {
        if (isPalindrome(argv[2])) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }

    return 0;
}

// Time Complexity: O(n)
bool isPalindrome(char *s) {
    // point to the first and last characters
    int lo = 0;
    int hi = strlen(s) - 1;         // O(n)

    while (lo < hi) {               // n/2 = O(n)
        // check if they match
        if (s[lo] != s[hi]) {
            return false;
        }
        // if they do, move inwards to the next pair
        lo++;
        hi--;
    }
    // stop at the middle
    return true;
}
