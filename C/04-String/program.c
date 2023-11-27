#include <stdio.h>
#define wordcount 30
#define maxlength 10

char* sentence = "adj45  kf-gr54k0 09mmbdsjk8 d   djhg87 4jFk4f djujshd 2345 rt.";

int scan(char* sentence) {
	printf("original sentences = %s\n", sentence);
	int i = 0; // итератор по предложению
	int j = 0; // итератор по слова
	int k = 0; // подсчет кол-ва букв в слове
	int wc = 0;
	int is_space = 1; // признак того, что предыдущий символ является пробелом
	char word[11] = "";
	do {
		char c = sentence[i++]; // char c = sentence[i]; i = i + 1; // post-increment

		// Проверка на корректность символов, допускается следующий набор: " .0..9A..Za..z"
		if (!(c == ' ' || c == '.' || (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
			printf("ERROR: We found invalid char = '%c'\n", c);
			return 3;
		}

		// если встретили не пробел или точку (те букву или цифру)
		if (c != ' ' && c != '.') {
			if (is_space == 1) {
				j = 0;
				k = 0;
				is_space = 0;
			}
			// если это не цифра
			if (!(c >= '0' && c <= '9')) 
				word[j++] = c;
			k++;
			if (k > maxlength) {
				printf("ERROR: We have reached word length limit (%i)\n", maxlength);
				return 1;
			}
		}
		else if (is_space == 0) {
			word[j] = 0;
			is_space = 1;
			if (k % 2 == 0 && j != 0)  // j != 0  -- убирает пустое слово
				printf("%s\n", word);
			wc++;
			if (wc > wordcount) {
				printf("ERROR: We have reached sentence length limit (%i)\n", wordcount);
				return 2;
			}
		}
	} while (sentence[i-1] != '.');
	return 0;
}


int main(void) {
	int result = scan(sentence);
	if (result == 0)
		printf("Program has finished successfully");
	else
		printf("Program has finished with error = %i", result);
	return result;
}