.DEFAULT_GOAL := all
TOKEN ?= submit
SHELL := /bin/bash

all:
	@if [[ ! -e build/Makefile ]]; then \
		mkdir -p build; \
		cd build && cmake .. -DCMAKE_BUILD_TYPE=Debug; fi
	@make -C build

lib:
	@find source -type f -name "*.cpp" -exec \
		g++ -std=c++17 -O2 -I include -shared -fPIC -o libgraph.so {} +

clean:
	@if [[ -d build ]]; then \
		rm -r build; fi
	@if [[ -e libgraph.so ]]; then \
		rm libgraph.so; fi

run:
	@if [[ ! -e build/Makefile ]]; then \
		mkdir -p build; \
		cd build && cmake ..; fi
	@make -C build
	@./build/Test01

submit:
	$(eval TEMP := $(shell mktemp -d))
	$(eval BASE := $(shell basename $(CURDIR)))
	$(eval FILE := ${TEMP}/${TOKEN}.zip)
	@cd .. && zip -qr ${FILE} ${BASE}/.git
	@echo "Created submission archive ${FILE}"
	@curl -m 5 -w "\n" -X POST -F "TOKEN=${TOKEN}" -F "FILE=@${FILE}" \
		http://114.212.10.47:8085/api/v1/submission/lab
	@rm -r ${TEMP}
