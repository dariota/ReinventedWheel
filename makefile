CC=clang
FL=-g -Werror -Wall -Wextra -pedantic -o
INC=-Iincludes/
COM=compiled/
SRC=src/

Systems1415Q2.e: bitBuffer.o arrays.o

%.o: */%.c | $(COM)
	$(CC) $< -c $(INC) $(FL) $(COM)$(@F)

%.e: */%.c
	$(CC) $(firstword $^) $(addprefix $(COM), $(wordlist 2, $(words $^), $^)) $(INC) $(FL) $@

.PRECIOUS: %/
%/:
	mkdir $@

clean:
	rm -f *.e **/*.o
	rm -rf $(COM)
