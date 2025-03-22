#pragma once

#include <vector>
#include <thread>

template<class T>
class Matrix1D
{
    T* m_data;
    int m_row;
    int m_column;

public:

    Matrix1D(int row, int col) :m_row(row), m_column(col) {
        m_data = new T[m_row * m_column];
    }

    void set_val(int i, int j, int val) {
        m_data[i * m_column + j] = val;
    }

    void set_all(int value) {
        std::fill(m_data, m_data + m_row * m_column, value);
    }

    void set_all_rand() {
        for (int i = 0; i < m_row; i++) {
            for (int j = 0; j < m_column; j++) {
                m_data[i + j] = std::rand() % 10;
            }
        }
    }

    static void sequential_multiply(Matrix1D* x, Matrix1D* y, Matrix1D* res) {

        if (!(x->m_column == y->m_row) || !((x->m_row == res->m_row) && (y->m_column == res->m_column))) {
            std::cout << "Incorrect diamenssions of Matrix1D" << std::endl;
        }

        int r = res->m_row * res->m_column;
        for (int i = 0; i < r; i++) {
            int ele{ 0 };
            for (int j = 0; j < x->m_column; j++) {

                int a1 = (i / res->m_column) * x->m_column + j;
                int b1 = i % res->m_row + (j * y->m_column);

                int a = x->m_data[a1];
                int b = y->m_data[b1];
                int cur = a * b;
                ele += cur;
            }
            res->m_data[i] = ele;
        }
    }

    static void parallel_multiply(Matrix1D* x, Matrix1D* y, Matrix1D* res) {

        if (!(x->m_column == y->m_row) || !((x->m_row == res->m_row) && (y->m_column == res->m_column))) {
            std::cout << "Incorrect diamenssions of Matrix2D" << std::endl;
        }

        struct data_chunk {
            void operator()(Matrix1D* x, Matrix1D* y, Matrix1D* res, int start, int end) {

                int r = res->m_row * res->m_column;
                for (int i = 0; i < r; i++) {
                    int ele{ 0 };
                    for (int j = 0; j < x->m_column; j++) {

                        int a1 = (i / res->m_column) * x->m_column + j;
                        int b1 = i % res->m_row + (j * y->m_column);

                        int a = x->m_data[a1];
                        int b = y->m_data[b1];
                        int cur = a * b;
                        ele += cur;
                    }
                    res->m_data[i] = ele;
                }
            }
        };

        int len = res->m_row * res->m_column;

        if (!len)
            return;

        int min_pre_thread = 10000;

        int max_threads = (len + min_pre_thread - 1) / min_pre_thread;

        int hardware_threads = std::thread::hardware_concurrency();
        int num_threads = std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);
        int block_size = len / num_threads;

        std::vector<std::thread> threads(num_threads - 1);
        int block_start = 0;
        int block_end = 0;

        for (unsigned int i = 0; i < (num_threads - 1); i++) {
            block_start = i * block_size;
            block_end = block_start + block_size;

            threads[i] = std::thread(data_chunk(), x, y, res, block_start, block_end);
        }

        data_chunk()(x, y, res, block_end, len);

        //for (const auto& curr_thread : threads)
        //{
        //    if(curr_thread.joinable())
        //        curr_thread.join();
        //}

        for (unsigned int i = 0; i < threads.size(); ++i)
        {
            //if (i.joinable())
            threads.at(i).join();
        }

    }

    static void Sequential_transpose(Matrix1D* x, Matrix1D* res)
    {
        if ((x->m_row != res->m_column) && (x->m_column != res->m_row)) {
            std::cout << "InvalidDoamenssions" << std::endl;
        }

        int result_row = 0, result_column = 0;
        int input_row = 0, input_column = 0;

        int r = res->m_row * res->m_column;

        for (size_t i = 0; i < r; i++) {

            result_row = i / res->m_column;
            result_column = i % res->m_column;

            input_row = result_column;
            input_column = result_row;

            int x_index = input_row * x->m_column + input_column;

            int val = x->m_data[x_index];

            res->m_data[i] = val;
        }
    }

    static void Parallel_transpose(Matrix1D* x, Matrix1D* res)
    {

        if ((x->m_row != res->m_column) && (x->m_column != res->m_row)) {
            std::cout << "InvalidDoamenssions" << std::endl;
        }

        struct data_chunk {
            void operator()(Matrix1D* x, Matrix1D* res, int start, int end) {

                int result_row = 0, result_column = 0;
                int input_row = 0, input_column = 0;

                int r = res->m_row * res->m_column;

                for (size_t i = 0; i < r; i++) {

                    result_row = i / res->m_column;
                    result_column = i % res->m_column;

                    input_row = result_column;
                    input_column = result_row;

                    res->m_data[i] = x->m_data[input_row * x->m_column + input_column];
                }
            }
        };

        int len = res->m_row * res->m_column;

        if (!len)
            return;

        int min_pre_thread = 10000;

        int max_threads = (len + min_pre_thread - 1) / min_pre_thread;

        int hardware_threads = std::thread::hardware_concurrency();
        int num_threads = std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);
        int block_size = len / num_threads;

        std::vector<std::thread> threads(num_threads - 1);
        int block_start = 0;
        int block_end = 0;

        for (unsigned int i = 0; i < (num_threads - 1); i++) {
            block_start = i * block_size;
            block_end = block_start + block_size;

            threads[i] = std::thread(data_chunk(), x, res, block_start, block_end);
        }

        data_chunk()(x, res, block_end, len);

        //for (const auto& curr_thread : threads)
        //{
        //    if(curr_thread.joinable())
        //        curr_thread.join();
        //}

        for (unsigned int i = 0; i < threads.size(); ++i)
        {
            //if (i.joinable())
            threads.at(i).join();
        }
    }

    void print() {

        for (int i = 0; i < m_row; i++) {
            for (int j = 0; j < m_column; j++) {
                std::cout << m_data[i + j] << " ";
            }
            std::cout << std::endl;
        }

        std::cout << std::endl;

        for (int i = 0; i < m_row; i++) {
            for (int j = 0; j < m_column; j++) {
                std::cout << m_data[i + j] << " ";
            }
        }

        std::cout << std::endl;
    }

    ~Matrix1D() {
        delete[] m_data;
    }


};