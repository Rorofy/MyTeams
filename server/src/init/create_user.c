/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** function inits a client
*/

#include <uuid/uuid.h>
#include <types.h>

void create_user(user_t *user, const char *username)
{
    memset(user, 0, sizeof(user_t));
    strcpy(user->name, username);
    user->conversations = vector_create(conversation_t);
    user->subscribed = vector_create(uuid_t);
    uuid_generate(user->uuid);
}
