#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearTimeLogFile() {
    FILE *timefile = fopen("time.txt", "w");
    if (timefile != NULL) {
        fclose(timefile);
    } else {
        printf("Ошибка при очистке файла time.txt.\n");
    }
}

int *createarray(int size) {
    int *array = (int *)malloc(size * sizeof(int));
    return array;
}

void fillarray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("Введите значение для элемента %d:", i + 1);
        scanf("%d", &array[i]);
    }
}

void printarray(int *array, int size) {
    printf("Динамический массив: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void findDiaposon(int *array, int size, int min, int max) {
    printf("Индексы элементов в диапазоне [%d, %d]: ", min, max);
    for (int i = 0; i < size; i++) {
        if (array[i] >= min && array[i] <= max) {
            printf("%d ", array[i]);
        }
    }
    printf("\n");
}

void saveArray(int *array, int size, const char *filename) {

    FILE *file = fopen(filename, "wb");
    if (file != NULL) {
        fwrite(array, sizeof(int), size, file);
        fclose(file);
    } else {
        printf("Ошибка при открытии файла для записи.\n");
    }
}

void printArray(const char *filename) {

    FILE *file = fopen(filename, "rb");
    if (file != NULL) {
        int value;
        while (fread(&value, sizeof(int), 1, file) == 1) {
            printf("%d ", value);
        }
        fclose(file);
        printf("\n");
    } else {
        printf("Ошибка при открытии файла для чтения.\n");
    }
}

void freearray(int *array) {
    if (array != NULL) {
        free(array);
    }
}

int main() {
    int size;
    printf("Введите размер массива:");
    scanf("%d", &size);

    int *dynamicarray = createarray(size);

    if (dynamicarray != NULL) {
        clock_t start = clock();

        fillarray(dynamicarray, size);
        printarray(dynamicarray, size);
        int min, max;
        printf("Введите минимальное и максимальное значение для поиска: ");
        scanf("%d %d", &min, &max);

        findDiaposon(dynamicarray, size, min, max);

        saveArray(dynamicarray, size, "array.bin");
        printf("Массив сохранен в файл 'array.bin'.\n");

        printf("Содержимое массива из файла 'array.bin':\n");
        printArray("array.bin");

        freearray(dynamicarray);

        clock_t end = clock();
        double elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Время исполнения всех функций: %f секунд\n", elapsed);

        FILE *timefile = fopen("time.txt", "a");
        fprintf(timefile, "Время исполнения всех функций:: %f секунд\n", elapsed);
        fclose(timefile);
    } else {
        printf("Не удалось выделить память для массива.\n");
    }

    return 0;
}
