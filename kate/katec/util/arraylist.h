#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* data;
    size_t length;
} DynArrayElement;

typedef struct {
    DynArrayElement* array;
    size_t size;
    size_t capacity;
} DynamicArrayList;

DynamicArrayList* createDynamicArrayList() {
    DynamicArrayList* list = (DynamicArrayList*)malloc(sizeof(DynamicArrayList));
    list->size = 0;
    list->capacity = 10;
    list->array = (DynArrayElement*)malloc(list->capacity * sizeof(DynArrayElement));
    return list;
}

void freeDynamicArrayList(DynamicArrayList* list) {
    for (size_t i = 0; i < list->size; i++) {
        free(list->array[i].data);
    }
    free(list->array);
    free(list);
}

void append(DynamicArrayList* list, const char* str) {
    if (list->size == list->capacity) {
        list->capacity++;
        list->array = (DynArrayElement*)realloc(list->array, list->capacity * sizeof(DynArrayElement));
    }
    
    list->array[list->size].length = strlen(str);
    list->array[list->size].data = (char*)malloc((list->array[list->size].length + 1) * sizeof(char));
    strcpy(list->array[list->size].data, str);
    
    list->size++;
}

void delete(DynamicArrayList* list, size_t index) {
    if (index >= list->size) {
        return;
    }
    
    free(list->array[index].data);
    
    for (size_t i = index; i < list->size - 1; i++) {
        list->array[i] = list->array[i + 1];
    }
    
    list->size--;
}

void deleteCharAtIndex(DynamicArrayList* list, size_t index, size_t charIndex) {
    if (index >= list->size) {
        return;
    }

    if (charIndex >= list->array[index].length) {
        return;
    }
    
    size_t newLength = list->array[index].length - 1;
    char* newData = (char*)malloc((newLength + 1) * sizeof(char));
    
    size_t newDataIndex = 0;
    for (size_t i = 0; i < list->array[index].length; i++) {
        if (i != charIndex) {
            newData[newDataIndex] = list->array[index].data[i];
            newDataIndex++;
        }
    }
    
    newData[newLength] = '\0';
    free(list->array[index].data);
    
    list->array[index].length = newLength;
    list->array[index].data = newData;
}

#endif // ARRAYLIST_H