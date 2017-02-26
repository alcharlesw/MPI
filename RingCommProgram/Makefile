EXECS = mpi_ring
MPICC = mpicc
OPTS = -O2

MPI_files = mpi_ring.c

all: ${EXECS}

mpi_ring: ${MPI_files}
	${MPICC} ${OPTS} ${MPI_files} -o $@

clean:
	rm ${EXECS}
