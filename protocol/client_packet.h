/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** this header contains the packets that will be sent by client
*/

#ifndef PACKET_H
#define PACKET_H

#include <stdint.h>
#include <stddef.h>
#include <data_types.h>
#include <common_types.h>

enum CLIENT_PACKET_TYPE {
    LOGIN = 1,
    LOGOUT = 2,
    USERS = 3,
    USER = 4,
    SEND = 5,
    SUBSCRIBE = 6,
    SUBSCRIBED = 7,
    UNSUBSCRIBE = 8,
    CREATE = 9,
    INFO = 10
};

typedef struct {
    uint8_t type;
} __attribute__((packed)) client_header_t;

typedef struct {
    name_t name;
    union {
        description_t description;
        body_t message;
    };
    uuid_t context;
} __attribute__((packed)) creation_t;

typedef struct {
    body_t body;
} __attribute__((packed)) reply_creation_t;

typedef struct {
    client_header_t header;
    union {
        name_t username;
        uuid_t uuid;
        message_data_t msg_send_data;
        creation_t creation_data;
        reply_creation_t reply_data;
    } data;
} __attribute__((packed)) client_packet_t;

#endif //PACKET_H
