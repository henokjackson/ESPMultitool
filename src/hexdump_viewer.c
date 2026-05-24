/**
 * @file hexdump_viewer.c
 * @author Henok Jackson
 * @copyright Copyright(c) 2026.
 * @license Licensed under the MIT License.
 */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../include/file_reader.h"

unsigned long int get_hex_address_range(unsigned long long int file_size) {
    if (file_size == 0) {
        printf("WARNING: file size is 0 bytes !");
    }

    unsigned long int hex_digit_count = 1;
    while (file_size != 0 && file_size != 1) {
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

char* generate_hex_address(const unsigned long int address_hex_digit_count,
    unsigned long int index,
    char* address,
    const char* address_hex_prefix,
    const unsigned long int address_length) {
    if (index == 0 ||
        address_hex_digit_count == 0 ||
        address_length == 0 ||
        address_hex_prefix == nullptr ||
        address == nullptr) {
        printf("Invalid arguments !");
        return nullptr;
    }

    // Calculate no.of digits of index
    /* INFO: There are no built-in function to calculate the length of int types.
     * Since looping through is not performant we are using the logarithmic method.
     * Log10(n) is always gonna look for nearest number of 10s to be multiplied and add one to it.
     * Casting it to an int type will drop the  mantissa. However this will fail for 0.
     * Actually we don't need index calculation -> reversing the loop handles it.
     */
    //const unsigned int index_len = (int)log10(abs(index)) + 1;

    address[0] = address_hex_prefix[0];
    address[1] = address_hex_prefix[1];
    for (unsigned long int i = address_length - 1; i > 1; i--) {
        if (index != 0) {
            address[i] = index % 10;
            index = index / 10;
        } else {
            address[i] = '0';
        }
    }

    return address;
}

void render_hexdump(FILE* file_stream) {
    // Set file pointer to the beginning.
    errno = 0;
    rewind(file_stream);
    if (errno != 0) {
        perror("Error reading file");
    }

    // Get file size.
    const off_t file_size = get_file_size(file_stream);

    /* Calculate address range in hex.
     * INFO: off_t is a signed long long int.
       Casting signed long long int to unsigned long long int is generally considered safe
       especially in case of positive integers.
     */
    const unsigned long int address_hex_digit_count = get_hex_address_range(file_size);
    const char* address_hex_prefix = "0x";
    const unsigned long int address_length = address_hex_digit_count + strlen(address_hex_prefix);
    char address[address_length];
    unsigned char byte;

    // Read file byte by byte.
    for (unsigned long int i = 0; i < file_size; i++) {
        byte = read_byte(file_stream);
        printf("%s\t%x\t|%c|\n",
            generate_hex_address(address_hex_digit_count,
                file_size,
                address,
                address_hex_prefix,
                address_length),
            byte,
            convert_byte_to_ascii_char(byte));
    }
}