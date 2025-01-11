#include "print.h"
#include "input.h"
#include "compare.h"

void check_cmd(char* cmd) {
    if (compare_str(cmd, "print")) {
        print_str("Message > ");
        char* message = input();
        print_str(message);
        print_str("\n");
    } else {
        print_str("Unknown command\n");
    }
}

void terminal_loop() {
    while (1) {
        print_str("icaOS > ");
        char* command = input();
        check_cmd(command);
    }
}

void kernel_main() {
    print_clear();
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    print_str("Welcome to IcaOS!\n");
    terminal_loop();
}