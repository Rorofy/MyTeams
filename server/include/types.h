/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** server types
*/

#ifndef TYPES_H
#define TYPES_H

#include <vlib/vlib.h>
#include <data_types.h>
#include <client_packet.h>
#include <server_packet.h>
#include <common_types.h>

typedef struct {
    const char *title;
    const char *message;
    const uuid_t uuid;
    vector (message_t) *replies;
} thread_t; //in channels

typedef struct {
    char *name;
    char *description;
    uuid_t uuid;
    vector (thread_t) *threads;
} channel_t; //in teams

typedef struct {
    char *title;
    char *message;
    uuid_t uuid;
    vector (channel_t) *channels;
} team_t;

typedef struct {
    name_t name;
    uuid_t uuid;
    uint64_t numberOfConnections;
    vector (conversation_t) *conversations;
    vector (uuid_t) *subscribed;
} user_t;

typedef struct {
    int fd;
    uuid_t uuid;
    size_t read_size;
    size_t write_size;
    unsigned char *reading_buff;
    unsigned char *writing_buff;
} client_t;

typedef struct {
    int fd;
    uint16_t port;
    fd_set read_fd_set;
    fd_set write_fd_set;
} socket_t;

typedef struct {
    socket_t *sock;
    vector(team_t) *teams;
    vector(user_t) *users;
    vector(client_t) *clients;
} server_t;

typedef void (command_t)(
    server_t *server,
    client_t *client,
    client_packet_t *packet
);

#endif //TYPES_H
