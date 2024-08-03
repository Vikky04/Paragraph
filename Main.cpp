#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PARAGRAPH_SIZE 1000
#define MAX_WORD_SIZE 50
#define MAX_WORDS 200

// Function to convert a string to lowercase
void toLowerCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to check if a character is a delimiter
int isDelimiter(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\t' || ch == ',' || ch == '.' || ch == '!' || ch == '?' || ch == ';' || ch == ':';
}

int main() {
    char paragraph[MAX_PARAGRAPH_SIZE];
    char words[MAX_WORDS][MAX_WORD_SIZE];
    int wordCount[MAX_WORDS] = {0};
    int totalWords = 0;

    // Read the paragraph from the user
    printf("Enter a paragraph: ");
    fgets(paragraph, sizeof(paragraph), stdin);

    // Tokenize the paragraph into words
    char *token = strtok(paragraph, " \n\t,.-!?:;");
    while (token != NULL) {
        toLowerCase(token);

        // Check if the word already exists in the words array
        int found = 0;
        for (int i = 0; i < totalWords; i++) {
            if (strcmp(words[i], token) == 0) {
                wordCount[i]++;
                found = 1;
                break;
            }
        }

        // If the word is not found, add it to the words array
        if (!found) {
            strcpy(words[totalWords], token);
            wordCount[totalWords]++;
            totalWords++;
        }

        // Get the next token
        token = strtok(NULL, " \n\t,.-!?:;");
    }

    // Print the word frequencies
    printf("Word frequencies:\n");
    for (int i = 0; i < totalWords; i++) {
        printf("%s: %d\n", words[i], wordCount[i]);
    }

    return 0;
}
