#include <stdio.h>
#include <stdlib.h>

int findMaxSubstring(char* str, char* substr) {
    int max = 0;
    int pos = -1;
    int maxpos = -1;
    int digit = 0;
    for (int i = 0; i <= strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            if (!digit) {
                pos = i;
            }
            digit = 1;
        } else {
            if (digit) {
                if (i - pos > max) {
                    max = i - pos;
                    maxpos = pos;
                }
            }
            digit = 0;
        }
    }
    for (int i = 0; i < max; i++)
        substr[i] = str[i + maxpos];
    substr[max] = 0;
    return maxpos;
}

int main(void) {
    char* s = "a128qw4335df545f123456";
    char r[10];
    int i = findMaxSubstring(s, r);
    printf("%s, substring = %s", s, r);
}

/*int main(void) {
	char* fileName = "D:\\f.txt";

	FILE* f;

	fopen_s(&f, fileName, "r");
    if (f == NULL)
        exit(EXIT_FAILURE);

    //read line by line
    const size_t line_size = 300;
    char* line = malloc(line_size);
    while (fgets(line, line_size, f) != NULL) {
        printf("%s", line);
    }
    free(line);

    exit(EXIT_SUCCESS);
}*/