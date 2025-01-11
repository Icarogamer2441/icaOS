#include "io.h"
#include "input.h"
#include "print.h"

#define INPUT_BUFFER_SIZE 256
#define KEYBOARD_DATA_PORT 0x60

static char read_scancode();
static char scancode_to_char(char scancode);

char* input() {
    static char buffer[INPUT_BUFFER_SIZE];
    int index = 0;
    print_set_color(PRINT_COLOR_GREEN, PRINT_COLOR_BLACK);

    while (1) {
        char scancode = read_scancode();
        if (scancode & 0x80) {  // Ignora release key
            continue;
        }

        // Detecta backspace diretamente pelo scancode (0x0E)
        if (scancode == 0x0E) {
            if (index > 0) {
                index--;
                print_char('\b');
                print_char(' ');
                print_char('\b');
            }
            continue;
        }

        char c = scancode_to_char(scancode);
        if (c == '\n') {
            buffer[index] = '\0';
            print_char('\n');
            return buffer;
        }
        else if (c >= ' ' && c <= '~' && index < INPUT_BUFFER_SIZE - 1) {
            buffer[index] = c;
            print_char(c);
            index++;
        }
    }
}

static char read_scancode() {
    while (!(inb(0x64) & 1)) { }
    return inb(KEYBOARD_DATA_PORT);
}

static char scancode_to_char(char scancode) {
    static const char scancode_table[] = {
        0, 27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', 0,   // mudado '\b' para 0
        '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
        0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0,
        '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, '*', 0, ' '
    };

    if (scancode < sizeof(scancode_table)) {
        return scancode_table[scancode];
    }
    return 0;
}