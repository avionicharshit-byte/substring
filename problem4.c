#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    char s[100];
    int x, y;
    printf("Enter the string: ");
    scanf("%s", s);
    printf("Enter the values of x and y: ");
    scanf("%d %d", &x, &y);

    int n = strlen(s);
    int score = 0;
    int i = 0;

    while (i < n) {
        if (s[i] == 'a' && s[i+1] == 'b') {
            score += x;
            i += 2;
        } else if (s[i] == 'b' && s[i+1] == 'a') {
            score += y;
            i += 2;
        } else if (s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'a') {
            score += x + y;
            i += 3;
        } else if (s[i] == 'b' && s[i+1] == 'a' && s[i+2] == 'b') {
            score += x + y;
            i += 3;
        } else if (s[i] == 'a') {
            int count = 0;
            while (i < n && s[i] == 'a') {
                count++;
                i++;
            }
            score += (count / 3) * x * y;
        } else if (s[i] == 'b') {
            int count = 0;
            while (i < n && s[i] == 'b') {
                count++;
                i++;
            }
            score += (count / 3) * x * y;
        } else {
            i++;
        }
    }

    printf("Maximum points: %d\n", score);

    return 0;
}
