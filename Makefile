
###############################################################################
#
# This makefile builds the tests and demo for clog library.
#
# @file         Makefile
# @author       Dorian N. Nihil
# @brief        Builds tests and demos for clog library.
# @version      1.0.1
# @date         2025-06-15
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
target_demo  := demo-main

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
CFLAGS       := -MMD -MP -Wall -g


# Demo

demo_dir     := ./demo
demo_srcs    := $(shell find $(demo_dir) -name '*.c')
demo_objs    := $(demo_srcs:%=$(build_dir)/%.o)
demo_inc_dirs  := $(src_dir) $(demo_dir)
demo_inc_flags := $(addprefix -I,$(demo_inc_dirs))


.PHONY: default
default: demo


install:
	@echo "Installing library headers clog.h and clog-colors.h..."
	install -d $(INCLUDEDIR)
	install -m 644 src/clog.h $(INCLUDEDIR)/
	install -m 644 src/clog-colors.h $(INCLUDEDIR)/


uninstall:
	@echo "Uninstalling library headers..."
	$(RM) -f $(INCLUDEDIR)/clog.h
	$(RM) -f $(INCLUDEDIR)/clog-colors.h


.PHONY: demo
demo: $(build_dir)/$(target_demo)
	cd $(build_dir) && ./$(target_demo)


$(build_dir)/$(target_demo): $(demo_srcs)
	@echo "Building demo..."
	mkdir -p $(dir $@)
	$(CC) -w $(demo_inc_flags) $^ -o $@


.PHONY: test
test: $(build_dir)/$(target_exec)
	cd $(build_dir) && ./$(target_exec)


.PHONY: build
build: $(build_dir)/$(target_exec)


.PHONY: rebuild
rebuild: clean build


$(build_dir)/$(target_exec): $(objs)
	@echo "Building test..."
	$(CC) $^ $(LDFLAGS) -o $@ 


$(build_dir)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(inc_flags) -c $< -o $@


.PHONY: clean
clean:
	@echo "Cleaning up..."
	$(RM) -r $(build_dir)


-include $(deps)


