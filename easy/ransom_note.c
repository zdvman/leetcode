#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


bool canConstruct(char* ransomNote, char* magazine) {
	// Array to store the frequency of each character in the magazine
	int charCount[26] = {0};
	
	// Count each character in the magazine
	for (int i = 0; magazine[i] != '\0'; i++) {
		charCount[magazine[i] - 'a']++;
	}
	
	// Check if we can form ransomNote from magazine characters
	for (int i = 0; ransomNote[i] != '\0'; i++) {
		if (--charCount[ransomNote[i] - 'a'] < 0) {
			return false;
		}
	}
	
	return true;
}

// Solution with use of array of addresses to compare
// if the address of current symbol from ransomNote string
// exists in tha array of addresses.

// int check_ptr(unsigned int *arr, int arr_size, unsigned int address) {
// 	int i = 0;
// 	while (i < arr_size) {
// 		if (arr[i] == address)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// void add_ptr_to_arr(unsigned int *arr, int arr_size, unsigned int address) {
// 	int i = 0;
// 	while (i < arr_size) {
// 		if (arr[i] == -1)
// 		{
// 			arr[i] = address;
// 			return ;
// 		}
// 		i++;
// 	}
// }

// bool canConstruct(char* ransomNote, char* magazine) {
// 	int len1 = strlen(ransomNote);
// 	int len2 = strlen(magazine);
// 	int tmp_len = 0;
// 	if (len2 < len1)
// 		return false;
// 	unsigned int *arr = malloc(sizeof(unsigned int) * len1);
// 	if (!arr)
// 		return (NULL);
// 	memset(arr, -1, sizeof(unsigned int) * len1);
// 	int i = 0;
// 	while (magazine[i]) {
// 		int j = 0;
// 		while (ransomNote[j]) {
// 			if (ransomNote[j] == magazine[i]
// 			&& !check_ptr(arr, len1, &ransomNote[j]) ) {
// 				add_ptr_to_arr(arr, len1, &ransomNote[j]);
// 				tmp_len++;
// 				if (tmp_len == len1) {
// 					free(arr);
// 					return true;
// 				}
// 				break ;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	free(arr);
// 	return (false);
// }

int main(void) {
	char *ransomNote = "aa";
	char *magazine = "aab";
	printf("%d\n", canConstruct(ransomNote, magazine));
	return (0);
}
