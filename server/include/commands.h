/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** header that contains all commands
*/

#ifndef COMMANDS_H
#define COMMANDS_H

#include "types.h"

#define COMMANDS_NUM (sizeof(commands) / sizeof(cmd_pair_t))

#define CREATE_FUN_PAIR(fun_name, f_type)   \
    {                                       \
        .command = &fun_name,               \
        .type = f_type                      \
    }

void login(server_t *server, client_t *client, client_packet_t *packet);
void logout(server_t *server, client_t *client, client_packet_t *packet);
void users(server_t *server, client_t *client, client_packet_t *packet);
void user(server_t *server, client_t *client, client_packet_t *packet);
void send(server_t *server, client_t *client, client_packet_t *packet);
void subscribe(server_t *server, client_t *client, client_packet_t *packet);
void subscribed(server_t *server, client_t *client, client_packet_t *packet);
void unsubscribe(server_t *server, client_t *client, client_packet_t *packet);
void create(server_t *server, client_t *client, client_packet_t *packet);
void info(server_t *server, client_t *client, client_packet_t *packet);

typedef struct {
    command_t *command;
    const char type;
} cmd_pair_t;

cmd_pair_t commands[] = {
    CREATE_FUN_PAIR(login, LOGIN),
    CREATE_FUN_PAIR(logout, LOGOUT),
    CREATE_FUN_PAIR(users, USERS),
    CREATE_FUN_PAIR(user, USER),
    CREATE_FUN_PAIR(send, SEND),
    CREATE_FUN_PAIR(subscribe, SUBSCRIBE),
    CREATE_FUN_PAIR(subscribed, SUBSCRIBED),
    CREATE_FUN_PAIR(unsubscribe, UNSUBSCRIBE),
    CREATE_FUN_PAIR(create, CREATE),
    CREATE_FUN_PAIR(info, INFO)
};

#endif //COMMANDS_H
