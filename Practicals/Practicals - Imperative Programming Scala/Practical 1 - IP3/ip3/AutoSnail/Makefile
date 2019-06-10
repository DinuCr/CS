SOURCE := $(wildcard src/*.scala)

all: .compiled

.compiled: $(SOURCE)
	@mkdir -p bin
	scalac -d bin $^
	cp mapinfo.txt erewhon.txt bin
	touch $@


clean: force
	rm -rf .compiled bin 

force:
