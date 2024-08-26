CC=gcc
CFLAGS=-Wall -Werror -fPIC
LDFLAGS=-shared

SOURCES=pam_nuclear.c
OBJECTS=pam_nuclear.o
TARGET=pam_nuclear.so

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^

$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

install:
	install -m 755 pam_nuclear.so /usr/lib/security/pam_nuclear.so
