CXX=g++
RM=rm
RM_FLAGS := -f

BUILD_DIR ?= ./build

TARGET ?= nnet.out
SRC_DIRS ?= ./src ./examples

TEST_TARGET ?= test.out
TEST_DIRS ?= ./tests

MKDIR_P ?= mkdir -p

MAIN_SRC := ./src/main.cpp
SRCS := $(shell find $(SRC_DIRS) \( -name "*.cpp" -or -name "*.c" -or -name "*.s" \) -and ! -name "main.cpp")
TEST_SRCS := $(shell find $(TEST_DIRS) -name *.cpp -or -name *.c -or -name *.s)

MAIN_OBJ := $(BUILD_DIR)/main.o
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
TEST_OBJS := $(TEST_SRCS:%=$(BUILD_DIR)/%.o)

DEPS := $(OBJS:.o=.d)
TEST_DEPS := $(TEST_OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP

TEST_FLAGS := -lgtest -lgtest_main -lpthread

$(BUILD_DIR)/$(TARGET): $(OBJS) $(MAIN_OBJ)
	$(CXX) $(OBJS) $(MAIN_OBJ) -o $@ $(LDFLAGS)

$(BUILD_DIR)/$(TEST_TARGET): $(OBJS) $(TEST_OBJS)
	$(CXX) $(OBJS) $(TEST_OBJS) $(TEST_FLAGS) -o $@ $(LDFLAGS)

# assembly
$(BUILD_DIR)/%.s.o: %.s
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) -c $< -o $@

# c++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

# main
$(MAIN_OBJ): $(MAIN_SRC)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(MAIN_SRC) -o $(MAIN_OBJ)

# Execution
test: $(BUILD_DIR)/$(TEST_TARGET)
	$(BUILD_DIR)/$(TEST_TARGET)

run: $(BUILD_DIR)/$(TARGET)
	$(BUILD_DIR)/$(TARGET)

.PHONY: clean
clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPS)
