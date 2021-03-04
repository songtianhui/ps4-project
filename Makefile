.default = all
TOKEN ?= submit
SHELL := /bin/bash

all:
	@if [[ ! -d build ]]; then \
		mkdir -p build; \
		cd build && cmake ..; fi
	@make -C build

clean:
	@if [[ -d build ]]; then \
		rm -r build; fi

submit:
	$(eval TEMP := $(shell mktemp -d))
	$(eval BASE := $(shell basename $(CURDIR)))
	@cd .. && zip -qr ${TEMP}/${TOKEN}.zip ${BASE}/.git
	@echo "Created submission archive ${TEMP}/${TOKEN}.zip"
	@curl -m 5 -X POST -F "TOKEN=${TOKEN}" -F "FILE=@${TEMP}" \
		http://114.212.10.47:8085/api/v1/submission/lab
	@rm -r ${TEMP}
