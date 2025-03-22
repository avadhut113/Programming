#pragma once

//Use cases
//my_shared_pointer<int> sp1(new int);
//my_shared_pointer<int> sp2(new int);
// 
// copy semantics
//my_shared_pointer<int> sp3(sp1);
//sp2 = sp1;
//sp3 = sp1;

//move semantic
// 
//my_shared_pointer<int> sp4(std::move(sp1));            //rc=1
//my_shared_pointer<int> sp4(std::move(sp1));            //rc=2
//my_shared_pointer<int> sp4(std::move(sp1));            //empty   
//     
//     

class refrence_count
{
    unsigned int m_count;
public:
    refrence_count() : m_count(0) {}
    void operator--(int) {
        this->m_count--;
    }

    void operator++(int) {
        this->m_count++;
    }

    unsigned int get_count() const {
        return m_count;
    }
};

template <typename T>
class my_shared_pointer
{
    T* m_ptr;
    refrence_count* m_ref_count;
public:
    explicit my_shared_pointer(T* p) :m_ptr(p), m_ref_count(new refrence_count) {
        std::cout << "my_shared_pointer" << std::endl;
        if(m_ptr)
            (*m_ref_count)++;
    }

    my_shared_pointer(const my_shared_pointer& sp_right) {
        std::cout << "my_shared_pointer(const my_shared_pointer& right)" << std::endl;
        m_ptr = sp_right.m_ptr;
        m_ref_count = sp_right.m_ref_count;
        if(m_ref_count)
            (*m_ref_count)++;
    }

    my_shared_pointer& operator=(const my_shared_pointer& sp_right) {
        std::cout << "my_shared_pointer& operator=(const my_shared_pointer& right)" << std::endl;
        if (this != &sp_right && m_ptr != sp_right.m_ptr) {
            (*m_ref_count)--;
            if (m_ref_count->get_count() == 0) {
                delete m_ptr;
                delete m_ref_count;
            }

            m_ptr = sp_right.m_ptr;
            m_ref_count = sp_right.m_ref_count;
            if (m_ref_count)
                (*m_ref_count)++;
        }
        return *this;
    }

    my_shared_pointer(my_shared_pointer&& sp_right) noexcept {
        std::cout << "my_shared_pointer(my_shared_pointer&& right)" << std::endl;
        m_ptr = sp_right.m_ptr;
        m_ref_count = sp_right.m_ref_count;

        sp_right.m_ptr = nullptr;
        sp_right.m_ref_count = nullptr;
    }

    my_shared_pointer& operator=(my_shared_pointer&& sp_right) noexcept {
        std::cout << "my_shared_pointer& operator=(my_shared_pointer&& right)" << std::endl;
        if (this != &sp_right) {
            (*m_ref_count)--;
            if (m_ref_count->get_count() == 0) {
                delete m_ptr;
                delete m_ref_count;
            }

            m_ptr = sp_right.m_ptr;
            m_ref_count = sp_right.m_ref_count;

            sp_right.m_ptr = nullptr;
            sp_right.m_ref_count = nullptr;
        }
        return *this;
    }

    T* operator->() {
        return m_ptr;
    }

    T& operator*() {
        return *m_ptr;
    }

    ~my_shared_pointer() {
        std::cout << "~my_shared_pointer" << std::endl;
        if (m_ref_count != nullptr) {
            (*m_ref_count)--;
            if (m_ref_count->get_count() == 0) {
                delete m_ptr;
                delete m_ref_count;
            }
        }   
    }
};