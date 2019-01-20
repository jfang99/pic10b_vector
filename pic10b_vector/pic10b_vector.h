#include <iostream>   // std::ostream, std::cout
#include<string>

namespace Pic10b{
    using std::string;
    using std::cout;
    using std::ostream;
    using std::endl;
    
    template<typename T>
    class vector{
    private:
        T* the_data;
        size_t the_size;
        size_t the_capacity;
        
        static const int INIT_CAP = 10;
        
        
    public:
        // The big 4
        vector();
        vector( const vector& );
        vector& operator=( const vector& );
        ~vector();
        
        // Other members [public]
        bool empty() const;
        size_t size() const;
        size_t capacity() const;
        T front() const;
        T back() const;
        T at( size_t index ) const;
        T& operator[]( size_t index );
        T operator[]( size_t index ) const;
        void dump_data_to(ostream& out ) const;
        void dump_data() const;
        void push_back( T new_value );
        void pop_back();
        
        
        //other member functions:
        //int types:
        vector operator*(int a);
        
        //for string:
        vector operator* (string str);
        
        //double types:
        vector operator* (double a);
        vector operator+(const vector<T>& vec);
        vector& operator+=(const vector<T>& vec);
        T operator*(const vector<T>& vec);
        
        //overload bool type operator for int
        bool operator<(const vector<T>& vec);
        bool operator<=(const vector<T>& vec);
        bool operator>(const vector<T>& vec);
        bool operator>=(const vector<T>& vec);
        bool operator==(const vector<T>& vec);
        bool operator!=(const vector<T>& vec);
    private:
        //Other members [private]
        void reserve( size_t new_capacity );
        
    }; // end Pic10b::vector
    
    
    /** ************************* THE BIG 4 ************************* **/
    template<typename T>
    vector<T>::vector()
    : the_data(nullptr), the_size(0), the_capacity(INIT_CAP) {
        cout<<"xxxxxxxxxDefault constructor called"<<endl;
        the_data = new T[the_capacity];
    }
    
    template<typename T>
    vector<T>::vector( const vector& source )
    : the_data(nullptr), the_size(source.the_size),
    the_capacity(source.the_capacity) {
        cout<<"xxxxxxxxxxCopy constructor called"<<endl;
        the_data = new T[the_capacity];
        
        // Deep copy of internal array
        for ( int i = 0 ; i < the_size ; ++i ){
            the_data[i] = source.the_data[i];
        }
    }
    
    template<typename T>
    vector<T>& vector<T>::operator=( const vector& rhs ) {
        cout<<"xxxxxxxxxxxAssignment operator called"<<endl;
        if ( this != &rhs ) {     // Self-assignment?
            // Release old memory and request more
            delete[] the_data;
            the_data = new T[rhs.the_capacity];
            
            // Shallow copy non-pointers
            the_size = rhs.the_size;
            the_capacity = rhs.the_capacity;
            
            // Deep copy internal array
            for ( int i = 0 ; i < the_size ; ++i )
                the_data[i] = rhs.the_data[i];
        }
        return *this;
    }
    
    template<typename T>
    vector<T>::~vector(){
        cout<<"xxxxxxxxxdestructor called"<<endl;
        delete[] the_data;
    }
    
    /** *********************** OTHER MEMBERS *********************** **/
    template<typename T>
    bool vector<T>::empty() const {
        return the_size == 0;
    }
    
    template<typename T>
    size_t vector<T>::size() const {
        return the_size;
    }
    
    template<typename T>
    size_t vector<T>::capacity() const {
        return the_capacity;
    }
    
    template<typename T>
    T vector<T>::front() const {
        return *the_data;
    }
    
    template<typename T>
    T vector<T>::back() const {
        return *(the_data + the_size - 1);
    }
    
    template<typename T>
   T vector<T>::at( size_t index ) const {
        if ( index < the_size )
            return the_data[index];
        return the_data[0];
    }
    
    template<typename T>
    T& vector<T>::operator[]( size_t index ){
        return the_data[index];
    }
    
    template<typename T>
    T vector<T>::operator[]( size_t index ) const {
        return the_data[index];
    }
    
    template<typename T>
    void vector<T>::dump_data_to( ostream& out ) const {
        out << "Vector (dump): ";
        for ( size_t i = 0 ; i < the_capacity ; ++i )
            out << the_data[i] << ' ';
        out << '\n';
    }
    
    template<typename T>
    void vector<T>::dump_data() const {
        dump_data_to( cout );
    }
    
    template<typename T>
    void vector<T>::push_back( T new_value ){
        if ( the_size == the_capacity )
            reserve( the_capacity + 1 );     // `the_data` is reassigned
        
        the_data[the_size++] = new_value;
    }
    
    // This implementation does not shrink the vector (ever)
    template<typename T>
    void vector<T>::pop_back(){
        if ( the_size > 0 )
            --the_size;
    }
    
    
   template<typename T>
    void vector<T>::reserve( size_t new_capacity ){
        if ( new_capacity > the_capacity ) {
            if ( new_capacity <= 2 * the_capacity )
                new_capacity = 2 * the_capacity;
            
            T* old_location = the_data;
            
            the_data = new T[new_capacity];
            the_capacity = new_capacity;
            
            for ( size_t i = 0 ; i < the_size ; ++i )
                the_data[i] = old_location[i];
            
            delete old_location;
        }
    }
    
    
    
    //integer types:
    template<typename T>
    vector<T> vector<T>::operator*(int a) {
        vector vec(*this);
        for (int i = 0; i < vec.size(); ++i) {
            vec[i] = vec[i] * a;
        }
        return vec;
    }
    
    //string type:
    template<typename T>
    vector<T> vector<T>::operator*(string str){
        vector<T> copy(*this);
        for(int i=0; i<the_size; ++i){
            copy[i]=copy[i]+" "+str;
        }
        return copy;
    }
    
    //double type:
    template<typename T>
    vector<T> vector<T>::operator*(double a){
        vector<T> copy(*this);
        for(int i=0; i<the_size; ++i){
            copy[i]=copy[i]*a;
        }
        return copy;
    }
    
    template<typename T>
    vector<T> vector<T>::operator+(const vector<T>& vec){
        vector<T> copy(*this);
        for(int i=0; i<the_size;i++){
            copy[i] = copy[i]+vec[i];
            
        }
        return copy;
    }
    
    template<typename T>
    vector<T>& vector<T>::operator+=(const vector<T>& vec) {
        for (int i = 0; i < vec.size(); ++i) {
            (*this)[i] = (*this)[i] + vec[i];
        }
        return (*this);
    }
    
    
    template<typename T>
    T vector<T>::operator*(const vector<T>& vec) {
        T answer = 0;
        for (int i = 0; i < vec.size(); ++i) {
            answer = answer + ((*this)[i] * vec[i]);
        }
        return answer;
    }
    
    
    //bool types:
    template<typename T>
    bool vector<T>::operator<(const vector<T>& vec){
        T size = 0.0;
        for(int i=0; i<vec.size();i++){
            size=size+vec[i]*vec[i];
        }
        T size_this=0.0;
        for(int i=0; i<(*this).size();i++){
            size_this=size_this+(*this)[i]*(*this)[i];
        }
        if(size_this<size)return true;
        else return false;
    }
    
    template<typename T>
    bool vector<T>::operator<=(const vector<T>& vec){
        T size = 0.0;
        for(int i=0; i<vec.size();i++){
            size=size+vec[i]*vec[i];
        }
        T size_this=0.0;
        for(int i=0; i<(*this).size();i++){
            size_this=size_this+(*this)[i]*(*this)[i];
        }
        if(size_this<=size)return true;
        else return false;
    }
    
    template<typename T>
    bool vector<T>::operator>(const vector<T>& vec){
        T size = 0.0;
        for(int i=0; i<vec.size();i++){
            size=size+vec[i]*vec[i];
        }
        T size_this=0.0;
        for(int i=0; i<(*this).size();i++){
            size_this=size_this+(*this)[i]*(*this)[i];
        }
        if(size_this>size)return true;
        else return false;
    }
    
    template<typename T>
    bool vector<T>::operator>=(const vector<T>& vec){
        T size = 0.0;
        for(int i=0; i<vec.size();i++){
            size=size+vec[i]*vec[i];
        }
        T size_this=0.0;
        for(int i=0; i<(*this).size();i++){
            size_this=size_this+(*this)[i]*(*this)[i];
        }
        if(size_this>=size)return true;
        else return false;
    }
    
    template<typename T>
    bool vector<T>::operator==(const vector<T>& vec) {
        if (the_size != vec.size()) return false;
        else {
            for (int i = 0; i < vec.size();++i) {
                if ((*this)[i] != vec[i]) {
                    return false;
                }
            }
            return true;
        }
    }
    
    template<typename T>
    bool vector<T>::operator!=(const vector<T>& vec) {
        if (the_size != vec.size()) return true;
        else {
            for (int i = 0; i < vec.size(); ++i) {
                if ((*this)[i] != vec[i]) {
                    return true;
                }
            }
            return false;
        }
    }
    
    
} // end Pic10b namespace




/** ************************ OTHER FUNCTIONS ************************ **/

using Pic10b::vector;
using std::string;
using std::ostream;
using std::cout;

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v ){
    for ( size_t i = 0 ; i < v.size() ; ++i )
        out << v[i] << ' ';
    return out;
}

template<typename T>
void print_vector( const vector<T>& v ){
    if ( v.empty() )
        cout << "Vector is empty\n";
    else
        cout << "Vector (contents): " << v << '\n' ;
}


//my other non-member functions:
template<typename T>
vector<T> operator*(int a, const vector<T>& vec) {
    vector<T> copy(vec);
    for (int i = 0; i < vec.size(); ++i) {
        copy[i] = copy[i] * a;
    }
    return copy;
}


template<typename T>
vector<T> operator*( string str, const vector<T>& vec){
    vector<T> copy(vec);
    for(int i=0; i<vec.size(); ++i){
        copy[i] = str + " " + copy[i];
    }
    return copy;
}
