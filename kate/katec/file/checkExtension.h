#include <stdbool.h>
#include <string.h>

bool checkExtension(const char* filename, const char* extension) {
    size_t filenameLen = strlen(filename);
    size_t extensionLen = strlen(extension);

    if (filenameLen <= extensionLen) {
        return false; // Dosya adı uzantıdan kısa olamaz
    }

    const char* extensionStart = filename + filenameLen - extensionLen;

    return (strcmp(extensionStart, extension) == 0);
}