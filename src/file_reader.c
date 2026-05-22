/**
 * @file file_reader.c
 * @copyright Copyright(c) 2026 Henok Jackson. All rights reserved.
 * @license Licensed under the MIT License.
 */

#include "../include/file_reader.h"
#include <sys/stat.h>
#include <stdio.h>

off_t get_file_size(FILE* file_stream) {
    if (file_stream == nullptr) {
        printf("Invalid argument passed !");
        return -1;
    }

    const int file_descriptor = fileno(file_stream);
    if (file_descriptor == -1) {
        perror("Error opening file !");
    }

    struct stat file_stat;
    int const stat_status = fstat(file_descriptor, &file_stat);
    if (stat_status != 0) {
        perror("Error opening file !");
        return -1;
    }

    return file_stat.st_size;
}

FILE* open_file_stream(const char* file_path, const char* mode) {
    if (file_path == nullptr || mode == nullptr) {
        printf("Invalid arguments passed !");
        return nullptr;
    }

    FILE* file_stream = fopen(file_path, mode);
    if (!file_stream) {
        perror("Error opening file !");
        return nullptr;
    }

    return file_stream;
}

bool close_file_stream(FILE** file_stream_ptr) {
    if (file_stream_ptr == nullptr) {
        printf("Invalid arguments passed !");
        return false;
    }
    const bool is_closed = fclose(*file_stream_ptr) == 0 ? true : false;
    if (is_closed) {
        *file_stream_ptr = nullptr;
    }

    return is_closed;
}

unsigned char read_byte(FILE* file_stream) {
    if (file_stream == nullptr) {
        printf("Invalid arguments passed !");
        return -1;
    }

    const int ascii_byte = fgetc(file_stream);
    if (ascii_byte == EOF) {
        return EOF;
    }

    const unsigned char byte = (unsigned char)ascii_byte;

    return byte;
}