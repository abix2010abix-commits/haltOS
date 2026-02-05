int strlen(char *s) {
    int i = 0;
    while (s[i] != '\0') i++;
    return i;
} 

int strncmp(int size, char *c1, char *c2) {
    int counter = 0;


    while (counter < size) {
        if (c1[counter] == c2[counter]) {
            counter++;
        } else {
            return 1;
        }
    }


    return 0;
}

void strcpy(char *dest, char *src) {
    while (*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}
int atio(char *s) {
    int r = 0;
    int i = 0;

    while (s[i] >= '0' && s[i] <= '9') {
        r = r * 10 + (s[i] - '0');
        i++;
    }
    return r;
}


void reverse(char *str, int l) {
    int start = 0;
    int end = l - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void itoa(int num, char *str) {
    int i = 0;


    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }


    while (num != 0) {
        int rem = num % 10;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / 10;
    }

    str[i] = '\0';

    reverse(str, i);
}