#include "file/openFile.h"
#include "file/checkExtension.h"
#include "parser/parser.h"
#include "util/color.h"
#include "output/output.h"
#include "util/outputFileNameGenerator.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[]) {
    char* content = openFile(argv[1]);
    if (content == NULL) {
        setColor(RED);
        puts("Failed to open the file (wrong filePath or Empty).");
        setColor(WHITE);
        return 1;
    }
    else if (!checkExtension(argv[1], "kate")) {
        setColor(YELLOW);
        puts("The file extension should be '.kate'.");
        setColor(WHITE);
        return 1;
    }

    /*
    NULL'a kadar olan elemanları ekrana yazdırıyor.
    puts(content);
    */
    /*
    for (size_t i = 0; i < parsedContent->size; i++) {
        printf("Array %zu: %s\n", i, parsedContent->array[i].str);
    }
    */

    //Dinamik char arraylerimizi saklayan ArrayList
    //DynamicArrayList* parsedContent = restore(splitAndStore(content));
    DynamicArrayList* parsedContent = parse(content);

    for (size_t i = 0; i < parsedContent->size; i++) {
         printf("%zu:|%s|\n", i, parsedContent->array[i].data);
     }

    char* filename = generate_output_filename(argv[1]); //oluşturulmuş output dosyası ismi.

    // Liste elemanlarını tek bir dosyaya yazdır
    writeAllElementsToFile(parsedContent, filename);
    
    freeDynamicArrayList(parsedContent);
    free(content);
    return 0;
}