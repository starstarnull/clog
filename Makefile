
###############################################################################
#
# This makefile builds the <program> application.
#
# @file         Makefile
# @author       <author>
# @brief        Builds <program> application.
# @version      <0.0.0-0>
# @date         <date>
#
# @copyright    Copyright (c) 2025. All rights reserved.
#
# Standards:    Capital variables are standard makefile variables.
#
###############################################################################

PREFIX       ?= /usr/local
INCLUDEDIR   = $(PREFIX)/include
RM           := trash

target_exec  := test-main

src_dir      := ./src
build_dir    := ./build
test_dir     := ./test

headers_src  := src/clog.h src/clog-colors.h
headers      := clog.h clog-colors.h

inc_dirs     := $(src_dir) $(test_dir)

srcs         := $(shell find $(src_dir) -name '*.c')
srcs         += $(shell find $(test_dir) -name '*.c')

objs         := $(srcs:%=$(build_dir)/%.o)
deps         := $(objs:.o=.d)

inc_flags    := $(addprefix -I,$(inc_dirs))

# The -MMD and -MP flags together generate Makefiles for us.
CFLAGS       := $(inc_flags) -MMD -MP -Wall -g


.PHONY: default
default: test


install:
	@echo "Installing library headers clog.h and clog-colors.h..."
	install -d $(INCLUDEDIR)
	install -m 644 src/clog.h $(INCLUDEDIR)/
	install -m 644 src/clog-colors.h $(INCLUDEDIR)/


uninstall:
	@echo "Uninstalling library headers..."
	$(RM) -f $(INCLUDEDIR)/$(headers)


.PHONY: test
test: $(build_dir)/$(target_exec)
	cd $(build_dir) && ./$(target_exec)


.PHONY: build
build: $(build_dir)/$(target_exec)


.PHONY: rebuild
rebuild: clean build


$(build_dir)/$(target_exec): $(objs)
	@echo "Building test and demo..."
	$(CC) $^ $(LDFLAGS) -o $@ 


$(build_dir)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY: clean
clean:
	@echo "Cleaning up..."
	$(RM) -r $(build_dir)


-include $(deps)


