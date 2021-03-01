submit:
	$(eval TEMP := $(shell mktemp))
	$(eval BASE := $(shell basename $(CURDIR)))
	@zip $TEMP -b .. -r $BASE/.git
	@curl -X POST -F "TOKEN=${TOKEN}" -F "FILE=@${TEMP}" \
		http://114.212.10.47:8085/api/v1/submission/lab
	@rm -f $TEMP
