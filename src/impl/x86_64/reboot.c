#include "reboot.h"

static void acpi_reboot() {
    __asm__ volatile(
        "mov $0x0, %%eax;"
        "int $0x15;"
        :
        :
        : "eax"
    );
}

void reboot() {
    acpi_reboot();
}