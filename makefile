CC=clang
FL=-g -Werror -Wall -Wextra -pedantic -o
INC=-Iincludes/
COM=compiled/
SRC=src/

%.o: $(SRC)%.c $(COM)
	$(CC) $< -c $(INC) $(FL) $(COM)$(@F)

$(COM):
	mkdir $(COM)

clean:
	rm -f **/*.e **/*.o
	rm -rf $(COM)
