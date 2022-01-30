# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/30 18:46:06 by jodufour          #+#    #+#              #
#    Updated: 2022/01/30 19:54:49 by jodufour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

######################################
#              COMMANDS              #
######################################
CXX				=	c++ -c
LINK			=	c++
MKDIR			=	mkdir -p
RM				=	rm -rf

######################################
#             EXECUTABLE             #
######################################
NAME			=	ex00.out

#######################################
#             DIRECTORIES             #
#######################################
SRC_DIR			=	srcs/
OBJ_DIR			=	objs/
PRV_DIR			=	private/

######################################
#            SOURCE FILES            #
######################################
SRC				=	\
					${addprefix class/,	\
						Bureaucrat.cpp	\
					}					\
					main.cpp

######################################
#            OBJECT FILES            #
######################################
OBJ				=	${SRC:.cpp=.o}
OBJ				:=	${addprefix ${OBJ_DIR}, ${OBJ}}

DEP				=	${OBJ:.o=.d}

#######################################
#                FLAGS                #
#######################################
CPPFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS		+=	-std=c++98
CPPFLAGS		+=	-MMD -MP
CPPFLAGS		+=	-I${PRV_DIR}

LDFLAGS			=	

ifeq (${DEBUG}, 1)
	CPPFLAGS	+=	-g
endif

#######################################
#                RULES                #
#######################################
${NAME}: ${OBJ}
	${LINK} ${OBJ} ${LDFLAGS} ${OUTPUT_OPTION}

all: ${NAME}

-include ${DEP}

${OBJ_DIR}%.o: ${SRC_DIR}%.cpp
	@${MKDIR} ${@D}
	${CXX} ${CPPFLAGS} $< ${OUTPUT_OPTION}

clean:
	${RM} ${OBJ_DIR} ${NAME} vgcore.*

fclean:
	${RM} ${OBJ_DIR} ${NAME} vgcore.*

re: clean all

fre: fclean all

.PHONY:	all clean fclean re fre
