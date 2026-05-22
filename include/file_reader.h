/**
 * @file file_reader.h
 * @copyright Copyright(c) 2026 Henok Jackson. All rights reserved.
 * @license Licensed under the MIT License.
 */

#ifndef ESP8266_MULTITOOL_FILE_READER_H
#define ESP8266_MULTITOOL_FILE_READER_H

#include <stdio.h>
#include <sys/_types/_off_t.h>

/**
 * Returns the size of the file.
 * @param file_stream The file stream.
 * @return The file size in bytes.
 */
off_t get_file_size(FILE* file_stream);

/**
 * Opens a file stream for a given path and mode.
 * @param file_path The file path.
 * @param mode The file read/write mode.
 * @return A file stream object to the given file path if it exists.
 */
FILE* open_file_stream(const char* file_path, const char* mode);

/**
 * Closes an open file stream.
 * @param file_stream_ptr Reference of a file stream object.
 * @return A boolean flag indicating the result of the close() operation.
 */
bool close_file_stream(FILE** file_stream_ptr);

/**
 * Reads a byte from the file stream.
 * @param file_stream The file stream object.
 * @return A byte read from the file stream.
 */
unsigned char read_byte(FILE* file_stream);

#endif