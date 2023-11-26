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
	int i = 0; // �������� �� �����������
	int j = 0; // �������� �� �����
	int k = 0; // ������� ���-�� ���� � �����
	int is_space = 1; // ������� ����, ��� ���������� ������ �������� ��������
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
			if (k % 2 == 0 && j != 0) // j != 0  -- ������� ������ �����
				printf("%s\n", word);
		}
	} while (sentence[i-1] != '.');
}


int main(void) {
	scan(sentence);
}