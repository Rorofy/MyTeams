/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** header that contains misc functions
*/

#ifndef MISC_H
#define MISC_H

#include <server_packet.h>

void display_help(void);
char *remove_newline(char *str);
server_packet_t *pop_first_server_msg(client_t *client);
char *get_first_string(const char *str);

#endif //MISC_H
