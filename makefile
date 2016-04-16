CC=clang
FL=-g -Werror -Wall -Wextra -pedantic -o
INC=-Iincludes/

%.o: %.c $(COM)
	$(CC) $< -c $(INC) $(FL) $@

clean:
	rm -f **/*.e **/*.o
