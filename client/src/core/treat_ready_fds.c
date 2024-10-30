/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that treats ready fds
*/

#include <types.h>
#include <stdio.h>
#include <unistd.h>
#include <core.h>

static void serve_stdin(client_t *client)
{
    char *buff = NULL;
    size_t n = 0;

    if (getline(&buff, &n, stdin) != -1) {
        parse_command(client, buff);
        free(buff);
    }
}

static void serve_server(client_t *client)
{
    unsigned char buff[BUFF_SIZE] = {0};
    ssize_t read_size = read(client->fd, buff, BUFF_SIZE);

    if (read_size > 0) {
        client->buff = reallocarray(
            client->buff,
            client->buff_size + read_size,
            sizeof(unsigned char)
        );
        memcpy(client->buff + client->buff_size, buff, read_size);
        client->buff_size += read_size;
        treat_server_data(client);
    }
}

void treat_ready_fds(client_t *client, fd_set *set)
{
    if (FD_ISSET(0, set))
        serve_stdin(client);
    if (FD_ISSET(client->fd, set))
        serve_server(client);
}
