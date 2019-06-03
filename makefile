

all: Miglior_sequenza test_coverage


test_coverage:
	g++ --std=c++11 -O0 Miglior_sequenza.cpp -o Miglior_sequenza
	./Miglior_sequenza
	if [ -z "$TRAVIS_JOB_ID" ]; then
    		export COVERALLS_REPO_TOKEN="fake testing token"
	fi

	coveralls --verbose --encodings utf-8

Miglior_sequenza:	Miglior_sequenza.cpp
	g++ --std=c++11 -O3 Miglior_sequenza.cpp -o Miglior_sequenza 

clean:
	rm -f Miglior_sequenza

