//s="c*a*bc p=aabc output: true . : match missing letter and * match occurence of the letter
// "
#include <stdbool.h>
bool solve(char *s, char *p)
{
    // Pattern finished
    if (*p == '\0')
        return *s == '\0';

    // Do current characters match?
    bool firstMatch = (*s != '\0') &&
                      (*s == *p || *p == '.');

    // Is the next character '*'
    if (*(p + 1) == '*')
    {
        return solve(s, p + 2) ||              // Skip x*
               (firstMatch && solve(s + 1, p)); // Use x*
    }

    // Normal character
    return firstMatch && solve(s + 1, p + 1);
}

bool isMatch(char *s, char *p)
{
    return solve(s, p);
}