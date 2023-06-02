#pragma once

#include <iostream>
#include <stdexcept>
#include <iterator>


template <class T, size_t N>
class MyArray
{
    class iterator 
    {
        friend class MyArray;
        using value_type = T;
        using reference = T&;
        using pointer = T*;
        friend class MyArray;
        
    private:
        pointer ptr_;
        int index;
        int max_index;
        iterator(pointer ptr, int idx, int max) : ptr_(ptr), index(idx), max_index(max) {}
    public:
    
    	
    	reference operator*() const { 
            //std::cout << "index " << index << " max " << max_index << std::endl;
            if (index == -1 || index == max_index) {
                throw std::invalid_argument("Trying to get element out of range");   
            }
            
            return *ptr_; 
        }
        pointer operator->() { 
            if (index == -1 || index == max_index) {
                throw std::invalid_argument("Trying to get element out of range");   
            }
            return ptr_; 
        }
    
        // Prefix increment
        iterator& operator++() { ++ptr_; ++index; return *this; }  
    
        // Postfix increment
        iterator operator++(int) 
        { 
            iterator tmp = *this; 
            ++(*this); 
            ++index;
            return tmp; 
            
        }

        /*iterator& operator--() { 
            --ptr_; 
            return *this; 
        }  
    
        // Postfix increment
        iterator operator--(int) 
        { 
            iterator tmp = *this; 
            --(*this); 
            return tmp; 
            
        }

        iterator operator[](int n) const { //random Access, доступ О(1)
            iterator tmp = *this; 
            tmp += n;
            return tmp;
        }
        
        
        iterator& operator+=(std::ptrdiff_t n) { //смещаем указатель
            
            ptr_ += n; 
            return *this;
        }*/


        bool operator== (const iterator& b) { return ptr_ == b.ptr_; };
        bool operator!= (const iterator& b) { return ptr_ != b.ptr_; };   
    
    };
    class reverseIterator 
    {
        friend class MyArray;
        using value_type = T;
        using reference = T&;
        using pointer = T*;
    private:
        pointer ptr_;
        int index;
        int max_index;
        reverseIterator(pointer ptr, int idx, int max) : ptr_(ptr), index(idx), max_index(max) {}
    public:
    
    	
    	reference operator*() const { 
            //reverseIterator tmp = *this;
            //std::cout << "index " << index << " max " << max_index << std::endl;
            if (index == -1 || index == max_index) {
                throw std::invalid_argument("Trying to get element out of range");   
            }
            return *ptr_; 
        }

        pointer operator->() { 
            if (index == -1 || index == max_index) {
                throw std::invalid_argument("Trying to get element out of range");   
            }
            return ptr_; 
        }
    
        // Prefix increment
        reverseIterator& operator++() { --ptr_; --index; return *this; }  
    
        // Postfix increment
        reverseIterator operator++(int) 
        { 
            reverseIterator tmp = *this; 
            --(*this); 
            --index;
            return tmp; 
            
        }

        /*reverseIterator& operator--() { ++ptr_; return *this; }  
    
        // Postfix increment
        reverseIterator operator--(int) 
        { 
            reverseIterator tmp = *this; 
            
            ++(*this); 
            return tmp; 
            
        }

        reverseIterator operator[](int n) const { //random Access, доступ О(1)
            iterator tmp = *this; 
            tmp -= n;
            return tmp;
        }
        
        
        reverseIterator& operator-=(std::ptrdiff_t n) { //смещаем указатель
            
            ptr_ -= n; 
            return *this;
        }*/
    
        bool operator== (const reverseIterator& b) { return ptr_ == b.ptr_; };
        bool operator!= (const reverseIterator& b) { return ptr_ != b.ptr_; };   
    
    };

private:
    using value_type = T;
    using reference = value_type&;
    value_type data_[N];
    typedef const iterator constIterator;
    typedef const reverseIterator constReverseIterator;
    
public:
    explicit MyArray (const std::initializer_list<T>& list)
    {
        if (list.size() != N) {
            throw std::invalid_argument("Incorrect size of initializer list");   
        }
        std::copy(list.begin(), list.end(), data_);
        
    };

    MyArray ()
    {
        
    };
    
    
    iterator begin() 
	{
		return iterator(&data_[0], 0, N);
    }

	iterator end() {
		return iterator(&data_[N], N, N); 
    }
    
    reverseIterator rbegin() 
	{
		return reverseIterator(&data_[N - 1], N - 1, N);
    }

	reverseIterator rend() {
		return reverseIterator(&data_[0], -1, N);
    }
    
    constIterator beginConst()
	{
		return constIterator(&data_[0], 0, N);
    }

	constIterator endConst()
	{
		return constIterator(&data_[N], N, N);
    }
    
    constReverseIterator rbeginConst()
	{
		return constReverseIterator(&data_[N - 1], N - 1, N);
    }

	constReverseIterator rendConst()
	{
		return constReverseIterator(&data_[0], -1, N);
    }

    bool operator==(const MyArray& other) const
    {
        return (N == other.size() && std::equal(data_, data_ + N, other.data_));
    }
    
    bool operator!=(const MyArray& other) const
    {
        return !(*this == other);
    }
    
    bool operator>(const MyArray& other) const
    {
        size_t n1 = N;
        size_t n2 = other.size();
        return !std::lexicographical_compare(data_, data_ + n1, other.data_, other.data_ + n2)
        && !(*this == other);
    }
    
    bool operator<(const MyArray& other) const
    {
        size_t n1 = N;
        size_t n2 = other.size();
        return std::lexicographical_compare(data_, data_ + n1, other.data_, other.data_ + n2);
    }
    
    bool operator>=(const MyArray& other) const
    {
        return (*this == other || *this > other);
        
    }
    
    bool operator<=(const MyArray& other) const
    {
        
        return (*this == other || *this < other);
    }
    
    value_type& operator[](int i)
    {
        return data_[i];
        //auto it = iterator(&data_[0]);
        //return *it[i];
    }
    
    value_type& at(int i) {
    	// Проверяем выход за пределы массива
    	if (i >= int(size())) {
		throw std::invalid_argument("Element not exist");
	}
        return data_[i];
        
    }
    
    const value_type& operator[](size_t i) const
    {
        return data_[i];
    }
    
    constIterator at(int i) const
    {
    	if (i >= int(size())) {
		throw std::invalid_argument("Element not exist");
	}
        auto begin_it = begin();
        auto end_it = end();
        int count = 0;
        while (begin_it != end_it)
        {
            if (count == i)
            {
                return begin_it;
            }
            ++begin_it;
            count++;
        }
        return NULL;
        
    }
    
    value_type& front()
    {
        return data_[0];
    }
    
    value_type& back()
    {
        return data_[N- 1];
    }
    
    const value_type& frontConst() const
    {
        return data_[0];
    }
    
    const value_type& backConst() const
    {
        return data_[N - 1];
    }
    
    bool empty() const
    {
        return N == 0;
    }
    
    size_t size() const
    {
        return N;
    }

    constexpr size_t sizeConstexpr() 
    {
        return N;
    }
    template <class U, size_t K>
    friend std::ostream& operator<< (std::ostream& , MyArray<U, K>&);
    
};

template <class T, size_t N>
std::ostream& operator<< (std::ostream& out, MyArray<T, N>& arr)
{
    for(size_t i = 0; i < arr.size(); ++i)
        {
            out << arr.data_[i] << " ";
        };
    return out;
}
