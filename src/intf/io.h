#pragma once

static inline unsigned char inb(unsigned short port) {
    unsigned char result;
    __asm__ __volatile__("inb %1, %0" : "=a"(result) : "Nd"(port));
    return result;
}