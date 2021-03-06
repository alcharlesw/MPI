#include <mpi.h>
#include <stdio.h>

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

    /* Get the name of the processor */
    MPI_Get_processor_name(processor_name, &name_len);

    /* Print off a hello world message */
    printf("Hello world from process %s, number %d "
           "out of %d processors.\n",
           processor_name, world_rank, world_size);

	MPI_Finalize();
}
