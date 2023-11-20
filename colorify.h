#define RESET "\033[0m"

// Foreground colors
#define BLACK_FG "\033[30m"
#define RED_FG "\033[31m"
#define GREEN_FG "\033[32m"
#define YELLOW_FG "\033[33m"
#define BLUE_FG "\033[34m"
#define MAGENTA_FG "\033[35m"
#define CYAN_FG "\033[36m"
#define WHITE_FG "\033[37m"


void clear_screen()
{
    #ifdef _WIN32
        system("cls"); // For Windows
    #else
        system("clear"); // For Unix-like systems
    #endif
}