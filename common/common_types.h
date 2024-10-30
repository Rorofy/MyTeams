/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** shared types
*/

#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H

#define BUFF_SIZE 8192

#include <uuid/uuid.h>
#include <vlib/vlib.h>

typedef struct {
    char *msg;
    time_t msg_timestamp;
} message_t;

typedef struct {
    uuid_t target;
    vector(message_t) *messages;
} conversation_t;

typedef struct {
    uuid_t user_uuid;
    body_t message_body;
} __attribute__((packed)) message_data_t;

#endif //COMMON_TYPES_H
