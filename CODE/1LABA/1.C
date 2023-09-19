#include <stdio.h>

int main() {
    FILE* info;
    char in;
    info = fopen("comp_system.txt", "r");
    if (info == NULL) {
        printf("Не удалось открыть файл comp_system.txt");
        return 1;
    }
    while ((in = fgetc(info)) != EOF) {
    printf("%c", in);
}
    fclose(info);
    return 0;
}