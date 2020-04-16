CC = gcc
CFLAGS = -W -Wall
TARGET = market
OBJECTS = 21500080_main.c 21500080_manager.o 21500080_product.o
DTARGET = market_debug

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(DTARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -DDEBUG -o $@ $^

clean :
	rm *.o $(TARGET) $(DTARGET)
