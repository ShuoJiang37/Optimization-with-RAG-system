ROOT := $(shell pwd)
SRC_DIR := $(ROOT)/test
P :=

.PHONY: help setup get-dataset extract-dataset verify-dataset get-submissions clean-dataset clean

help:
	@echo "Usage: make <recipe> [-p=number]"
	@echo -e "    get-dataset:\tDownloads the compressed dataset (7.8GB)."
	@echo -e "    extract-dataset:\tExtracts the datatset (~75GB)."
	@echo -e "    verify-dataset:\tVerifies the datatset."
	@echo -e "    clean-dataset:\tDeletes the datatset."

setup:
	@mkdir -p test/
	@chmod +x scripts/*.sh

get-dataset:
	wget https://codait-cos-dax.s3.us.cloud-object-storage.appdomain.cloud/dax-project-codenet/1.0.0/Project_CodeNet.tar.gz

extract-dataset:
	gzip -t Project_CodeNet.tar.gz && tar -zxf Project_CodeNet.tar.gz

verify-dataset: setup
	./scripts/dataset_verify.sh -d=$(ROOT)/Project_CodeNet

# ./scripts/project_codenet_submissions.sh -d=Project_CodeNet -s p02272 > src/p02272.txt
get-submissions: setup
ifndef P
	$(error "Usage: make <cmd> P=<num>")
endif
	./scripts/project_codenet_submissions.sh -d=$(ROOT)/Project_CodeNet p$(P) > $(SRC_DIR)/p$(P).txt

benchmark:
	./scripts/benchmark.sh test

clean-dataset:
	rm -rf Project_CodeNet Project_CodeNet.tar.gz

clean:
	rm -rf test/* out/ inputs/ 
