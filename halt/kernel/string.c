 

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