/**
 * @file hexdump_viewer.c
 * @copyright Copyright(c) 2026 Henok Jackson. All rights reserved.
 * @license Licensed under the MIT License.
 */

#include <stdio.h>

unsigned long int get_hex_address_range(unsigned long long int file_size) {
    if (file_size == 0) {
        printf("WARNING: file size is 0 bytes !");
    }

    unsigned long int hex_digit_count = 1;
    while (file_size % 16 != 0) {
        hex_digit_count++;
        file_size /= 16;
    }

    return hex_digit_count;
}

unsigned char convert_byte_to_ascii_char (unsigned char byte) {
    if ((int)byte >= 32 && (int)byte <= 126) {
        return byte;
    }
    else {
        return '.';
    }
}

void render_hexdump(const FILE* file_stream) {

}