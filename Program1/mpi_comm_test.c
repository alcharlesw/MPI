#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    /* Initialize the MPI environment */
	MPI_Init(NULL, NULL);

    int world_size;
    int world_rank;

    char processor_name[MPI_MAX_PROCESSOR_NAME];
    int name_len;

	/* Get the number of processes */
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    /* Get the rank of the process */
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

	int number;
    if (world_rank == 1)
	{
		number = (int) (10.0 * rand() / RAND_MAX);
		MPI_Send(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
	} else if (world_rank == 0) {
        MPI_Status status;
		MPI_Recv(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);

		printf("Master received number %d from node 1.\n", number);
    }

	MPI_Finalize();
}
