#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>

__global__ void unique_idx_calc_threadIdx(int* input)
{
	int tid = threadIdx.x;

	printf("threadIdx : %d, value : %d \n", tid, input[tid]);
}

__global__ void unique_gid_calc(int* input)
{
	int tid = threadIdx.x;
	int offset = blockIdx.x * blockDim.x;
	int gid = tid + offset;


	printf("blockIdx.x : %d, threadIdx : %d, gid : %d, value : %d \n", blockIdx.x, tid, gid, input[tid]);
}

__global__ void unique_gid_calc_2D(int* input)
{
	int tid = threadIdx.x;
	int block_offset = blockIdx.x * blockDim.x;
	int row_offset = blockDim.x * gridDim.x * blockIdx.y;
	int gid = row_offset + block_offset + tid;


	printf("blockIdx.x : %d, blockIdx.y : %d, threadIdx : %d, gid : %d, value : %d \n"
			, blockIdx.x, blockIdx.y, tid, gid, input[tid]);
}

void UniqueIDXCal()
{
	int array_size = 16;
	int array_byte_size = sizeof(int) * array_size;
	int array_data[] = {11,22,56,9,54,89,12,34,834,67,4,234,53,65,68,35};

	for (int i = 0; i < array_size; i++) {
		printf("%d ", array_data[i]);
	}

	printf("\n \n");

	int* data_ptr;
	cudaMalloc((void**)&data_ptr, array_byte_size);
	cudaMemcpy(data_ptr, array_data, array_byte_size, cudaMemcpyHostToDevice);

	/*dim3 block(4);
	dim3 grid(2,2);
	unique_idx_calc_threadIdx << <grid, block >> > (data_ptr);*/

	/*dim3 block(4);
	dim3 grid(4);
	unique_gid_calc << <grid, block >> > (data_ptr);*/

	dim3 block(4);
	dim3 grid(2, 2);
	unique_gid_calc_2D << <grid, block >> > (data_ptr);
	cudaDeviceSynchronize();
	cudaDeviceReset();
}