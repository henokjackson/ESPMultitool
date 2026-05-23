/**
 * @file main.c
 * @author Henok Jackson
 * @copyright Copyright(c) 2026.
 * @license Licensed under the MIT License.
 */

#include <stdio.h>
#include "../include/file_reader.h"
#include "../include/commandline_parser.h"
#include "../include/hexdump_viewer.h"

int main(int argc, char* argv[]) {

    // Extract the commandline arguments.
    extract_commandline_arguments(argc, argv);

    // Flag 1: Hex view.
    if (g_hex_view == true) {
        // Check if file path was set.
        if (g_file_path_set == false) {
            printf("No file path specified !\n");
            return -1;
        }

        // Open file stream.
        FILE* binary_file = open_file_stream(g_file_path, "rb");
        if (binary_file == NULL) {
            return -1;
        }

        // Generate hexdump preview.
        render_hexdump(binary_file);

        // Close file.
        if (close_file_stream(&binary_file) != true) {
            printf("Error while closing file !\n");
            return -1;
        }
    }

    return 0;
}