.PHONY: init upload

init:
	-platformio run
	patch -p1 < adhoc12mhz.patch

upload:
	platformio run -t upload
