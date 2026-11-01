#include <iostream>
#include <memory>
#include <math.h>
using std::endl, std::cout;

class DArray{      //dynamic array 
    enum {
        max_length = 50,
        resize_factor=2,
        start_length=8,
        error_val=999
    };

    size_t length{0};
    size_t capacity{0};
    int* data{nullptr};

    class Item{
        DArray* current{nullptr};
        int index {-1};
        public:
            Item(DArray* p, int i):current(p), index(i){}
            //will work when something is written into array
            int operator = (int right);
            //will work when something is read from array     
            operator int () const;    //operator of class transformation to int
    };

    void _resize_array(int new_size);


    public:
        DArray() : length(0), capacity(start_length), data(new int[capacity]){}
        DArray(const DArray& other) : length(other.length), capacity(other.capacity), data(new int[capacity]){ 
            for(size_t i=0; i<length; ++i)
                data[i]=other.data[i];
        }
        ~DArray(){delete[] data;}

        int size() const {return length;}
        int capacity_ar() const { return capacity;}
        const int* get_data()const {return data;}
        void push_in(int value);

        const DArray& operator=(const DArray& other);

        Item operator [](int index){
            return Item(this,index);
        }
};

void DArray::push_in(int value){
    if(length>=capacity)
        _resize_array(capacity*resize_factor);

    if(length <capacity)
        data[length++]=value;
}
void DArray::_resize_array(int new_size){
    if(new_size>capacity){
        while (new_size>=capacity){
            capacity*=resize_factor;
            if(capacity>=max_length){
                capacity=max_length;
                break;
            }
        }
        int* new_data = new int[capacity];
        for(size_t i=0; i<length; ++i)
            new_data[i]=data[i];
        
        delete [] data;
        data = new_data;
    }
}
const DArray& DArray::operator=(const DArray& other)
{
    if(this != &other){
        delete [] data;
        length=other.length;
        capacity=other.capacity;
        data=new int[capacity];
        for(size_t i=0; i<length; ++i)
            data[i]=other.data[i];
    }
    return *this;
};

int DArray::Item::operator = (int right){
    if (index>=max_length || index<0)
        return right;
    if( index>=current->capacity)
        current->_resize_array(index+1);
    for (size_t i =current->length;i<index;i++ )
        current->data[i]=0;
    current->data[index]=right;
    if(index>=current->length)
        current->length=index+1;
    return right;           //this is needed to constructions like: a=b=c; - will work
}
DArray::Item::operator int () const{
    if (index>=current->length || index<0)
        return error_val;
    return current->data[index];
}

int main(){
    DArray ar1;
    for(int i=0; i<10;i++)
        ar1.push_in((i+1)*M_PI);

    ar1[25]=777;
    int v=ar1[25];

    cout<<v<<endl;
    for(int i=0; i<26;i++)
        cout<<ar1[i]<<" ";
    cout<<endl;
    cout<<ar1[255]<<endl;       //error code

    return 0;
} 