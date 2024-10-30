/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** main server loop
*/

#include <types.h>
#include <stdbool.h>
#include <stdio.h>
#include <core.h>
#include <signal.h>
#include <sys/signalfd.h>
#include <save.h>

static int get_sfd(void)
{
    sigset_t mask;
    int sfd;

    sigemptyset(&mask);
    sigaddset(&mask, SIGINT);
    if (sigprocmask(SIG_BLOCK, &mask, NULL) == -1) {
        perror("sigprocmask");
        return (-1);
    }
    sfd = signalfd(-1, &mask, 0);
    if (sfd == -1) {
        perror("signalfd");
        return (-1);
    }
    return (sfd);
}

bool loop(server_t *server)
{
    fd_set read_fds;
    fd_set write_fds;
    int sfd = get_sfd();

    if (sfd == -1)
        return (false);
    FD_SET(sfd, &(server->sock->read_fd_set));
    while (true) {
        read_fds = server->sock->read_fd_set;
        write_fds = server->sock->write_fd_set;
        if (select(FD_SETSIZE, &(read_fds), &(write_fds), NULL, NULL) == -1) {
            perror("select");
            return (false);
        }
        if (!process_read_fds(server, read_fds, sfd)) {
            save_users(server->users);
            return (false);
        }
        process_write_fds(server, write_fds);
    }
}
