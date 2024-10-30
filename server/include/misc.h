/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** misc header file
*/

#ifndef MISC_H
#define MISC_H

#include <stdbool.h>
#include "types.h"

bool buffer_user_input(client_t *client);
bool write_buffered_output(server_t *server, client_t *client);
void destroy_socket(socket_t *sock);
bool error_management(int ac, const char **av);
uint16_t parse_user_input(const char *arg);
void display_help(void);
client_t *get_client_from_fd(server_t *server, int fd);
client_packet_t *get_first_packet_from_buff(client_t *client);
void treat_incoming_packet(
    server_t *server,
    client_t *client,
    client_packet_t *packet);
command_t *get_command(uint8_t type);
void broadcast_message(server_t *server, const char *msg, size_t msg_len);
bool mem_checkval(const char *block, char byte, size_t size);

#endif //MISC_H
