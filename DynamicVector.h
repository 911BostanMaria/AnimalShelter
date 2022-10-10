#pragma once

template <class T>
class DynamicVector{
private:
    unsigned int capacity{};
    void resize();
    T *data;

public:
    unsigned int size{};
    explicit DynamicVector(unsigned int capacity = 100);
    DynamicVector& operator=(const DynamicVector &v);
    ~DynamicVector();
    unsigned int getCapacity() const {return this -> capacity;}
    unsigned int getSize() const {return this -> size;}
    void addElement(const T &e);
    void removeElement(unsigned int index);
    T & operator [](unsigned int index);
};

template<class T>
void DynamicVector<T>::resize() {
    unsigned int oldCapacity = this -> capacity;
    this -> capacity = this -> capacity * 2;
    T *newData = new T[this -> capacity];
    for(int i = 0; i < oldCapacity; i++)
        newData[i] = this -> data[i];
    delete [] this -> data;
    this -> data = newData;
}

template<class T>
DynamicVector<T>::DynamicVector(unsigned int capacity) {
    this -> capacity = capacity;
    this -> size = 0;
    this -> data = new T[capacity];
}

template<class T>
DynamicVector<T> &DynamicVector<T>::operator=(const DynamicVector<T> &v) {
    if(this == &v)
        return *this;
    this -> size = v.size;
    this -> capacity = v.capacity;
    for(int i = 0; i < this -> size; i++)
        this -> data[i] = v.data[i];
    return *this;
}

template<class T>
DynamicVector<T>::~DynamicVector() {
    delete [] this -> data;
}

template<class T>
void DynamicVector<T>::addElement(const T &e) {
    if(this -> size == this -> capacity)
        this -> resize();
    this -> data[this -> size++] = e;
}

template<class T>
void DynamicVector<T>::removeElement(unsigned int index) {
    for(unsigned int i = index; i < this -> size - 1; i++)
        this -> data[i] = this -> data[i + 1];
    this -> size--;

}

template<class T>
T &DynamicVector<T>::operator[](unsigned int index) {
    return this -> data[index];
}




