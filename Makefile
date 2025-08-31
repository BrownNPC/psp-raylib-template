BUILD_PRX = 1
TARGET = raylib
OBJS = main.o
INCDIR =
CFLAGS = -Wall
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

LIBDIR =
LDFLAGS =
LIBS=   -lraylib -lpng -lz  -lglut -lGLU -lGL -lpspvfpu 

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = raylib textures bunnymark
PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak


# --- Move build artifacts into a build/ directory ---
BUILD_DIR := build

.PHONY: postbuild install

# run postbuild automatically after the SDK's all target
all: postbuild

postbuild: $(BUILD_DIR)
	@for f in *.o *.prx *.elf; do \
	  if [ -f "$$f" ]; then \
	    echo "  mv $$f -> $(BUILD_DIR)/"; \
	    mv -f "$$f" "$(BUILD_DIR)/"; \
	  fi; \
	done
	@echo "Done."

$(BUILD_DIR):
	@mkdir -p "$(BUILD_DIR)"
