ROOT := $(shell pwd)
SCRIPTS := scripts
DATASET := dataset
INPUT := inputs
DATA := data/csv
TEST := test
P :=

.PHONY: help scripts \
	submissions benchmark \
	extract-dataset copy-dataset \
	get-codenet extract-codenet verify-codenet \
	clean-codenet clean-dataset clean \
	zip tmux attach detach

help:
	@echo "Usage: make <recipe> [-p=number]"
	@echo -e "    submissions:\t\tGets submissions in for benchmark script."
	@echo -e "    benchmark:\t\t\tExecutes the benchmark script."
	@echo -e "    inputs:\t\t\tCreate inputs for submissions."
	@echo -e "    clean:\t\t\tDeletes benchmark files."
	@echo ""
	@echo -e "    get-codenet:\t\tDownloads the compressed CodeNet dataset (7.8GB)."
	@echo -e "    extract-codenet:\t\tExtracts the CodeNet datatset (~75GB)."
	@echo -e "    verify-codenet:\t\tVerifies the CodeNet datatset."
	@echo -e "    clean-codenet:\t\tDeletes the CodeNet dataset."
	@echo ""
	@echo -e "    extract-dataset:\t\tExtracts submissions from CodeNet dataset."
	@echo -e "    copy-dataset:\t\tCopies the CodeNet submissions into the local dataset."
	@echo -e "    clean-dataset:\t\tDeletes the local dataset."

scripts:
	@chmod +x $(SCRIPTS)/*.sh

# Benchmarking recipies

submissions: scripts
	./$(SCRIPTS)/get_submissions.sh $(DATASET) $(TEST) p$(P)

benchmark:
	./$(SCRIPTS)/benchmark.sh -d $(DATA) -i $(INPUT) -t $(TEST) -x $(FLAGS)

inputs: scripts
	./$(SCRIPTS)/generate_inputs.sh -d $(INPUT) -f $(FLAGS)

# Project_CodeNet dataset recipies

get-codenet:
	wget https://codait-cos-dax.s3.us.cloud-object-storage.appdomain.cloud/dax-project-codenet/1.0.0/Project_CodeNet.tar.gz

extract-codenet:
	gzip -t Project_CodeNet.tar.gz && tar -zxf Project_CodeNet.tar.gz

verify-codenet: scripts
	./$(SCRIPTS)/dataset_verify.sh -d=$(ROOT)/Project_CodeNet

# Local dataset recipies

extract-dataset: scripts
ifndef P
	$(error "Usage: make <cmd> P=<num>")
endif
	@mkdir -p $(TEST)
	./$(SCRIPTS)/project_codenet_submissions.sh -d=$(ROOT)/Project_CodeNet p$(P) > $(TEST)/p$(P).txt

copy-dataset: scripts
	./$(SCRIPTS)/copy_submissions.sh

# Clean recipies

clean:
	rm -rf test/ out/ inputs/ data/csv/ benchmark_out.txt

clean-data:
	rm -rf data/csv

clean-codenet:
	@echo "Confirm: remove Project_CodeNet dataset (~75 GB)?"
	@rm -rI Project_CodeNet/ Project_CodeNet.tar.gz

clean-dataset:
	@echo "Confirm: remove local dataset?"
	@rm -rI dataset/

# Python Environment

venv:
	@python -m venv .venv

# Other utilities

zip:
	@echo "Not done yet lol"

tmux:
	@tmux new -s RAG

attach:
	@tmux attach -t RAG

detach:
	@tmux detach
