#pragma once

#include <iostream>
#include <stdexcept>


template <class T, size_t N>
class MyArray
{
    template <typename U>
    class iterator 
    {
        friend class MyArray;
        using value_type = U;
        using reference = U&;
        using pointer = U*;
        friend class MyArray;
        
    private:
        pointer ptr_;
        iterator(pointer ptr) : ptr_(ptr) {}
        iterator(const iterator<U>& it) = default;
    public:
    
    	
    	reference operator*() { 
            return *ptr_; 
        }

        const U& operator*() const {
            return *ptr_; 
        }


        pointer operator->() { 
            return ptr_; 
        }
    
        // Prefix increment
        iterator<U>& operator++() { ++ptr_; return *this; }  
    
        // Postfix increment
        iterator<U> operator++(int) 
        { 
            iterator tmp = *this; 
            ++(*this); 
            return tmp; 
            
        }

        bool operator== (const iterator& b) { return ptr_ == b.ptr_; };
        bool operator!= (const iterator& b) { return ptr_ != b.ptr_; };   
    
    };

    template <typename U>
    class reverseIterator 
    {
        friend class MyArray;
        using value_type = U;
        using reference = U&;
        using pointer = U*;
        friend class MyArray;
        
    private:
        pointer ptr_;
        reverseIterator(pointer ptr) : ptr_(ptr) {}
        reverseIterator(const reverseIterator<U>& it) = default;
    public:
    
    	
    	reference operator*() { 
            return *ptr_; 
        }

        const U& operator*() const {
            return *ptr_; 
        }


        pointer operator->() { 
            return ptr_; 
        }
    
        // Prefix increment
        reverseIterator<U>& operator++() { --ptr_; return *this; }  
    
        // referenceIterator increment
        reverseIterator<U> operator++(int) 
        { 
            iterator tmp = *this; 
            --(*this); 
            return tmp; 
            
        }

        bool operator== (const reverseIterator& b) { return ptr_ == b.ptr_; };
        bool operator!= (const reverseIterator& b) { return ptr_ != b.ptr_; };   
    
    };

private:
    using value_type = T;
    using reference = value_type&;
    value_type data_[N];
    //typedef const iterator constIterator;
    //typedef const reverseIterator constReverseIterator;
    
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
    
    
    iterator<value_type> begin() 
	{
		return iterator<value_type>(&data_[0]);
    }

	iterator<value_type> end() {
		return iterator<value_type>(&data_[N]); 
    }
    
    reverseIterator<value_type> rbegin() 
	{
		return reverseIterator<value_type>(&data_[N - 1]);
    }

	reverseIterator<value_type> rend() {
		return reverseIterator<value_type>(&data_[0]);
    }
    
    iterator<const value_type> beginConst()
	{
		return iterator<const value_type>(&data_[0]);
    }

	iterator<const value_type> endConst()
	{
		return iterator<const value_type>(&data_[N]);
    }
    
    reverseIterator<const value_type> rbeginConst()
	{
		return reverseIterator<const value_type>(&data_[N - 1]);
    }

	reverseIterator<const value_type> rendConst()
	{
		return reverseIterator<const value_type>(&data_[0]);
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
        return !(*this < other);
        
    }
    
    bool operator<=(const MyArray& other) const
    {
        
        return !(*this > other);
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
    
    const value_type& operator[](size_t i) const
    {
        return data_[i];
    }
    
    const value_type atConst(int i) const
    {
    	if (i >= int(size())) {
		throw std::invalid_argument("Element not exist");
	    }
        return data_[i];
        
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
