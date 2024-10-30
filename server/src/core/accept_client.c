/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that accept clients and push them into the server client list
*/

#include <types.h>
#include <resolv.h>
#include <core.h>
#include <init.h>

static void append_client(server_t *server, int user_fd)
{
    client_t client;

    init_client(&client, user_fd);
    vector_emplace_back(server->clients, client);
}

void accept_client(server_t *server)
{
    struct sockaddr_in client_addr;
    size_t size = sizeof(client_addr);
    int new_client = accept(
        server->sock->fd,
        (struct sockaddr *) &client_addr,
        (socklen_t *) &size
    );

    if (new_client < 0)
        perror("accept");
    else {
        FD_SET(new_client, &(server->sock->read_fd_set));
        append_client(server, new_client);
    }
}
