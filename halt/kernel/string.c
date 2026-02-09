// ==========================================
// string source file
// ==========================================

// ===============================================================
// 20:30 9/2/2026
int str_size(const char *string) {
	int size = 0;
	while (string[size] != '\0') {
		size++;
	}
	return size;
}
// ===============================================================
// 20:45 9/2/2026
int str_if(const char *string_1, const char *string_2) {
	int counter = 0;
	while (string_1[counter] == string_2[counter]) {
		if (string_1[counter] == '\0' && string_2[counter]) {
			return 0;
		}
		else {
			counter++;
		}
	}
	return 1;
}
// ===============================================================
// 20:57 9/2/2026
int str_write(char* string, char value, int size) {
	int count = 0;
	while (count < size) {
		string[count] = value;
		count++;
	}
}// ===============================================================
// 21:15 9/2/2026 
void str_is(int n, char *s) {
    int i = 0;
    if (n == 0) {
        s[0] = '0';
        s[1] = '\0';
        return;
    }

    while (n > 0) {
        s[i] = (n % 10) + '0';
        n = n / 10;
        i++;
    }
    s[i] = '\0';

    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

int str_si(char *s) {
    int result = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        result = result * 10 + (s[i] - '0');
    }
    return result;
}