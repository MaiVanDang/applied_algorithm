//Chapter 1 - Word Frequency in Text
#include <bits/stdc++.h>
using namespace std;

string sanitizeWord(const string& word) {
    string sanitized;
    for (char ch : word) {
        if (isalnum(ch)) {
            sanitized += ch;
        }
    }
    return sanitized;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    string text;
    map<string, int> wordCount;

    // Read the entire input text
    while (getline(cin, text)) {
        istringstream iss(text);
        string word;

        // Extract words from the text
        while (iss >> word) {
            string sanitizedWord = sanitizeWord(word);
            if (!sanitizedWord.empty()) {
                wordCount[sanitizedWord]++;
            }
        }
    }

    // Prepare a vector to sort the words
    vector<string> words;
    for (const auto& pair : wordCount) {
        words.push_back(pair.first);
    }

    // Sort words lexicographically
    sort(words.begin(), words.end());

    // Output the results
    for (const string& word : words) {
        cout << word << " " << wordCount[word] << endl;
    }

    return 0;
}