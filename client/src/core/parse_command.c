/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that parse an user command
*/

#include <types.h>
#include <stdio.h>
#include <commands.h>
#include <misc.h>

static char *isolate_command_name(const char *str)
{
    int i = 0;
    char *res = strdup(str + 1);

    for (; res[i] != '\0' && res[i] != ' ' && res[i] != '\n'; ++i);
    res[i] = '\0';
    return (res);
}

static command_t *get_command(const char *name)
{
    for (size_t i = 0; i < COMMANDS_NUM; ++i)
        if (strcasecmp(commands[i].name, name) == 0)
            return commands[i].command;
    return (NULL);
}

void parse_command(client_t *client, char *in)
{
    command_t *cmd;
    char *cmd_name;

    if (*in == '/') {
        cmd_name = isolate_command_name(in);
        cmd = get_command(cmd_name);
        remove_newline(in);
        if (cmd != NULL)
            cmd(client, in + strlen(cmd_name) + 2);
        else
            printf("Command not found\n");
        free(cmd_name);
    } else
        printf("Invalid syntax, commands should start with a slash\n");
}
