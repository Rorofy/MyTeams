/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that inits the socket
*/

#include <stdint.h>
#include <sys/socket.h>
#include <resolv.h>
#include <stdbool.h>
#include <unistd.h>

static bool bind_server(uint16_t port, int socket)
{
    struct sockaddr_in name = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr = {
            .s_addr = htonl(INADDR_ANY),
        }
    };
    int ret = bind(socket, (struct sockaddr *)&name, sizeof(name));
    if (ret == -1)
        perror("bind");
    return (ret != -1);
}

static int set_server_options(int socket)
{
    int enable = 1;
    int ret = setsockopt(
        socket,
        SOL_SOCKET,
        SO_REUSEADDR,
        &enable,
        sizeof(int)
    );

    if (ret == -1)
        perror("setsockopt");
    return (ret != -1);
}

static int return_error(int fd)
{
    close(fd);
    return (-1);
}

int init_raw_socket(uint16_t port)
{
    int res = socket(AF_INET, SOCK_STREAM, 0);

    if (res == -1) {
        perror("socket");
        return (-1);
    }
    if (!set_server_options(res))
        return return_error(res);
    if (!bind_server(port, res))
        return return_error(res);
    if (listen(res, FD_SETSIZE) == -1) {
        perror("listen");
        return return_error(res);
    }
    return (res);
}
