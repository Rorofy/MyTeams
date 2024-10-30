/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that process a fd given by process_write_fds
*/

#include <types.h>
#include <misc.h>
#include <stdio.h>

void treat_write_fd(server_t *server, int fd)
{
    client_t *client = get_client_from_fd(server, fd);

    if (client == NULL)
        return;
    write_buffered_output(server, client);
}