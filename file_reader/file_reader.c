/**
 * @file file_reader.c
 * @copyright Copyright(c) 2026 Henok Jackson. All rights reserved.
 * @license Licensed under the MIT License.
 */

#include "file_reader.h"
#include <sys/stat.h>
#include <stdio.h>

off_t get_file_size(const char* file_name) {
    struct stat file_stat;

    int const stat_status = stat(file_name, &file_stat);
    if (stat_status == -1) {
        perror("Error opening file !");
        return -1;
    }

    return file_stat.st_size;
}

FILE* open_file_stream(const char* file_path, const char* mode) {
    FILE* file_stream = fopen(file_path, mode);
    if (!file_stream) {
        perror("Error opening file !");
        return nullptr;
    }

    return file_stream;
}

bool close_file_stream(FILE** file_stream_ptr) {
    const bool is_closed = fclose(*file_stream_ptr) == 0 ? true : false;
    if (is_closed) {
        *file_stream_ptr = nullptr;
    }

    return is_closed;
}

int read_byte(FILE* file_stream) {
    const int ascii_byte = fgetc(file_stream);
    if (ascii_byte == EOF) {
        return EOF;
    }
    const unsigned char byte = (unsigned char)ascii_byte;

    return byte;
}