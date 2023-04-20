#pragma once

#include <iostream>
#include <stdexcept>



template <class T, size_t N>
class MyArray
{
    class iterator 
    {
        friend class MyArray;
        using value_type = T;
        using reference = T&;
        using pointer = T*;
    private:
        pointer ptr_;
    public:
    
    	iterator(pointer ptr) : ptr_(ptr) {}
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
    public:
    
    	reverseIterator(pointer ptr) : ptr_(ptr) {}
    	reference operator*() const { return *ptr_; }
        pointer operator->() { return ptr_; }
    
        // Prefix increment
        reverseIterator& operator--() { ptr_--; return *this; }  
    
        // Postfix increment
        reverseIterator operator--(int) 
        { 
            reverseIterator tmp = *this; 
            --(*this); 
            return tmp; 
            
        }
    
        friend bool operator== (const reverseIterator& a, const reverseIterator& b) { return a.ptr_ == b.ptr_; };
        friend bool operator!= (const reverseIterator& a, const reverseIterator& b) { return a.ptr_ != b.ptr_; };   
    
    };
    class constIterator 
    {
        friend class MyArray;
        using value_type = T;
        using const_reference = value_type&;
        using const_pointer = value_type*;
    private:
        const_pointer ptr_;
    public:
    
    	constIterator(const const_pointer ptr) : ptr_(ptr) {}
    	const_reference operator*() const { return *ptr_; }
        const_pointer operator->() const  { return ptr_; }
    
        // Prefix increment
        constIterator& operator++() const { ptr_++; return *this; }  
    
        // Postfix increment
        constIterator operator++(int) const 
        { 
            constIterator tmp = *this; 
            ++(*this); 
            return tmp; 
            
        }
    
        friend bool operator== (const constIterator& a, const constIterator& b) { return a.ptr_ == b.ptr_; };
        friend bool operator!= (const constIterator& a, const constIterator& b) { return a.ptr_ != b.ptr_; };   
    
    };
    class constReverseIterator 
    {
        friend class MyArray;
        using value_type = T;
        using const_reference = value_type&;
        using const_pointer = value_type*;
    private:
        const_pointer ptr_;
    public:
    
    	constReverseIterator(const const_pointer ptr) : ptr_(ptr) {}
    	const_pointer operator*() const { return *ptr_; }
        const_pointer operator->() const { return ptr_; }
    
        // Prefix increment
        constReverseIterator& operator--() const { ptr_--; return *this; }  
    
        // Postfix increment
        constReverseIterator operator--(int) const 
        { 
            constReverseIterator tmp = *this; 
            --(*this); 
            return tmp; 
            
        }
    
        friend bool operator== (const constReverseIterator& a, const constReverseIterator& b) { return a.ptr_ == b.ptr_; };
        friend bool operator!= (const constReverseIterator& a, const constReverseIterator& b) { return a.ptr_ != b.ptr_; };   
    
    };
private:
    using value_type = T;
    using reference = value_type&;
    value_type data_[N];//+ 2];
    size_t size_;
    
public:
    MyArray (std::initializer_list<T> list)
    {
        int counter = 0;
        for( auto elem : list )
        {
            data_[counter] = elem ;
            counter++;
        }
        size_ = N;
        //data_[N] = 0;
        //data_[0] = 0;
    };

    MyArray ()
    {
        
        size_ = N;
        //data_[N] = 0;
        //data_[0] = 0;
    };
    
    
    
    iterator begin() 
	{
		return iterator(&data_[0]);
    }

	iterator end() {
		return iterator(&data_[size_]); // +1 к сайзу не нужен
    }
    
    reverseIterator rbegin() 
	{
		return reverseIterator(&data_[size_ -1]);
    }

	reverseIterator rend() {
		return reverseIterator(&data_[0] - 1);
    }
    
    constIterator begin() const
	{
		return constIterator(&data_[0]);
    }

	constIterator end() const
	{
		return constIterator(&data_[size_]);
    }
    
    constReverseIterator rbegin() const
	{
		return constReverseIterator(&data_[size_ - 1]);
    }

	constReverseIterator rend() const 
	{
		return constReverseIterator(&data_[0] - 1);
    }

    bool operator==(const MyArray& other)
    {
        
        if (size_ != other.size_) 
        {
            return false;
        }
        
        for(size_t i = 0; i < size_; ++i)
        {
            if (data_[i] != other.data_[i])
            {
                return false;
            }
        }
        return true;
    }
    
    bool operator!=(const MyArray& other)
    {
        if (size_ != other.size_)
        {
            return true;
        }
        for(size_t i = 0; i < size_; ++i)
        {
            if (data_[i] != other.data_[i])
            {
                return true;
            }
        }
        return false;
    }
    
    bool operator>(const MyArray& other)
    {
        if (size_ < other.size_)
        {
            return false;
        }
        if (size_ > other.size_)
        {
            return true;
        }
        for(size_t i = 0; i < size_; ++i)
        {
            if (data_[i] < other.data_[i])
            {
                return false;
            }
        }
        return true;
    }
    
    bool operator<(const MyArray& other)
    {
        if (size_ < other.size_)
        {
            return true;
        }
        if (size_ > other.size_)
        {
            return false;
        }
        for(size_t i = 0; i < size_; ++i)
        {
            if (data_[i] > other.data_[i])
            {
                return true;
            }
        }
        return false;
    }
    
    bool operator>=(const MyArray& other)
    {
        
        if (*this == other || *this > other)
        {
            return true;
        }
        return false;
    }
    
    bool operator<=(const MyArray& other)
    {
        
         if (*this == other || *this < other)
        {
            return true;
        }
        return false;
    }
    
    value_type& operator[](int i)
    {
        return data_[i];
    }
    
    value_type& at(int i) {
    	// Проверяем выход за пределы массива
    	if (i >= int(size())) {
		throw std::invalid_argument("Element not exist");
	}
        return data_[i];
        
    }
    
    value_type& operator[](size_t i) const
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
        return data_[size_];
    }
    
    value_type& front() const
    {
        return data_[0];
    }
    
    value_type& back() const
    {
        return data_[size_ - 1];
    }
    
    bool empty()
    {
        return size_ == 0;
    }
    
    size_t size()
    {
        return size_;
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
    for(size_t i = 0; i < arr.size_; ++i)
        {
            out << arr.data_[i] << " ";
        };
    return out;
}

