#include "print.h"
#include "input.h"
#include "compare.h"
#include "reboot.h"

void check_cmd(char* cmd) {
    if (compare_str(cmd, "print")) {
        print_str("Message > ");
        char* message = input();
        print_str(message);
        print_str("\n");
    } else if (compare_str(cmd, "help")) {
        print_str("###############\n" \
                  "# help        #\n" \
                  "# print       #\n" \
                  "# reboot      #\n" \
                  "# color-green #\n" \
                  "# color-white #\n" \
                  "# clear       #\n" \
                  "# info        #\n" \
                  "###############\n");
    } else if (compare_str(cmd, "reboot")) {
        reboot();
    } else if (compare_str(cmd, "color-green")) {
        print_set_color(PRINT_COLOR_GREEN, PRINT_COLOR_BLACK);
        print_str("Text color set to green\n");
    } else if (compare_str(cmd, "color-white")) {
        print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
        print_str("Text color set to default (white)\n");
    } else if (compare_str(cmd, "clear")) {
        print_clear();
    } else if (compare_str(cmd, "info")) {
        print_str("Info:\n" \
                  "OS: icaOS\n" \
                  "Version: 1.1\n");
    } else {
        print_str("Unknown command: ");
        print_str(cmd);
        print_str("\n");
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
    print_str("##################################\n");
    print_str("#        Welcome to IcaOS!       #\n");
    print_str("##################################\n");
    print_str("#           Version 1.1          #\n");
    print_str("##################################\n");
    print_str("# use 'help' to see the commands #\n");
    print_str("##################################\n");
    terminal_loop();
}