all: libs

libs:
	$(MAKE) -C libc
	$(MAKE) -C mxx
	$(MAKE) -C msl

.PHONY: clean
clean:
	$(MAKE) -C libc clean
	$(MAKE) -C mxx clean
	$(MAKE) -C msl clean
