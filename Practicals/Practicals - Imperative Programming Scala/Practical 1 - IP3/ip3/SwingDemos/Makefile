SOURCE := $(wildcard src/*.scala)

all: .compiled

.compiled: $(SOURCE)
	@mkdir -p bin
	scalac -d bin $^
	touch $@


clean: force
	rm -rf .compiled bin 

force:
