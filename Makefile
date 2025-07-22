APP_NAME = Wiiverse
SOURCE_FILES = source/main.c source/graphics.c
DATA_FILES = data/background.png data/exit_icon.png

DEVKITPPC = /path/to/devkitPPC
LIBOGC = $(DEVKITPPC)

CFLAGS = -Wall -O2
LDFLAGS = -lgrrlib -lfreetype -lpngu -lpng -lz -lwiiuse -lbte -logc -lm

include $(DEVKITPPC)/wii_rules

all: $(APP_NAME).elf $(APP_NAME).dol

$(APP_NAME).elf: $(SOURCE_FILES)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

$(APP_NAME).dol: $(APP_NAME).elf
	elf2dol $< $@

clean:
	rm -f *.elf *.dol
