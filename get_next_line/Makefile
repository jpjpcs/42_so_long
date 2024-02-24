# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaosilva <joaosilva@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 19:46:31 by joaosilva         #+#    #+#              #
#    Updated: 2024/02/23 19:46:32 by joaosilva        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a

SRC = get_next_line_bonus.c get_next_line_utils_bonus.c 

OBJS = ${addprefix ../get_next_line_obj/, ${SRC:.c=.o}}
HEADER = get_next_line_bonus.h
INCLUDE = -I .
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror



### cria o libft.a. cria os ficheiro objeto, assim como o header. O bibft.a congrega todos os ficheiros objetos.
all: ${NAME}
$(NAME): ${OBJS} ${HEADER}
	ar rcs ../get_next_line_obj/${NAME} ${OBJS} ${HEADER}
	@echo "$(GREEN)\n${NAME} GNL created$(DEF_COLOR)" 


#criar a diretoria Get_Next_Line__obj e cria os objetos a partir dos ficheiros .c
../get_next_line_obj/%.o:%.c
	@mkdir -p ../get_next_line_obj
	${CC} ${CFLAGS} ${INCLUDE} -c -o $@ $^
	@echo "$(GRAY)\n$@ GNL objects and folder created$(DEF_COLOR)"



# remove os objetos e os objetos do bonus, assim como a pasta que os recebeu.
clean:
	@${RM} ${OBJS} ${OBJS_BONUS}
	@${RM} -r ../get_next_line_obj
	@echo "$(RED)\nGNL Objects and folder deleted$(DEF_COLOR)"



#remove o libft.a
fclean: clean
	${RM} ${NAME} 
	@echo "$(RED)\n${NAME} deleted\n$(DEF_COLOR)"



# primeiro faz o fclean (ou seja, o clean, eliminando os objetos, e dps elimina o libft.a), e a seguir torna a compilar tudo com o all (os objetos e o libft.a)
re: fclean all



#phony faz com que o nome destes comandos não sejam confundidos com ficheiros. ou seja, se houver um ficheiro com esse nome para ser compilado ou atualizado, o compilador ignora.
.PHONY: all clean fclean re



#o silent faz com que as ações ocorram, mas que não apareçam no terminal. Daí o nome silent, pq apesar de ocorreram as ações, elas são silenciosas...não aparecem no terminal.
#.SILENT:

# Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m
