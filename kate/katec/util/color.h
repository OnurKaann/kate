#include <stdio.h>

enum colors {
    BLACK = 0,
    RED = 4,
    GREEN = 2,
    YELLOW = 6,
    BLUE = 1,
    PURPLE = 5,
    CYAN = 3,
    WHITE = 7
};

#ifdef __linux__
    void setColor(enum colors color) {
        // Linux için renk ayarlama kodu
        switch (color) {
        case BLACK:
            printf("%s", "\033[0;30m");
            break;
        case RED:
            printf("%s", "\033[0;31m");
            break;
        case GREEN:
            printf("%s", "\033[0;32m");
            break;
        case YELLOW:
            printf("%s", "\033[0;33m");
            break;
        case BLUE:
            printf("%s", "\033[0;34m");
            break;
        case PURPLE:
            printf("%s", "\033[0;35m");
            break;
        case CYAN:
            printf("%s", "\033[0;36m");
            break;
        case WHITE:
            printf("%s", "\033[0;37m");
            break;
        default:
            break;
        }
    }
#endif

#ifdef _WIN32
#include <windows.h>

// Windows için setColor fonksiyonu
void setColor(enum colors color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Windows terminal handle
    SetConsoleTextAttribute(hConsole, color);  // Rengi ayarlıyoruz
}
#endif


//Windows 32 bit + 64 bit -> _WIN32 (for all Windows OS)
//Apple -> __APPLE__ (for all Apple OS)
//Linux -> __linux__ (subset of unix)
//BSD -> BSD (BSD)