/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** client types
*/

#ifndef TYPES_H
#define TYPES_H

#include <uuid/uuid.h>
#include <vlib/vlib.h>
#include <client_packet.h>
#include <common_types.h>

typedef struct
{
    char *name;
    uuid_t uuid;
} user_t;

typedef struct
{
    int fd;
    char *name;
    size_t buff_size;
    unsigned char *buff;
    uuid_t context;
    uuid_t uuid;
    vector (conversation_t) *conversations;
} client_t;

typedef struct {
    const char *ip;
    uint16_t port;
} options_t;

typedef void (command_t)(client_t *client, const char *input);

#endif //TYPES_H
