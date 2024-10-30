/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** command that check memory block value
*/

#include <stddef.h>
#include <stdbool.h>

bool mem_checkval(const char *block, char byte, size_t size)
{
    for (size_t i = 0; i < size; ++i)
        if (block[i] != byte)
            return (false);
    return (true);
}