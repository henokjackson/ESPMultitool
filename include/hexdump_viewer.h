/**
 * @file hexdump_viewer.h
 * @author Henok Jackson
 * @copyright Copyright(c) 2026.
 * @license Licensed under the MIT License.
 */

#ifndef ESP8266_MULTITOOL_HEXDUMP_VIEWER_H
#define ESP8266_MULTITOOL_HEXDUMP_VIEWER_H

#include <stdio.h>

/**
 * Renders the hexdump view.
 * @param file_stream The file stream.
 */
void render_hexdump(const FILE* file_stream);

#endif //ESP8266_MULTITOOL_HEXDUMP_VIEWER_H