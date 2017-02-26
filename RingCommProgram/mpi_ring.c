#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
    MPI_Init(&argc, &argv);

    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    MPI_Status status;

    int core_counter;
    if (world_rank == 0)
    {
        int world_size;

        MPI_Comm_size(MPI_COMM_WORLD, &world_size);

        core_counter = 1;
        MPI_Send(&core_counter, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(&core_counter, 1, MPI_INT, world_size - 1, 0, MPI_COMM_WORLD, &status);

        printf("Counted %d cores of %d.\n", core_counter, world_size);
    } else {
        int world_size;

        MPI_Comm_size(MPI_COMM_WORLD, &world_size);

        MPI_Recv(&core_counter, 1, MPI_INT, world_rank - 1, 0, MPI_COMM_WORLD, &status);
        ++core_counter;
        MPI_Send(&core_counter, 1, MPI_INT, (world_rank + 1) % world_size, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
