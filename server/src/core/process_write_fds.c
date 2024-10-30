/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that process writing fd set
*/

#include <stdlib.h>
#include <types.h>
#include <stdbool.h>
#include <core.h>

bool process_write_fds(server_t *server, fd_set write_fds)
{
    for (int i = 0; i < FD_SETSIZE; ++i)
        if (FD_ISSET(i, &write_fds))
            treat_write_fd(server, i);
    return (true);
}
