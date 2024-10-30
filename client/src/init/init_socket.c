/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function that init socket
*/

#include <stdint.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int init_socket(const char *addr, uint16_t port)
{
    int res = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in sock_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(port)
    };

    if (res == -1)
        return (-1);
    if (inet_pton(AF_INET, addr, &(sock_addr.sin_addr)) == -1)
        return (-1);
    if (connect(res, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) == -1)
        return (-1);
    return (res);
}
