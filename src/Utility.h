#ifndef __UTILITY_H__
#define __UTILITY_H__

namespace MyTinySTL
{   
    template<class T>
    void swap(T& a, T& b)
    {
        T temp = a;
        a = b;
        b = temp;
    }

    template<class T1, class T2>
    struct pair
    {
    public:
        typedef T1 first_type;
        typedef T2 second_type;
    
    // 数据成员
    public:
        T1 first;
        T2 second;

    // 初始化函数
    public:
        // 默认初始化函数
        pair(){};
        // 拷贝构造函数 
        template<class U, class V>
        pair(const pair<U,V> &pr);
        pair& operator= (const pair& pr);
        pair(const first_type& a,const second_type& b);
        void swap(const pair& pr);

    // 字典比较函数
    public:
        template<class T1, class T2>
        friend bool operator==(const pair<T1, T2>& lhs, const pair<T1,T2>& rhs);
        
        template<class T1, class T2>
        friend bool operator!=(const pair<T1, T2>& lhs, const pair<T1,T2>& rhs);
        
        template<class T1, class T2>
        friend bool operator>(const pair<T1, T2>& lhs, const pair<T1,T2>& rhs);
        
        template<class T1, class T2>
        friend bool operator<(const pair<T1, T2>& lhs, const pair<T1,T2>& rhs);

        template<class T1, class T2>
        friend bool operator>=(const pair<T1, T2>& lhs, const pair<T1,T2>& rhs);
        
        template<class T1, class T2>
        friend bool operator<=(const pair<T1, T2>& lhs, const pair<T1,T2>& rhs);
    };

    template<class T1, class T2>
    template<class U, class V>
    pair<T1, T2>::pair(const pair<U,V> &pr): first(pr.first), second(pr.second){};

    template<class T1, class T2>
    pair<T1, T2>::pair(const first_type& a, const second_type& b):first(a), second(b){};

    template<class T1, class T2>
    pair<T1, T2>& pair<T1,T2>::operator= (const pair<T1, T2>& pr)
    {
        if (this != &pr)
        {
            first = pr.first;
            second = pr.second;
        }
        return *this;
    }

    template<class T1, class T2>
    void pair<T1, T2>::swap(const pair<T1, T2>& pr)
    {
        MyTinySTL::swap(this->first, pr.first);
        MyTinySTL::swap(this->second, pr.second);
    }

    template<class T1, class T2>
    bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return lhs->first == rhs->second && lhs->second == rhs->second;
    }

    template<class T1, class T2>
    bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return !(lhs == rhs);
    }

    template<class T1, class T2>
    bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return lhs.first < rhs.first || (!(lhs.first < rhs.first) && lhs.second < rhs.second);
    }

    template<class T1, class T2>
    bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return !(rhs < lhs);
    }

    template<class T1, class T2>
    bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return rhs < lhs;
    }

    template<class T1, class T2>
    bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return !(lhs < rhs);
    }

    template<class U, class V>
    pair<U, V> make_pair(const U & a, const V& b)
    {
        return pair<U,V>(a, b);
    }
    
}


#endif