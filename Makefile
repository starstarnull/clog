
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

RM           := trash

TARGET_EXEC  := clog-test

BUILD_DIR    := ./build
TEST_DIR     := ./test

SRC_DIRS     := ./src
INC_DIRS     := $(shell find $(SRC_DIRS) -type d)

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c' -or -name '*.s')
SRCS += $(shell find $(TEST_DIR) -name '*.cpp' -or -name '*.c' -or -name '*.s')

OBJS         := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS         := $(OBJS:.o=.d)

INC_FLAGS    := $(addprefix -I,$(INC_DIRS))

# The -MMD and -MP flags together generate Makefiles for us!
CPPFLAGS     := $(INC_FLAGS) -MMD -MP -Wall -g


.PHONY: default
default: run


.PHONY: run
run: $(BUILD_DIR)/$(TARGET_EXEC)
	cd $(BUILD_DIR) && ./$(TARGET_EXEC)


.PHONY: build
build: $(BUILD_DIR)/$(TARGET_EXEC)


.PHONY: rebuild
rebuild: clean build


$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)


$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@


$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@


.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)


-include $(DEPS)


