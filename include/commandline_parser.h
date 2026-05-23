/**
 * @file commandline_parser.h
 * @author Henok Jackson
 * @copyright Copyright(c) 2026.
 * @license Licensed under the MIT License.
 */
#ifndef ESP8266_MULTITOOL_COMMANDLINE_PARSER_H
#define ESP8266_MULTITOOL_COMMANDLINE_PARSER_H

extern bool g_hex_view;
extern bool g_file_path_set;
extern char g_file_path[500];

void extract_commandline_arguments(int argc, const char** argv);

#endif //ESP8266_MULTITOOL_COMMANDLINE_PARSER_H