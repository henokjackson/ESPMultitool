/**
 * @file commandline_parser.c
 * @author Henok Jackson
 * @copyright Copyright(c) 2026.
 * @license Licensed under the MIT License.
 */

#include "../include/commandline_parser.h"
#include <stdio.h>
#include <string.h>

#define MAX_COMMAND_LINE_ARGS_COUNT 10
#define HEX_VIEW_ARG_STR "--hexview"

bool g_hex_view = false;
bool g_file_path_set = false;
char g_file_path[500];

void show_commandline_help() {
    printf("Invalid arguments !");
    printf("\n\nUsage: esp8266-multitool [FLAGS ...]\n");
    printf("Example:\n");
    printf("\tToggling hex view:\n");
    printf("\t\t--hexview filename\tGenerates the maximum possible fibonacci number that can be generated with the given heap.\n");
}

void extract_commandline_arguments(int argc, char* argv[]) {
    if (argc > MAX_COMMAND_LINE_ARGS_COUNT) {
        printf("Too many arguments !\n");
        return;
    }

    for (int i = 1; i < argc; i++) {
        bool command_invalid = true;

        if (g_hex_view == false && strcmp(HEX_VIEW_ARG_STR, argv[i]) == 0) {
            g_hex_view = true;
            command_invalid = false;
        }

        if (g_file_path_set == false &&
            argv[i][0] != '-' &&
            argv[i][1] != '-') {
            strcpy(g_file_path, argv[i]);
            g_file_path_set = true;
            command_invalid = false;
        }

        if (command_invalid == true) {
            show_commandline_help();
            return;
        }
    }
}