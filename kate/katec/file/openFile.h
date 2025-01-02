#ifndef OPEN_FILE_H
#define OPEN_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// UTF-8 BOM tanımı
#define UTF8_BOM "\xEF\xBB\xBF"

// UTF-8 BOM'u kontrol eder ve dosya işaretçisini uygun şekilde ayarlar
static inline int checkAndSkipBOM(FILE* file) {
    char bom[4] = {0};

    // Dosyanın başındaki ilk 3 baytı oku
    fread(bom, 1, 3, file);

    // UTF-8 BOM ile karşılaştır
    if (memcmp(bom, UTF8_BOM, 3) == 0) {
        return 1; // BOM bulundu
    } else {
        // Dosya işaretçisini başa geri al
        fseek(file, 0, SEEK_SET);
        return 0; // BOM yok
    }
}

// Dosya içeriğini okuyup bir char* dizisi olarak döndürüyor
static inline char* openFile(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        perror("The file could not be opened"); // Dosya açılamadı
        return NULL;
    }

    // BOM kontrolü
    checkAndSkipBOM(file);

    // Bellekte yer ayırmak için geçici bir tampon oluşturuyor
    char buffer[256];
    size_t totalSize = 1; // '\0' karakterini dahil etmek için 1 ile başlatıyoruz
    char* content = (char*)malloc(totalSize * sizeof(char));

    if (content == NULL) {
        perror("Memory allocation error");
        fclose(file);
        return NULL;
    }

    // İçeriği boş bir string olarak başlat
    content[0] = '\0';

    // Dosyayı okuyor ve içeriği tek bir büyük char dizisine aktarıyor
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        size_t len = strlen(buffer);
        totalSize += len;
        char* temp = (char*)realloc(content, totalSize * sizeof(char));

        if (temp == NULL) {
            perror("Memory allocation error");
            free(content);
            fclose(file);
            return NULL;
        }

        content = temp;
        strcat(content, buffer);
    }

    fclose(file);
    return content;
}

#endif // OPEN_FILE_H
