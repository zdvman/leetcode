#include <stdbool.h>
#include <string.h>

// Check if s and t are isomorphic
// Two strings are isomorphic if the characters in s can be replaced to get t
// All occurrences of a character must be replaced with another character while preserving the order of characters

bool isIsomorphic(char* s, char* t) {
	if (strlen(s) != strlen(t))
		return false;
	char s_arr[256] = {0};
	char t_arr[256] = {0};

	int i = 0;
	while (s[i]) {
		char s_char = s[i];
		char t_char = t[i];
		if (s_arr[s_char] == 0 && t_arr[t_char] == 0)
		{
			s_arr[s_char] = t_char;
			t_arr[t_char] = s_char;
		} else if (s_arr[s_char] != t_char  || t_arr[t_char] != s_char) {
			return false;
		}
		i++;
	}
	return true;
}

int main(void) {
	char s[] = "egg";
	char t[] = "add";
	printf("%d\n", isIsomorphic(s, t));
	return 0;
}
