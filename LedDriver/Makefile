
C_COMPILER=gcc

CFLAGS = -std=c89
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wincompatible-pointer-types-discards-qualifiers
CPPUTEST_WARNINGFLAGS += -Wno-unknown-warning-option
UNITY_ROOT=../Unity
UNITY_FIXTURE_ROOT=$(UNITY_ROOT)/extras/fixture/
TEST_TARGET=LedDriverTest
SRC_FILES=src/LedDriver.c
TEST_SRC_FILES=$(UNITY_ROOT)/src/unity.c \
	$(UNITY_FIXTURE_ROOT)/src/unity_fixture.c \
	test/AllTests.c \
	test/LedDriverTestRunner.c \
	test/LedDriverTest.c \
	mocks/RuntimeErrorStub.c
INC_DIRS=-Iinclude -Imocks -I$(UNITY_ROOT)/src -I$(UNITY_FIXTURE_ROOT)/src 


all: clean default

default: $(SRC_FILES) $(TEST_SRC_FILES)
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SRC_FILES) $(TEST_SRC_FILES) -o $(TEST_TARGET)
	- ./$(TEST_TARGET)

clean:
	rm -rf $(TEST_TARGET)
