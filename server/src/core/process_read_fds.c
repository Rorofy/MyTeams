/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that process reading fd_set
*/

#include <stdlib.h>
#include <stdbool.h>
#include <types.h>
#include <core.h>

bool process_read_fds(server_t *server, fd_set read_fds, int sfd)
{
    if (FD_ISSET(sfd, &read_fds))
        return (false);
    for (int i = 0; i < FD_SETSIZE; ++i)
        if (FD_ISSET(i, &read_fds))
            treat_read_fd(server, i);
    return (true);
}
