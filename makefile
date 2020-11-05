# Chess Engine Makefile
# Author: Jackson WIlliams
# 5-Nov-2020

TARGET	= chess-engine

CC		= gcc
CFLAGS	= -oFast -Wall -Wextra -Wsign-conversion -Wpointer-arith -Wcast-qual -Wwrite-strings -Wshadow -Wmissing-prototypes -Wpedantic -Wwrite-strings -g -std=gnu99 -lm

SRCDIR	= src/
INCDIR	= include/
BINDIR	= .

SRC := $(wildcard $(SRCDIR)/*.c)
INC := $(wildcard $(INCDIR)/*.c)

INCFLAGS := $(patsubst %/,-I%,$(dir $(wildcard $(INCDIR)/.)))

.PHONY: all
all:
	@$(MAKE) release

.PHONY: run
run:
	@$(MAKE) clean
	@$(MAKE) release
	@$(BINDIR)/$(TARGET)

.PHONY: release
release: $(BINDIR)/$(TARGET)

.PHONY: clean
clean:
	@rm -f $(BINDIR)/$(TARGET)

$(BINDIR)/$(TARGET): $(SRC) $(INC)
	@mkdir -p $(BINDIR)
	@$(CC) $(CFLAGS) $(INCFLAGS) $(SRC) -o $@
