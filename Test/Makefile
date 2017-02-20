EXECS = mpi_hello_world
MPICC?=mpicc
OPTS = -O2

MPI_files = mpi_hello_world.c

all: ${EXECS}

mpi_hello_world: ${MPI_files}
	${MPICC} ${OPT} ${MPI_files} -o $@


clean:
	rm ${EXECS}
