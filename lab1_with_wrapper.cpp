/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <stdexcept>

using namespace std;

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
    MyArray ()
    {
        for(size_t i = 0; i < N; ++i)// + 2; ++i)
        {
            
            data_[i] = 0;
            
        }
        size_ = N;
        //data_[N] = 0;
        //data_[0] = 0;
    };
    
    
    
    iterator begin() 
	{
		return iterator(&data_[0]);
    }

	iterator end() {
		return iterator(&data_[size_]);
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
            cout << "== " << endl;
            if (data_[i] != other.data_[i])
            {
                return false;
            }
        }
        return true;
    }
    
    bool operator!=(const MyArray& other)
    {
       cout << "!= " << endl;
        if (size_ != other.size_)
        {
            return true;
        }
        for(size_t i = 0; i < size_; ++i)
        {
            cout << "Data " << data_[i] << " and " << other.data_[i] << endl;
            if (data_[i] != other.data_[i])
            {
                return true;
            }
        }
        return false;
    }
    
    bool operator>(const MyArray& other)
    {
        cout << ">" << endl;
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
            cout << "Data " << data_[i] << " and " << other.data_[i] << endl;
            if (data_[i] < other.data_[i])
            {
                return false;
            }
        }
        return true;
    }
    
    bool operator<(const MyArray& other)
    {
        cout << "<" << endl;
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
            cout << "Data " << data_[i] << " and " << other.data_[i] << endl;
            if (data_[i] > other.data_[i])
            {
                return true;
            }
        }
        return false;
    }
    
    bool operator>=(const MyArray& other)
    {
        /*cout << ">= " << endl;
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
            cout << "Data " << data_[i] << " and " << other.data_[i] << endl;
            if (data_[i] < other.data_[i])
            {
                return false;
            }
        }
        return true;*/
        if (*this == other || *this > other)
        {
            return true;
        }
        return false;
    }
    
    bool operator<=(const MyArray& other)
    {
        /*cout << "<= " << endl;
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
            cout << "Data " << data_[i] << " and " << other.data_[i] << endl;
            if (data_[i] > other.data_[i])
            {
                return false;
            }
        }
        return true;*/
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
    
    iterator at(int i) {
        if (i >= size()) {
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
    
    value_type& operator[](int i) const
    {
        return data_[i];
    }
    
    constIterator at(int i) const
    {
        if (i >= size()) {
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
        return data_[size_ - 1];
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
    
    int size()
    {
        return size_;
    }
    template <class U, size_t K>
    friend ostream& operator<< (ostream& , MyArray<U, K>&);
    
};

template <class T, size_t N>
ostream& operator<< (ostream& out, MyArray<T, N>& arr)
{
    cout << "ARR SIZE =" << arr.size_<< endl;
    for(size_t i = 0; i < arr.size_; ++i)
        {
            cout << arr.data_[i] << " ";
        };
    return out;
}

int main()
{
    
    //int arraysCount = 0;
    MyArray<int, 10> arr1;
    MyArray<int, 10> arr2;
    MyArray<int, 10> arr3;
    MyArray<int, 10> arr4;
    MyArray<int, 10> arr5;
    while(true)
    {
        cout << "1.  Change element" << endl;
        cout << "2.  Arr1 == Arr2" << endl;
        cout << "3.  Arr1 != Arr2" << endl;
        cout << "4.  Arr1 >= Arr2" << endl;
        cout << "5.  Arr1 <= Arr2" << endl;
        cout << "6.  Arr1 > Arr2" << endl;
        cout << "7.  Arr1 < Arr2" << endl;
        cout << "8.  Print array element" << endl;
        cout << "9.  Check if array is empty" << endl;
        cout << "10. Print array size" << endl;
        cout << "11. Print front" << endl;
        cout << "12. Print back" << endl;
        cout << "13. Print Array" << endl;
        cout << "14. Create Array (Not supported)" << endl;
        cout << "15. Exit" << endl;
        cout << "Enter command number: " << endl;
        int x;
        cin >> x;
        int option;
        int arrayNumber;
        int position;
        switch(x)
        {
            case 1:
                cout << "Enter array number: " << endl;
                cin >> arrayNumber;
                cout << "Enter position: " << endl;
               
                cin >> position;
                cout << "Enter new value: " << endl;
                int newValue;
                cin >> newValue;
                if (arrayNumber == 1)
                {
                    arr1[position] = newValue;
                }
                else if (arrayNumber == 2)
                {
                    arr2[position] = newValue;
                }
                else if (arrayNumber == 3)
                {
                    arr3[position] = newValue;
                }
                else if (arrayNumber == 4)
                {
                    arr4[position] = newValue;
                }
                else if (arrayNumber == 5)
                {
                    arr5[position] = newValue;
                }
                else 
                {
                    cout << "Maximum array number is 5!";
                    continue;
                }


                continue;
            case 2:
                cout << "Enter 1 to compare Array 1 and Array 2: " << endl;
                cout << "Enter 2 to compare Array 1 and Array 3: " << endl;
                cout << "Enter 3 to compare Array 1 and Array 4: " << endl;
                cout << "Enter 4 to compare Array 1 and Array 5: " << endl;
                cout << "Enter 5 to compare Array 2 and Array 3: " << endl;
                cout << "Enter 6 to compare Array 2 and Array 4: " << endl;
                cout << "Enter 7 to compare Array 2 and Array 5: " << endl;
                cout << "Enter 8 to compare Array 3 and Array 4: " << endl;
                cout << "Enter 9 to compare Array 3 and Array 5: " << endl;
                cout << "Enter 10 to compare Array 4 and Array 5: " << endl;
                
                cin >> option;
                if (option == 1)
                {
                    bool res = arr1 == arr2;
                    if (res == 1)
                    {
                        cout << "Equal" << endl;
                    }
                    else 
                    {
                        cout << "Not equal" << endl;
                    }
                }
                else if (option == 2)
                {
                    bool res = arr1 == arr3;
                    if (res == 1)
                    {
                        cout << "Equal" << endl;
                    }
                    else 
                    {
                        cout << "Not equal" << endl;
                    }
                }
                else if (option == 3)
                {
                    bool res = arr1 == arr4;
                    if (res == 1)
                    {
                        cout << "Equal" << endl;
                    }
                    else 
                    {
                        cout << "Not equal" << endl;
                    }
                }
                else if (option == 4)
                {
                    bool res = arr1 == arr5;
                    if (res == 1)
                    {
                        cout << "Equal" << endl;
                    }
                    else 
                    {
                        cout << "Not equal" << endl;
                    }
                }
                else if (option == 5)
                {
                    bool res = arr2 == arr3;
                    if (res == 1)
                    {
                        cout << "Equal" << endl;
                    }
                    else 
                    {
                        cout << "Not equal" << endl;
                    }
                }
                else if (option == 6)
                {
                    bool res = arr2 == arr4;
                    if (res == 1)
                    {
                        cout << "Equal" << endl;
                    }
                    else 
                    {
                        cout << "Not equal" << endl;
                    }
                }
                else if (option == 7)
                {
                    bool res = arr2 == arr5;
                    if (res == 1)
                    {
                        cout << "Equal" << endl;
                    }
                    else 
                    {
                        cout << "Not equal" << endl;
                    }
                }
                else if (option == 8)
                {
                    bool res = arr3 == arr4;
                    if (res == 1)
                    {
                        cout << "Equal" << endl;
                    }
                    else 
                    {
                        cout << "Not equal" << endl;
                    }
                }
                else if (option == 9)
                {
                    bool res = arr3 == arr5;
                    if (res == 1)
                    {
                        cout << "Equal" << endl;
                    }
                    else 
                    {
                        cout << "Not equal" << endl;
                    }
                }
                else if (option == 10)
                {
                    bool res = arr4 == arr5;
                    if (res == 1)
                    {
                        cout << "Equal" << endl;
                    }
                    else 
                    {
                        cout << "Not equal" << endl;
                    }
                }
                else 
                {
                    cout << "Incorrect option!";
                    continue;
                }
                continue;
            case 3:
                cout << "Enter 1 to compare Array 1 and Array 2: " << endl;
                cout << "Enter 2 to compare Array 1 and Array 3: " << endl;
                cout << "Enter 3 to compare Array 1 and Array 4: " << endl;
                cout << "Enter 4 to compare Array 1 and Array 5: " << endl;
                cout << "Enter 5 to compare Array 2 and Array 3: " << endl;
                cout << "Enter 6 to compare Array 2 and Array 4: " << endl;
                cout << "Enter 7 to compare Array 2 and Array 5: " << endl;
                cout << "Enter 8 to compare Array 3 and Array 4: " << endl;
                cout << "Enter 9 to compare Array 3 and Array 5: " << endl;
                cout << "Enter 10 to compare Array 4 and Array 5: " << endl;
                cin >> option;
                if (option == 1)
                {
                    bool res = arr1 != arr2;
                    if (res != 1)
                    {
                        cout << "Equal" << endl;
                    }
                    else 
                    {
                        cout << "Not equal" << endl;
                    }
                }
                else if (option == 2)
                {
                    bool res = arr1 != arr3;
                    if (res != 1)
                    {
                        cout << "Equal" << endl;
                    }
                    else 
                    {
                        cout << "Not equal" << endl;
                    }
                }
                else if (option == 3)
                {
                    bool res = arr1 != arr4;
                    if (res != 1)
                    {
                        cout << "Equal" << endl;
                    }
                    else 
                    {
                        cout << "Not equal" << endl;
                    }
                }
                else if (option == 4)
                {
                    bool res = arr1 != arr5;
                    if (res != 1)
                    {
                        cout << "Equal" << endl;
                    }
                    else 
                    {
                        cout << "Not equal" << endl;
                    }
                }
                else if (option == 5)
                {
                    bool res = arr2 != arr3;
                    if (res != 1)
                    {
                        cout << "Equal" << endl;
                    }
                    else 
                    {
                        cout << "Not equal" << endl;
                    }
                }
                else if (option == 6)
                {
                    bool res = arr2 != arr4;
                    if (res != 1)
                    {
                        cout << "Equal" << endl;
                    }
                    else 
                    {
                        cout << "Not equal" << endl;
                    }
                }
                else if (option == 7)
                {
                    bool res = arr2 != arr5;
                    if (res != 1)
                    {
                        cout << "Equal" << endl;
                    }
                    else 
                    {
                        cout << "Not equal" << endl;
                    }
                }
                else if (option == 8)
                {
                    bool res = arr3 != arr4;
                    if (res != 1)
                    {
                        cout << "Equal" << endl;
                    }
                    else 
                    {
                        cout << "Not equal" << endl;
                    }
                }
                else if (option == 9)
                {
                    bool res = arr3 != arr5;
                    if (res != 1)
                    {
                        cout << "Equal" << endl;
                    }
                    else 
                    {
                        cout << "Not equal" << endl;
                    }
                }
                else if (option == 10)
                {
                    bool res = arr4 != arr5;
                    if (res != 1)
                    {
                        cout << "Equal" << endl;
                    }
                    else 
                    {
                        cout << "Not equal" << endl;
                    }
                }
                else 
                {
                    cout << "Incorrect option!";
                    continue;
                }
                continue;
            case 4:
                cout << "Enter 1 to compare Array 1 and Array 2: " << endl;
                cout << "Enter 2 to compare Array 1 and Array 3: " << endl;
                cout << "Enter 3 to compare Array 1 and Array 4: " << endl;
                cout << "Enter 4 to compare Array 1 and Array 5: " << endl;
                cout << "Enter 5 to compare Array 2 and Array 3: " << endl;
                cout << "Enter 6 to compare Array 2 and Array 4: " << endl;
                cout << "Enter 7 to compare Array 2 and Array 5: " << endl;
                cout << "Enter 8 to compare Array 3 and Array 4: " << endl;
                cout << "Enter 9 to compare Array 3 and Array 5: " << endl;
                cout << "Enter 10 to compare Array 4 and Array 5: " << endl;
                cin >> option;
                if (option == 1)
                {
                    bool res = arr1 >= arr2;
                    if (res == 1)
                    {
                        cout << "Greater or equal" << endl;
                    }
                    else 
                    {
                        cout << "Not greater or equal" << endl;
                    }
                }
                else if (option == 2)
                {
                    bool res = arr1 >= arr3;
                    if (res == 1)
                    {
                        cout << "Greater or equal" << endl;
                    }
                    else 
                    {
                        cout << "Not greater or equal" << endl;
                    }
                }
                else if (option == 3)
                {
                    bool res = arr1 >= arr4;
                    if (res == 1)
                    {
                        cout << "Greater or equal" << endl;
                    }
                    else 
                    {
                        cout << "Not greater or equal" << endl;
                    }
                }
                else if (option == 4)
                {
                    bool res = arr1 >= arr5;
                    if (res == 1)
                    {
                        cout << "Greater or equal" << endl;
                    }
                    else 
                    {
                        cout << "Not greater or equal" << endl;
                    }
                }
                else if (option == 5)
                {
                    bool res = arr2 >= arr3;
                    if (res == 1)
                    {
                        cout << "Greater or equal" << endl;
                    }
                    else 
                    {
                        cout << "Not greater or equal" << endl;
                    }
                }
                else if (option == 6)
                {
                    bool res = arr2 >= arr4;
                    if (res == 1)
                    {
                        cout << "Greater or equal" << endl;
                    }
                    else 
                    {
                        cout << "Not greater or equal" << endl;
                    }
                }
                else if (option == 7)
                {
                    bool res = arr2 >= arr5;
                    if (res == 1)
                    {
                        cout << "Greater or equal" << endl;
                    }
                    else 
                    {
                        cout << "Not greater or equal" << endl;
                    }
                }
                else if (option == 8)
                {
                    bool res = arr3 >= arr4;
                    if (res == 1)
                    {
                        cout << "Greater or equal" << endl;
                    }
                    else 
                    {
                        cout << "Not greater or equal" << endl;
                    }
                }
                else if (option == 9)
                {
                    bool res = arr3 >= arr5;
                    if (res == 1)
                    {
                        cout << "Greater or equal" << endl;
                    }
                    else 
                    {
                        cout << "Not greater or equal" << endl;
                    }
                }
                else if (option == 10)
                {
                    bool res = arr4 >= arr5;
                    if (res == 1)
                    {
                        cout << "Greater or equal" << endl;
                    }
                    else 
                    {
                        cout << "Not greater or equal" << endl;
                    }
                }
                else 
                {
                    cout << "Incorrect option!";
                    continue;
                }
                continue;
            case 5:
                cout << "Enter 1 to compare Array 1 and Array 2: " << endl;
                cout << "Enter 2 to compare Array 1 and Array 3: " << endl;
                cout << "Enter 3 to compare Array 1 and Array 4: " << endl;
                cout << "Enter 4 to compare Array 1 and Array 5: " << endl;
                cout << "Enter 5 to compare Array 2 and Array 3: " << endl;
                cout << "Enter 6 to compare Array 2 and Array 4: " << endl;
                cout << "Enter 7 to compare Array 2 and Array 5: " << endl;
                cout << "Enter 8 to compare Array 3 and Array 4: " << endl;
                cout << "Enter 9 to compare Array 3 and Array 5: " << endl;
                cout << "Enter 10 to compare Array 4 and Array 5: " << endl;

                cin >> option;
                if (option == 1)
                {
                    bool res = arr1 <= arr2;
                    if (res == 1)
                    {
                        cout << "Smaller or equal" << endl;
                    }
                    else 
                    {
                        cout << "Not smaller or equal" << endl;
                    }
                }
                else if (option == 2)
                {
                    bool res = arr1 <= arr3;
                    if (res == 1)
                    {
                        cout << "Smaller or equal" << endl;
                    }
                    else 
                    {
                        cout << "Not smaller or equal" << endl;
                    }
                }
                else if (option == 3)
                {
                    bool res = arr1 <= arr4;
                    if (res == 1)
                    {
                        cout << "Smaller or equal" << endl;
                    }
                    else 
                    {
                        cout << "Not smaller or equal" << endl;
                    }
                }
                else if (option == 4)
                {
                    bool res = arr1 <= arr5;
                    if (res == 1)
                    {
                        cout << "Smaller or equal" << endl;
                    }
                    else 
                    {
                        cout << "Not smaller or equal" << endl;
                    }
                }
                else if (option == 5)
                {
                    bool res = arr2 <= arr3;
                    if (res == 1)
                    {
                        cout << "Smaller or equal" << endl;
                    }
                    else 
                    {
                        cout << "Not smaller or equal" << endl;
                    }
                }
                else if (option == 6)
                {
                    bool res = arr2 <= arr4;
                    if (res == 1)
                    {
                        cout << "Smaller or equal" << endl;
                    }
                    else 
                    {
                        cout << "Not smaller or equal" << endl;
                    }
                }
                else if (option == 7)
                {
                    bool res = arr2 <= arr5;
                    if (res == 1)
                    {
                        cout << "Smaller or equal" << endl;
                    }
                    else 
                    {
                        cout << "Not smaller or equal" << endl;
                    }
                }
                else if (option == 8)
                {
                    bool res = arr3 <= arr4;
                    if (res == 1)
                    {
                        cout << "Smaller or equal" << endl;
                    }
                    else 
                    {
                        cout << "Not smaller or equal" << endl;
                    }
                }
                else if (option == 9)
                {
                    bool res = arr3 <= arr5;
                    if (res == 1)
                    {
                        cout << "Smaller or equal" << endl;
                    }
                    else 
                    {
                        cout << "Not smaller or equal" << endl;
                    }
                }
                else if (option == 10)
                {
                    bool res = arr4 <= arr5;
                    if (res == 1)
                    {
                        cout << "Smaller or equal" << endl;
                    }
                    else 
                    {
                        cout << "Not smaller or equal" << endl;
                    }
                }
                else 
                {
                    cout << "Incorrect option!";
                    continue;
                }
                continue;
            case 6:
                cout << "Enter 1 to compare Array 1 and Array 2: " << endl;
                cout << "Enter 2 to compare Array 1 and Array 3: " << endl;
                cout << "Enter 3 to compare Array 1 and Array 4: " << endl;
                cout << "Enter 4 to compare Array 1 and Array 5: " << endl;
                cout << "Enter 5 to compare Array 2 and Array 3: " << endl;
                cout << "Enter 6 to compare Array 2 and Array 4: " << endl;
                cout << "Enter 7 to compare Array 2 and Array 5: " << endl;
                cout << "Enter 8 to compare Array 3 and Array 4: " << endl;
                cout << "Enter 9 to compare Array 3 and Array 5: " << endl;
                cout << "Enter 10 to compare Array 4 and Array 5: " << endl;

                cin >> option;
                if (option == 1)
                {
                    bool res = arr1 >= arr2;
                    if (res == 1)
                    {
                        cout << "Greater" << endl;
                    }
                    else 
                    {
                        cout << "Not greater" << endl;
                    }
                }
                else if (option == 2)
                {
                    bool res = arr1 > arr3;
                    if (res == 1)
                    {
                        cout << "Greater" << endl;
                    }
                    else 
                    {
                        cout << "Not greater" << endl;
                    }
                }
                else if (option == 3)
                {
                    bool res = arr1 > arr4;
                    if (res == 1)
                    {
                        cout << "Greater" << endl;
                    }
                    else 
                    {
                        cout << "Not greater" << endl;
                    }
                }
                else if (option == 4)
                {
                    bool res = arr1 > arr5;
                    if (res == 1)
                    {
                        cout << "Greater" << endl;
                    }
                    else 
                    {
                        cout << "Not greater" << endl;
                    }
                }
                else if (option == 5)
                {
                    bool res = arr2 > arr3;
                    if (res == 1)
                    {
                        cout << "Greater" << endl;
                    }
                    else 
                    {
                        cout << "Not greater" << endl;
                    }
                }
                else if (option == 6)
                {
                    bool res = arr2 > arr4;
                    if (res == 1)
                    {
                        cout << "Greater" << endl;
                    }
                    else 
                    {
                        cout << "Not greater" << endl;
                    }
                }
                else if (option == 7)
                {
                    bool res = arr2 > arr5;
                    if (res == 1)
                    {
                        cout << "Greater" << endl;
                    }
                    else 
                    {
                        cout << "Not greater" << endl;
                    }
                }
                else if (option == 8)
                {
                    bool res = arr3 > arr4;
                    if (res == 1)
                    {
                        cout << "Greater" << endl;
                    }
                    else 
                    {
                        cout << "Not greater" << endl;
                    }
                }
                else if (option == 9)
                {
                    bool res = arr3 > arr5;
                    if (res == 1)
                    {
                        cout << "Greater" << endl;
                    }
                    else 
                    {
                        cout << "Not greater" << endl;
                    }
                }
                else if (option == 10)
                {
                    bool res = arr4 > arr5;
                    if (res == 1)
                    {
                        cout << "Greater" << endl;
                    }
                    else 
                    {
                        cout << "Not greater" << endl;
                    }
                }
                else 
                {
                    cout << "Incorrect option!";
                    continue;
                }
                continue;
            case 7:
                cout << "Enter 1 to compare Array 1 and Array 2: " << endl;
                cout << "Enter 2 to compare Array 1 and Array 3: " << endl;
                cout << "Enter 3 to compare Array 1 and Array 4: " << endl;
                cout << "Enter 4 to compare Array 1 and Array 5: " << endl;
                cout << "Enter 5 to compare Array 2 and Array 3: " << endl;
                cout << "Enter 6 to compare Array 2 and Array 4: " << endl;
                cout << "Enter 7 to compare Array 2 and Array 5: " << endl;
                cout << "Enter 8 to compare Array 3 and Array 4: " << endl;
                cout << "Enter 9 to compare Array 3 and Array 5: " << endl;
                cout << "Enter 10 to compare Array 4 and Array 5: " << endl;

                cin >> option;
                if (option == 1)
                {
                    bool res = arr1 < arr2;
                    if (res == 1)
                    {
                        cout << "Smaller" << endl;
                    }
                    else 
                    {
                        cout << "Not smaller" << endl;
                    }
                }
                else if (option == 2)
                {
                    bool res = arr1 < arr3;
                    if (res == 1)
                    {
                        cout << "Smaller" << endl;
                    }
                    else 
                    {
                        cout << "Not smaller" << endl;
                    }
                }
                else if (option == 3)
                {
                    bool res = arr1 < arr4;
                    if (res == 1)
                    {
                        cout << "Smaller" << endl;
                    }
                    else 
                    {
                        cout << "Not smaller" << endl;
                    }
                }
                else if (option == 4)
                {
                    bool res = arr1 < arr5;
                    if (res == 1)
                    {
                        cout << "Smaller" << endl;
                    }
                    else 
                    {
                        cout << "Not smaller" << endl;
                    }
                }
                else if (option == 5)
                {
                    bool res = arr2 < arr3;
                    if (res == 1)
                    {
                        cout << "Smaller" << endl;
                    }
                    else 
                    {
                        cout << "Not smaller" << endl;
                    }
                }
                else if (option == 6)
                {
                    bool res = arr2 < arr4;
                    if (res == 1)
                    {
                        cout << "Smaller" << endl;
                    }
                    else 
                    {
                        cout << "Not smaller" << endl;
                    }
                }
                else if (option == 7)
                {
                    bool res = arr2 < arr5;
                    if (res == 1)
                    {
                        cout << "Smaller" << endl;
                    }
                    else 
                    {
                        cout << "Not smaller" << endl;
                    }
                }
                else if (option == 8)
                {
                    bool res = arr3 < arr4;
                    if (res == 1)
                    {
                        cout << "Smaller" << endl;
                    }
                    else 
                    {
                        cout << "Not smaller" << endl;
                    }
                }
                else if (option == 9)
                {
                    bool res = arr3 < arr5;
                    if (res == 1)
                    {
                        cout << "Smaller" << endl;
                    }
                    else 
                    {
                        cout << "Not smaller" << endl;
                    }
                }
                else if (option == 10)
                {
                    bool res = arr4 < arr5;
                    if (res == 1)
                    {
                        cout << "Smaller" << endl;
                    }
                    else 
                    {
                        cout << "Not smaller" << endl;
                    }
                }
                else 
                {
                    cout << "Incorrect option!";
                    continue;
                }
                continue;
            case 8:
                cout << "Enter array number: " << endl;
                
                cin >> arrayNumber;
                cout << "Enter position: " << endl;
                
                cin >> position;
                if (arrayNumber == 1)
                {
                    cout << arr1[position] <<endl;
                }
                else if (arrayNumber == 2)
                {
                    cout << arr2[position] <<endl;
                }
                else if (arrayNumber == 3)
                {
                    cout << arr3[position] <<endl;
                }
                else if (arrayNumber == 4)
                {
                    cout << arr4[position] <<endl;
                }
                else if (arrayNumber == 5)
                {
                    cout << arr5[position] <<endl;
                }
                else 
                {
                    cout << "Maximum array number is 5!";
                    continue;
                }


                continue;
            case 9:
                cout << "Enter array number: " << endl;

                cin >> arrayNumber;
                if (arrayNumber == 1)
                {
                    cout << arr1.empty() <<endl;
                }
                else if (arrayNumber == 2)
                {
                    cout << arr2.empty() <<endl;
                }
                else if (arrayNumber == 3)
                {
                    cout << arr3.empty() <<endl;
                }
                else if (arrayNumber == 4)
                {
                    cout << arr4.empty() <<endl;
                }
                else if (arrayNumber == 5)
                {
                    cout << arr5.empty() <<endl;
                }
                else 
                {
                    cout << "Maximum array number is 5!";
                    continue;
                }


                continue;
            case 10:
                cout << "Enter array number: " << endl;

                cin >> arrayNumber;
                if (arrayNumber == 1)
                {
                    cout << arr1.size() <<endl;
                }
                else if (arrayNumber == 2)
                {
                    cout << arr2.size() <<endl;
                }
                else if (arrayNumber == 3)
                {
                    cout << arr3.size() <<endl;
                }
                else if (arrayNumber == 4)
                {
                    cout << arr4.size() <<endl;
                }
                else if (arrayNumber == 5)
                {
                    cout << arr5.size() <<endl;
                }
                else 
                {
                    cout << "Maximum array number is 5!";
                    continue;
                }


                continue;
            case 11:
                cout << "Enter array number: " << endl;

                cin >> arrayNumber;
                if (arrayNumber == 1)
                {
                    cout << arr1.front() <<endl;
                }
                else if (arrayNumber == 2)
                {
                    cout << arr2.front() <<endl;
                }
                else if (arrayNumber == 3)
                {
                    cout << arr3.front() <<endl;
                }
                else if (arrayNumber == 4)
                {
                    cout << arr4.front() <<endl;
                }
                else if (arrayNumber == 5)
                {
                    cout << arr5.front() <<endl;
                }
                else 
                {
                    cout << "Maximum array number is 5!";
                    continue;
                }


                continue;
            case 12:
                cout << "Enter array number: " << endl;

                cin >> arrayNumber;
                if (arrayNumber == 1)
                {
                    cout << arr1.back() <<endl;
                }
                else if (arrayNumber == 2)
                {
                    cout << arr2.back() <<endl;
                }
                else if (arrayNumber == 3)
                {
                    cout << arr3.back() <<endl;
                }
                else if (arrayNumber == 4)
                {
                    cout << arr4.back() <<endl;
                }
                else if (arrayNumber == 5)
                {
                    cout << arr5.back() <<endl;
                }
                else 
                {
                    cout << "Maximum array number is 5!";
                    continue;
                }


                continue;
            case 13:
                cout << "Enter array number: " << endl;

                cin >> arrayNumber;
                if (arrayNumber == 1)
                {
                    cout << arr1 <<endl;
                }
                else if (arrayNumber == 2)
                {
                    cout << arr2 <<endl;
                }
                else if (arrayNumber == 3)
                {
                    cout << arr3 <<endl;
                }
                else if (arrayNumber == 4)
                {
                    cout << arr4 <<endl;
                }
                else if (arrayNumber == 5)
                {
                    cout << arr5 <<endl;
                }
                else 
                {
                    cout << "Maximum array number is 5!";
                    continue;
                }


                continue;
            case 14:
                /*cout << "Enter array size:" << endl;
                size_t n;
                cin >> n;
                if (arraysCount == 0)
                {
                    MyArray<int, n> arr1;
                    arraysCount++;
                }
                else if (arraysCount == 1)
                {
                    MyArray<int, n> arr2;
                    arraysCount++;
                }
                else if (arraysCount == 2)
                {
                    MyArray<int, n> arr3;
                    arraysCount++;
                }
                else if (arraysCount == 3)
                {
                    MyArray<int, n> arr4;
                    arraysCount++;
                }
                else if (arraysCount == 4)
                {
                    MyArray<int, n> arr5;
                    arraysCount++;
                }
                else
                {
                    cout << "Maximum arrays count is 5!";
                    continue;
                }*/
                
                
                continue;
            case 15:
                return 0;
            default:
                cout << "Incorrect number!" << endl;
                continue;
        }
        
    }
    
    return 0;
}
