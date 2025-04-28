
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
# @copyright    Copyright (c) <year>. All rights reserved.
#
# Standards:    Capital variables are standard makefile variables.
#
###############################################################################

RM = trash
app = build/clog-test
src_dir := src
build_dir := build

.PHONY: run
run: $(app)
	./$(app)

$(app): test/clog-manual-test.c
	$(CC) $(CFLAGS) $^ -I $(src_dir) -o $@



