/*
** EPITECH PROJECT, 2024
** myteams
** File description:
** file that contains packet that will be sent by the server
*/

#ifndef SERVER_PACKET_H
#define SERVER_PACKET_H

#include <uuid/uuid.h>
#include <stdint.h>
#include <stddef.h>
#include <data_types.h>
#include <common_types.h>
#include <stdbool.h>

enum CLIENT_EVENTS {
    EVENT_LOGGED_IN,
    EVENT_LOGGED_OUT,
    EVENT_PRIVATE_MESSAGE_RECEIVED,
    EVENT_THREAD_REPLY_RECEIVED,
    EVENT_TEAM_CREATED,
    EVENT_CHANNEL_CREATED,
    EVENT_THREAD_CREATED,
    EVENT_USER_LISTED
};

typedef struct {
    uint8_t type;
} __attribute__((packed)) server_header_t;

typedef struct {
    uuid_t team_uuid;
    uuid_t thread_uuid;
    uuid_t user_uuid;
    body_t reply_body;
} __attribute__((packed)) reply_data_t;

typedef struct {
    uuid_t uuid;
    name_t name;
    description_t description;
} __attribute__((packed)) team_data_t;

typedef team_data_t channel_data_t;

typedef struct {
    uuid_t thread_uuid;
    uuid_t user_uuid;
    time_t creation_timestamp;
    name_t title;
    body_t body;
} __attribute__((packed)) thread_data_t;

typedef struct {
    uuid_t uuid;
    name_t username;
    bool connected;
} __attribute__((packed)) user_data_t;

typedef struct {
    message_data_t msg;
    time_t timestamp;
} __attribute__((packed)) dm_data_t;

typedef struct {
    server_header_t header;
    union {
        uuid_t uuid;
        user_data_t user_data;
        dm_data_t message_data;
        reply_data_t reply_data;
        team_data_t team_data;
        channel_data_t channel_data;
        thread_data_t thread_data;
    } data;
} __attribute__((packed)) server_packet_t;

#endif //SERVER_PACKET_H
