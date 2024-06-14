#include <stdio.h>

int main() {
    FILE* file;
    errno_t err;

    err = fopen_s(&file, "ex.txt", "rb");
    if (err != 0) {
        perror("Error opening file");
        return -1;
    }

    char ch;
    int count = 0;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\r') {
            count++;
        }
    }

    // 결과를 출력합니다
    printf("Number of carriage return characters: %d\n", count);

    fclose(file);
    return 0;
}
