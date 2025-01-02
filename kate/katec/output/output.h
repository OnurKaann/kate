#ifndef OUTPUT_H
#define OUTPUT_H

#include <stdio.h>
#include <stdlib.h>
#include "../util/arraylist.h" // DynamicArrayList tanımları için

/**
 * DynamicArrayList'teki tüm elemanları tek bir dosyaya satır satır yazar.
 * @param list DynamicArrayList yapısı.
 * @param filename Yazılacak dosyanın ismi.
 */
void writeAllElementsToFile(DynamicArrayList* list, const char* filename) {
    if (list == NULL || list->array == NULL) {
        fprintf(stderr, "DynamicArrayList is null or empty.\n");
        return;
    }

    // Dosyayı yazmak için aç
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        return;
    }

    // Liste elemanlarını dosyaya satır satır yazıyoz
    for (size_t i = 0; i < list->size; i++) {
        fprintf(file, "%s\n", list->array[i].data);
    }

    // Dosyayı kapat
    fclose(file);
    printf("All elements written to %s\n", filename);
}

#endif // OUTPUT_H
