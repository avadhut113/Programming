#include "OrganizationTheradCUDA.cuh"
#include "UniqueIndexCalculation.cuh"
#include "SumArray.cuh"

__global__ void hello_cuda()
{
    printf("Hello CUDA world\n");
}

void elements_of_CUDA()
{
    int nx = 16, ny = 4;
    dim3 block(8, 2);
    dim3 grid(nx / block.x, ny / block.y);

    hello_cuda << <grid, block >> > ();
}

int main()
{
    //elements_of_CUDA();
    
    //OrganizingCUDAThreads();

    //UniqueIDXCal();

    SumArray();
    return 0;
}