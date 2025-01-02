#include "../util/arraylist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Tırnak durumunu kontrol edip boşlukları temizliyor.
void preprocessAndTrim(char* str) {
    char* start = str;
    char* end = str + strlen(str) - 1;
    char currentQuote = '\0';

    // Başlangıç ve bitiş boşluklarını temizle
    while (isspace((unsigned char)*start)) start++;
    while (end >= start && isspace((unsigned char)*end)) end--;

    size_t writeIndex = 0;
    for (char* ptr = start; ptr <= end; ptr++) {
        if (*ptr == '"' || *ptr == '\'') {
            currentQuote = (currentQuote == *ptr) ? '\0' : *ptr; // Tırnak durumunu güncelle
        } else if (currentQuote == '\0' && isspace((unsigned char)*ptr)) {
            continue; // Tırnak dışındaki boşlukları atla
        }
        str[writeIndex++] = *ptr;
    }
    str[writeIndex] = '\0'; // Sonlandırıcı karakteri ekle
}

// Girdi stringini ayırıyor, boşlukları temizliyor ve listeye ekliyor
DynamicArrayList* parse(char* input) {
    DynamicArrayList* resultList = createDynamicArrayList();
    char* token;
    const char* delimiters = ";\{\}";

    token = strtok(input, delimiters);
    while (token) {
        preprocessAndTrim(token); // Tokeni işle ve temizle
        if (*token != '\0') {     // Boş olmayan tokenleri ekle
            append(resultList, token);
        }
        token = strtok(NULL, delimiters);
    }
    return resultList;
}
