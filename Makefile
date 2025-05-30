
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

RM           := trash

target_exec  := test-clog-manual

src_dir      := ./src
build_dir    := ./build
test_dir     := ./test

inc_dirs     := $(src_dir) $(test_dir)

srcs         := $(shell find $(src_dir) -name '*.c')
srcs         += $(shell find $(test_dir) -name '*.c')

objs         := $(srcs:%=$(build_dir)/%.o)
deps         := $(objs:.o=.d)

inc_flags    := $(addprefix -I,$(inc_dirs))

# The -MMD and -MP flags together generate Makefiles for us.
CFLAGS       := $(inc_flags) -MMD -MP -Wall -g


.PHONY: default
default: build


.PHONY: test
test: $(build_dir)/$(target_exec)
	cd $(build_dir) && ./$(target_exec)


.PHONY: build
build: $(build_dir)/$(target_exec)


.PHONY: rebuild
rebuild: clean build


$(build_dir)/$(target_exec): $(objs)
	$(CC) $^ $(LDFLAGS) -o $@ 


$(build_dir)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


.PHONY: clean
clean:
	$(RM) -r $(build_dir)


-include $(deps)


