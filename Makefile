##
## EPITECH PROJECT, 2021
## myteams
## File description:
## project's makefile
##

include client/client.mk
include server/server.mk

CPPFLAGS	+=	-I lib/
CPPFLAGS	+=	-I common/
CPPFLAGS	+=	-I protocol/

CFLAGS		+=	-Wall
CFLAGS		+=	-Wextra

LDFLAGS		+=	-L ./lib/myteams/
LDFLAGS		+=	-l myteams
LDFLAGS		+=	-l uuid

OBJ_DIR		:=	build/

CC			:=	gcc
RM			:=	rm -rf

VLIB_PATH	:=	lib/vlib/

ifeq ($(ASAN), TRUE)
	CFLAGS	+= -fsanitize=address
	LDFLAGS	+= -lasan
endif

ifeq ($(DEBUG), TRUE)
	CFLAGS	+= -g3 -O0
endif

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

all: client server

client: CPPFLAGS += -I client/include/
client: $(CLIENT_OBJ)
	$(CC) -o $(CLIENT_NAME) $(CFLAGS) $(LDFLAGS) $(CLIENT_OBJ)

server: CPPFLAGS += -I server/include/
server: $(SERVER_OBJ)
	$(CC) -o $(SERVER_NAME) $(CFLAGS) $(LDFLAGS) $(SERVER_OBJ)

tests_run: fclean
	make -C $(VLIB_PATH) tests_run

clean:
	$(RM) $(CLIENT_OBJ)
	$(RM) $(SERVER_OBJ)
	make -C $(VLIB_PATH) clean

fclean: clean
	$(RM) $(CLIENT_NAME)
	$(RM) $(SERVER_NAME)
	$(RM) vgcore.*
	make -C $(VLIB_PATH) fclean

re: fclean all

.PHONY: all client server tests_run clean fclean re
