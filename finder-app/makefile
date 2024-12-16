CC := gcc
TARGET := writer
CROSS_COMPILE ?= 
CROSS_CC := $(CROSS_COMPILE)gcc

.PHONY: all clean

all: $(TARGET)

$(TARGET): writer.c
	$(CROSS_CC) -o $@ $<

clean:
	rm -f $(TARGET) *.o