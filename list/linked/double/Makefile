D ?= 0
CFLAGS += -DD=$(D)
TARGET := Main
IN := in0

$(TARGET): FORCE
	g++ $(CFLAGS) -o $@ $(TARGET).cpp
	./$(TARGET) < $(IN) 2>&1 | tee $(TARGET).txt

.PHONY: FORCE

clean:
	find ! -name Makefile | xargs rm -rf
