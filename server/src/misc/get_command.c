/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that get commands by enum value
*/

#include <commands.h>
#include <types.h>

command_t *get_command(uint8_t type)
{
    for (unsigned int i = 0; i < COMMANDS_NUM; ++i)
        if (commands[i].type == type)
            return (commands[i].command);
    return (NULL);
}