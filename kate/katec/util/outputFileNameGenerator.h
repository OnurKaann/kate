#ifndef OUTPUT_FILE_NAME_GENERATOR_H
#define OUTPUT_FILE_NAME_GENERATOR_H

#include <stdio.h>
#include <string.h>

// Fonksiyon prototipi
char* generate_output_filename(char *arg) {
    static char output_filename[100];  // Değiştirilmiş dosya ismini tutacak yer
    char *dot_position = strchr(arg, '.');
    
    // Eğer nokta varsa
    if (dot_position != NULL) {
        // Uzantıyı değiştir
        strcpy(dot_position + 1, "kexe");  // ".kate"yi ".kexe" ile değiştiriyor .kexe ne moruk neyse :D
    } else {
        // Nokta yoksa, ".kexe" ekle
        snprintf(output_filename, sizeof(output_filename), "%s.kexe", arg);
        return output_filename;
    }

    return arg;  // Değiştirilmiş dosya ismini döndürüyorr
}

#endif 
// OUTPUT_FILE_NAME_GENERATOR_H