/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** header that contains commands map
*/

#ifndef COMMANDS_H
#define COMMANDS_H

#define COMMANDS_NUM (sizeof(commands) / sizeof(cmd_pair_t))
#define CREATE_FUN_PAIR(fun_name)   \
    {                               \
        .command = &fun_name,       \
        .name = #fun_name           \
    }

void help(client_t *client, const char *input);
void login(client_t *client, const char *input);
void logout(client_t *client, const char *input);
void users(client_t *client, const char *input);
void user(client_t *client, const char *input);
void send(client_t *client, const char *input);
void messages(client_t *client, const char *input);
void subscribe(client_t *client, const char *input);
void subscribed(client_t *client, const char *input);
void unsubscribe(client_t *client, const char *input);
void use(client_t *client, const char *input);
void create(client_t *client, const char *input);
void list(client_t *client, const char *input);
void info(client_t *client, const char *input);

typedef struct {
    command_t *command;
    const char *name;
} cmd_pair_t;

cmd_pair_t commands[] = {
    CREATE_FUN_PAIR(help),
    CREATE_FUN_PAIR(login),
    CREATE_FUN_PAIR(logout),
    CREATE_FUN_PAIR(users),
    CREATE_FUN_PAIR(user),
    CREATE_FUN_PAIR(send),
    CREATE_FUN_PAIR(messages),
    CREATE_FUN_PAIR(subscribe),
    CREATE_FUN_PAIR(subscribed),
    CREATE_FUN_PAIR(unsubscribe),
    CREATE_FUN_PAIR(use),
    CREATE_FUN_PAIR(create),
    CREATE_FUN_PAIR(list),
    CREATE_FUN_PAIR(info)
};

#endif //COMMANDS_H
