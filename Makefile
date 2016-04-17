CC:=clang
FL:=-g -Werror -Wall -Wextra -pedantic -o
INC:=-Iincludes/
COM:=compiled/
SRC:=src/

Systems1415Q2.e: $(addprefix $(COM), bitBuffer.o arrays.o)

$(COM)%.o: */%.c | $(COM)
	$(CC) $< -c $(INC) $(FL) $(COM)$(@F)

%.e: */%.c
	$(CC) $(firstword $^) $(wordlist 2, $(words $^), $^) $(INC) $(FL) $@

.PRECIOUS: %/
%/:
	mkdir -p $@

.PHONY: clean
clean:
	$(RM) *.e
	$(RM) -r $(COM)
