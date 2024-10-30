/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** core header file
*/

#ifndef CORE_H
#define CORE_H

#include <stdbool.h>
#include "types.h"

bool loop(server_t *server);
bool process_read_fds(server_t *server, fd_set read_fds, int sfd);
bool process_write_fds(server_t *server, fd_set write_fds);
void treat_read_fd(server_t *server, int fd);
void treat_write_fd(server_t *server, int fd);
void accept_client(server_t *server);
void send_message(
    server_t *server,
    client_t *client,
    const char *msg,
    size_t msg_len
);
void disconnect_client(server_t *server, client_t *client);

#endif //CORE_H
