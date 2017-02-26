EXECS = mpi_comm_test
MPICC =mpicc
OPTS = -O2

MPI_files = mpi_comm_test.c

all: ${EXECS}

mpi_comm_test: ${MPI_files}
	${MPICC} ${OPTS} ${MPI_files} -o $@


clean:
	rm ${EXECS}
