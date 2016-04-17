CC:=clang
FL:=-g -Werror -Wall -Wextra -pedantic
INC:=-Iincludes/
COM:=compiled/
SRC:=src/

Systems1415Q2.e_dep:=bitBuffer.o arrays.o

override CFLAGS += $(INC) $(FL)

vpath %.c $(SRC)
vpath %.h $(INC)

.SECONDEXPANSION:

.PRECIOUS: $(COM)%.o
$(COM)%.o: %.c %.h | $(COM)
	$(COMPILE.c) $(OUTPUT_OPTION) $<

%.e: %.c $$(addprefix $$(COM), $$($$@_dep))
	$(LINK.c) $^ $(OUTPUT_OPTION)

.PRECIOUS: %/
%/:
	mkdir -p $@

.PHONY: clean
clean:
	$(RM) *.e
	$(RM) -r $(COM)
