SUBDIRS = src
dist_doc_DATA = README

dependencies:
	sudo apt update -y
	sudo apt install -y libsdl2-dev libsdl2-image-dev

clean-local:
	@rm config.status configure config.log
	@rm Makefile Makefile.in
	@rm -r autom4te.cache/
	@rm aclocal.m4
	@rm -r configs
	@rm stamp-h1 config.h config.h.in
