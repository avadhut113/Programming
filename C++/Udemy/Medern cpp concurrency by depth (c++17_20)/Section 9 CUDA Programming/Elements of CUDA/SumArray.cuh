#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


__global__ void sum_array_gpu(int* array1, int* array2, int* res, int size)
{
	int gid = blockIdx.x * blockDim.x + threadIdx.x;

	if (gid < size) {
		res[gid] = array1[gid] + array2[gid];
	}
}

void sum_array_cpu(int* array1, int* array2, int* res, int size)
{
	for (int i = 0; i < size; i++) {
		res[i] = array1[i] + array2[i];
	}
}

void compare_arrays(int* array1, int* array2, int size)
{
	for (int i = 0; i < size; i++) {
		if (array1[i] != array2[i]) {
			printf("arraysare diffrent\n");
			return;
		}
	}
	printf("arrays are same\n");
}

void SumArray()
{
	int size = 1000;
	int block_size = 128;
	int no_bytes = size * sizeof(int);

	//host ptr
	int* h_a, * h_b, * gpu_res, * cpu_res;
	h_a = (int*)malloc(no_bytes);
	h_b = (int*)malloc(no_bytes);
	gpu_res = (int*)malloc(no_bytes);
	cpu_res = (int*)malloc(no_bytes);

	//initialize host pointer
	time_t t;
	srand((unsigned)time(&t));
	for (int i = 0; i < size; i++) {
		h_a[i] = (int)(rand() & 0xFF);
	}

	for (int i = 0; i < size; i++) {
		h_b[i] = (int)(rand() & 0xFF);
	}

	sum_array_cpu(h_a, h_b, cpu_res, size);

	//device pointer
	int* d_a, * d_b, * d_res;
	cudaMalloc((int**)&d_a, no_bytes);
	cudaMalloc((int**)&d_b, no_bytes);
	cudaMalloc((int**)&d_res, no_bytes);

	cudaMemcpy(d_a, h_a, no_bytes, cudaMemcpyHostToDevice);
	cudaMemcpy(d_b, h_b, no_bytes, cudaMemcpyHostToDevice);

	//launch the grid
	dim3 block(block_size);
	dim3 grid((size / block.x) + 1);

	sum_array_gpu << <grid, block >> > (d_a, d_b, d_res, size);
	cudaDeviceSynchronize();

	cudaMemcpy(gpu_res, d_res, no_bytes, cudaMemcpyDeviceToHost);

	//array comparison
	compare_arrays(gpu_res, cpu_res, size);

	cudaFree(d_a);
	cudaFree(d_b);
	cudaFree(d_res);

	free(h_a);
	free(h_b);
	free(gpu_res);

}