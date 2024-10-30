/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** core header
*/

#ifndef LOOP_H
#define LOOP_H

#include <server_packet.h>

int loop(client_t *client);
void treat_ready_fds(client_t *client, fd_set *set);
void parse_command(client_t *client, char *in);
void treat_server_data(client_t *client);
void parse_event(client_t *client, server_packet_t *packet);

#endif //LOOP_H
