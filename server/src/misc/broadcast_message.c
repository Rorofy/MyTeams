/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that broadcasts a message to all clients
*/

#include <types.h>
#include <core.h>
#include <stdio.h>
#include <misc.h>

void broadcast_message(
    server_t *server,
    const char *msg,
    size_t msg_len)
{
    vector_foreach(server->clients, e)
        if (!mem_checkval((const char *)e->uuid, 0, sizeof(uuid_t)))
            send_message(server, e, msg, msg_len);
}