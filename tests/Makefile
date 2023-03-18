CXX = g++
CC = $(CXX)

CPPFLAGS = -MMD -MP
CPPFLAGS += -I $(INC_DIR) -I $(SRC_DIR) -I $(TCPI_DIR) -I $(TCPS_DIR)

# c++ language
CXXFLAGS = -std=c++17
CXXFLAGS+= -Wall -pedantic
CXXFLAGS+= -Werror
CXXFLAGS+= -g3


INC_DIR = ../../inc/messenger
SRC_DIR = ../../src/messenger
TCPI_DIR = ../../inc
TCPS_DIR = ../../src

TARGET = utest
OBJS = utest.o $(SRC_DIR)/messenger_manager.o $(SRC_DIR)/messenger.o $(SRC_DIR)/messenger_encrypt.o $(SRC_DIR)/messenger_factory.o $(SRC_DIR)/messenger_sources.o $(SRC_DIR)/messenger_destinations.o $(SRC_DIR)/messenger_config.o $(SRC_DIR)/command_parser.o $(TCPS_DIR)/tcp_client.o $(TCPS_DIR)/tcp_simple_protocol.o


all: $(TARGET)

check: $(TARGET)
	./$(TARGET) -v

$(TARGET): $(OBJS)


clean:
	@$(RM) $(TARGET) $(OBJS) $(DEPENDS)

.PHONY: all check clean


DEPENDS = $(OBJS:%.o=%.d)

-include $(DEPENDS)

