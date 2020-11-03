CC=g++
FLAGS=-std=c++17 -O2
PROGNAME=solution
FILENAME=solution.cpp
CONTEST=practice2
ACLREPO=ac-library
ACLREPOURL=https://github.com/atcoder/$(ACLREPO).git

all: acl
	for problem in `ls $(CONTEST)`; do \
		$(CC) $(FLAGS) -I$(ACLREPO) -o$(CONTEST)/$${problem}/$(PROGNAME) $(CONTEST)/$${problem}/$(FILENAME); \
	done

acl:
	if [ ! -e $(ACLREPO) ]; then \
		git clone $(ACLREPOURL); \
	fi

clean:
	rm -rf $(ACLREPO)
	for problem in `ls $(CONTEST)`; do \
		rm -f $(CONTEST)/$${problem}/$(PROGNAME); \
	done