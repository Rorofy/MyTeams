/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** server struct initialization function
*/

#ifndef INIT_H
#define INIT_H

#include <stdint.h>
#include "types.h"

server_t *init_server_struct(uint16_t port);
socket_t *init_server_socket(uint16_t port);
int init_raw_socket(uint16_t port);
void create_user(user_t *user, const char *username);
void init_client(client_t *client, int client_fd);

#endif //INIT_H
