#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 256;

void preprocessBadChar(string path, int badchar[ALPHABET_SIZE]) {
    int n = path.length();

    for (int i = 0; i < ALPHABET_SIZE; i++)
        badchar[i] = -1;

    for (int i = 0; i < n - 1; i++)
        badchar[(int)path[i]] = i;

    // For the last character in the pattern, we set a special case
    badchar[(int)path[n - 1]] = n - 1;
}

int boyerMoore(string text, string path) {
    int m = text.length();
    int n = path.length();
    int badchar[ALPHABET_SIZE];

    preprocessBadChar(path, badchar);

    int s = 0;
    while (s <= (m - n)) {
        int j = n - 1;

        while (j >= 0 && path[j] == text[s + j])
            j--;

        if (j < 0) {
            // Pattern found at index s
            return s;
            // If you want to find all occurrences, you may print or store s here.
            // Move the pattern to the next possible position.
            // s += (s + n < m) ? n - badchar[text[s + n]] : 1;
        } else {
            // Shift the pattern so that the bad character in text aligns with the last occurrence in pattern.
            s += max(1, j - badchar[text[s + j]]);
        }
    }

    return -1; // Pattern not found
}

int main() {
    string text = "Welcometomychannel";
    string path = "nnel";

    int ans = boyerMoore(text, path);
    if (ans != -1) {
        cout << "Pattern found at index " << ans << endl;
    } else {
        cout << "Pattern not found in the text" << endl;
    }

    return 0;
}
