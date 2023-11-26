#include <stdio.h>

char* sentence = "adj45  kfgr54k0 09mmbdsjk8 d   djhg87 4jfk4f djujshd 2345 rt.";
// 20 61 65 67 34 35 20 20 
/*
* kfgrk
* mmbdsjk
* djhg
* jfkf
* ?
* rt
*/

// word
//    0   1   2   3   4   5   6   7   8   9   10   
//  | a | d | j | 4 | 5 | \0 |   |   |   |   |   |  

void scan(char* sentence) {
	int i = 0; // итератор по предложению
	int j = 0; // итератор по слова
	int k = 0; // подсчет кол-ва букв в слове
	int is_space = 1; // признак того, что предыдущий символ является пробелом
	char word[11] = "";
	do {
		char c = sentence[i++];

		if (c != ' ' && c != '.') {
			if (is_space == 1) {
				j = 0;
				k = 0;
				is_space = 0;
			}

			if (c < '0' || c > '9') 
				word[j++] = c;
			k++;
		}
		else if (is_space == 0) {
			word[j] = 0;
			is_space = 1;
			if (k % 2 == 0 && j != 0) // j != 0  -- убирает пустое слово
				printf("%s\n", word);
		}
	} while (sentence[i-1] != '.');
}


int main(void) {
	scan(sentence);
}