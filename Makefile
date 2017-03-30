OUTPUT=desafio_if

CC=gcc
CC_OPT=

CC_OMP=-fopenmp
CC_PTH=-pthread

.PHONY: all
all: $(OUTPUT)_omp $(OUTPUT)_pthreads

$(OUTPUT)_omp: $(OUTPUT)_omp.c
	$(CC) -o $(OUTPUT)_omp $(CC_OPT) $(CC_OMP) $(OUTPUT)_omp.c

$(OUTPUT)_pthreads: $(OUTPUT)_pthreads.c
	$(CC) -o $(OUTPUT)_pthreads $(CC_OPT) $(CC_PTH) $(OUTPUT)_pthreads.c

.PHONY: clean
clean:
	rm $(OUTPUT)_omp $(OUTPUT)_pthreads
