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
        iterator(pointer ptr) : ptr_(ptr) {}
    public:
    
    	
    	reference operator*() const { return *ptr_; }
        pointer operator->() { return ptr_; }
    
        // Prefix increment
        iterator& operator++() { ptr_++; return *this; }  
    
        // Postfix increment
        iterator operator++(int) 
        { 
            iterator tmp = *this; 
            ++(*this); 
            return tmp; 
            
        }

        iterator& operator--() { 
            ptr_--; return *this; 
        }  
    
        // Postfix increment
        iterator operator--(int) 
        { 
            iterator tmp = *this; 
            --(*this); 
            return tmp; 
            
        }

        iterator operator[](int n) const { //random Access
            iterator tmp = *this; 
            for (int i = 0; i < n; ++i) {
                ++tmp;
            }
            return tmp; 
        }
        
    
        friend bool operator== (const iterator& a, const iterator& b) { return a.ptr_ == b.ptr_; };
        friend bool operator!= (const iterator& a, const iterator& b) { return a.ptr_ != b.ptr_; };   
    
    };
    class reverseIterator 
    {
        friend class MyArray;
        using value_type = T;
        using reference = T&;
        using pointer = T*;
    private:
        pointer ptr_;
        reverseIterator(pointer ptr) : ptr_(ptr) {}
    public:
    
    	
    	reference operator*() const { return *ptr_; }
        pointer operator->() { return ptr_; }
    
        // Prefix increment
        reverseIterator& operator++() { ptr_--; return *this; }  
    
        // Postfix increment
        reverseIterator operator++(int) 
        { 
            reverseIterator tmp = *this; 
            --(*this); 
            return tmp; 
            
        }

        reverseIterator& operator--() { ptr_++; return *this; }  
    
        // Postfix increment
        reverseIterator operator--(int) 
        { 
            reverseIterator tmp = *this; 
            
            ++(*this); 
            return tmp; 
            
        }
    
        friend bool operator== (const reverseIterator& a, const reverseIterator& b) { return a.ptr_ == b.ptr_; };
        friend bool operator!= (const reverseIterator& a, const reverseIterator& b) { return a.ptr_ != b.ptr_; };   
    
    };

private:
    using value_type = T;
    using reference = value_type&;
    value_type data_[N];
    typedef const iterator constIterator;
    typedef const reverseIterator constReverseIterator;
    
public:
    explicit MyArray (const std::initializer_list<T> list)
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
		return iterator(&data_[0]);
    }

	iterator end() {
		return iterator(&data_[N]); 
    }
    
    reverseIterator rbegin() 
	{
		return reverseIterator(&data_[N - 1]);
    }

	reverseIterator rend() {
		return reverseIterator(&data_[0]);
    }
    
    constIterator beginConst() const
	{
		return constIterator(&data_[0]);
    }

	constIterator endConst() const
	{
		return constIterator(&data_[N]);
    }
    
    constReverseIterator rbeginConst() const
	{
		return constReverseIterator(&data_[N - 1]);
    }

	constReverseIterator rendConst() const 
	{
		return constReverseIterator(&data_[0] - 1);
    }

    bool operator==(const MyArray& other) const
    {
        
        if (N != other.size()) 
        {
            return false;
        }
        
        for(size_t i = 0; i < N; ++i)
        {
            if (data_[i] != other.data_[i])
            {
                return false;
            }
        }
        return true;
    }
    
    bool operator!=(const MyArray& other) const
    {
        if (N != other.size())
        {
            return true;
        }
        for(size_t i = 0; i < N; ++i)
        {
            if (data_[i] != other.data_[i])
            {
                return true;
            }
        }
        return false;
    }
    
    bool operator>(const MyArray& other) const
    {
        if (N < other.size())
        {
            return false;
        }
        if (N > other.size())
        {
            return true;
        }
        for(size_t i = 0; i < N; ++i)
        {
            if (data_[i] < other.data_[i])
            {
                return false;
            }
        }
        return true;
    }
    
    bool operator<(const MyArray& other) const
    {
        if (N < other.size())
        {
            return true;
        }
        if (N > other.size())
        {
            return false;
        }
        for(size_t i = 0; i < N; ++i)
        {
            if (data_[i] > other.data_[i])
            {
                return true;
            }
        }
        return false;
    }
    
    bool operator>=(const MyArray& other) const
    {
        
        if (*this == other || *this > other)
        {
            return true;
        }
        return false;
    }
    
    bool operator<=(const MyArray& other) const
    {
        
         if (*this == other || *this < other)
        {
            return true;
        }
        return false;
    }
    
    value_type& operator[](int i)
    {
        //return data_[i];
        auto it = iterator(&data_[0]);
        std::cout << *it[i] << std::endl;
        return *it[i];
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
        auto it = constIterator(&data_[0]);
        std::cout << *it[i] << std::endl;
        return *it[i];
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
