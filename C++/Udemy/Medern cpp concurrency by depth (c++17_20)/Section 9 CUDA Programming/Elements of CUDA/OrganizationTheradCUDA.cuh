#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>

__global__ void print_threadIDs()
{
	printf("threadIdx.x = %d, threadIdx.y = %d, threadIdx.z = %d \n", threadIdx.x, threadIdx.y, threadIdx.z);
}

__global__ void print_blockIDs()
{
	printf("blockIdx.x = %d, blockIdx.y = %d, blockIdx.z = %d \n", blockIdx.x, blockIdx.y, blockIdx.z);
}

__global__ void print_gridDim()
{
	printf("gridDim.x = %d, gridDim.y = %d, gridDim.z = %d \n", gridDim.x, gridDim.y, gridDim.z);
}

__global__ void print_blockDim()
{
	printf("blockDim.x = %d, blockDim.y = %d, blockDim.z = %d \n", blockDim.x, blockDim.y, blockDim.z);
}

void OrganizingCUDAThreads()
{
	int nx = 16, ny = 16;

	dim3 block(8, 8);
	dim3 grid(nx / block.x, ny / block.y);

	//print_threadIDs << <grid, block >> > ();

	print_blockIDs << <grid, block >> > ();
	print_blockDim << <grid, block >> > ();
	print_gridDim << <grid, block >> > ();

	cudaDeviceSynchronize();
	cudaDeviceReset();
}