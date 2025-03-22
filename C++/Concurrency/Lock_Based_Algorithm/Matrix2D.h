#pragma once

#include <thread>
#include <vector>

template<class T>
class Matrix2D
{
    T** m_data;
    int m_row;
    int m_column;

public:

    Matrix2D(int row, int col) :m_row(row), m_column(col) {
        m_data = new T*[m_row];

        for (int i = 0; i < m_row; i++)
            m_data[i] = new T[m_column];
    }

    void set_val(int i, int j, int val) {
        m_data[i][j] = val;
    }

    void set_all(int value) {
        std::fill(m_data, m_data + m_row * m_column, value);
    }

    void set_all_rand() {
        for (int i = 0; i < m_row; i++) {
            for (int j = 0; j < m_column; j++) {
                m_data[i][j] = std::rand() % 10;
            }
        }
    }

    static void sequential_multiply(Matrix2D* x, Matrix2D* y, Matrix2D* res) {

        if (!(x->m_column == y->m_row) || !((x->m_row == res->m_row) && (y->m_column == res->m_column))) {
            std::cout << "Incorrect diamenssions of Matrix2D" << std::endl;
        }

        for (int i = 0; i < x->m_row; i++) {
            for (int j = 0; j < y->m_column; j++) {
                int ele{ 0 };
                for (int k = 0; k < x->m_column; k++)
                    ele += x->m_data[i][k] * y->m_data[k][j];

                res->m_data[i][j] = ele;
            }
        }
    }

    static void parallel_multiply(Matrix2D* x, Matrix2D* y, Matrix2D* res) {

        if (!(x->m_column == y->m_row) || !((x->m_row == res->m_row) && (y->m_column == res->m_column))) {
            std::cout << "Incorrect diamenssions of Matrix2D" << std::endl;
        }

        struct data_chunk {
            void operator()(Matrix2D* x, Matrix2D* y, Matrix2D* res, int start,int end){

                for (int i = start; i < end; i++) {
                    for (int j = 0; j < y->m_column; j++) {
                        int ele{ 0 };
                        for (int k = 0; k < x->m_column; k++)
                            ele += x->m_data[i][k] * y->m_data[k][j];

                        res->m_data[i][j] = ele;
                    }
                }
            }
        };

        int len = res->m_row;

        if(!len)
            return;

        int min_row_pre_thread = 10;
        int max_threads = (len + min_row_pre_thread - 1) / min_row_pre_thread;

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

    static void Sequential_transpose(Matrix2D* x, Matrix2D* res)
    {
        if ((x->m_row != res->m_column) && (x->m_column != res->m_row)) {
            std::cout << "InvalidDoamenssions" << std::endl;
        }

        for (int i = 0; i < x->m_row; i++) {
            for (int j = 0; j < x->m_column; j++) {
                res->m_data[j][i] = x->m_data[i][j];
            }
        }
    }

    static void Parallel_transpose(Matrix2D* x, Matrix2D* res)
    {

        if ((x->m_row != res->m_column) && (x->m_column != res->m_row)) {
            std::cout << "InvalidDoamenssions" << std::endl;
        }

        struct data_chunk {
            void operator()(Matrix2D* x, Matrix2D* res, int start, int end) {

                for (int i = start; i < end; i++) {
                    for (int j = 0; j < x->m_column; j++) {
                        res->m_data[j][i] = x->m_data[i][j];
                    }
                }
            }
        };

        int len = x->m_row;

        if (!len)
            return;

        int min_row_pre_thread = 10;
        int max_threads = (len + min_row_pre_thread - 1) / min_row_pre_thread;

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
                std::cout << m_data[i][j] << " ";
            }
            std::cout << std::endl;
        }

        std::cout << std::endl;
    }

    ~Matrix2D() {

        for (int i = 0; i < m_row; i++)
            delete[] m_data[i];

        delete[] m_data;
    }


};