Q ?= @

DEBUG	=	-O3
CC		=	gcc
INCLUDE =	-I/usr/local/include
CFLAGS	=	$(DEBUG) -Wall $(INCLUDE) -Winline -pipe

LDFLAGS	=	-L/usr/local/lib
LDLIBS	=	-lwiringPi -lwiringPiDev  -lpthread -lm -lcrypt -lrt 

SRC		=	initialize_LCD.c blink.c blink_lcd.c lcd.c blink2.c led.c
OBJ		=	$(SRC:.c=.o)
BINS	=   $(SRC:.c=)

rm:
	rm blink initialize_LCD
led:	led.o
		$Q $(CC) -o $@ led.o $(LDFLAGS) $(LDLIBS)
		sudo ./led

blink:	blink.o
		$Q $(CC) -o $@ blink.o $(LDFLAGS) $(LDLIBS)
		sudo ./blink

blink2:	blink2.o
		$Q $(CC) -o $@ blink2.o $(LDFLAGS) $(LDLIBS)
		sudo ./blink2

initialize_LCD:	initialize_LCD.o
		$Q $(CC) -o $@ initialize_LCD.o $(LDFLAGS) $(LDLIBS)
		sudo ./initialize_LCD

lcd:	lcd.o
		$Q $(CC) -o $@ blink2.o $(LDFLAGS) $(LDLIBS)
		sudo ./lcd 16 2 4

blink_lcd:	blink_lcd.o
		$Q $(CC) -o $@ blink2.o $(LDFLAGS) $(LDLIBS)
		sudo ./blink_lcd
