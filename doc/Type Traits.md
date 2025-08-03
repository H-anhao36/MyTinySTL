# Type Traits

## 简介

​	Type Traits翻译为中文是类型特征，字面上的意思是将一些类型（int, float, struct xxx等）加上特征，用于模板元编程进行一些特化操作，例如在静态方法中获取某个类型的属性，并对其进行判断，以便走不同的处理方法。这类操作主要是在编译期完成的。



## 工作原理和使用

标准库里的type traits位于头文件里的`<type_traits>`中，这些type traits主要可以有两种用途。

##### 类型查询（type queries）

​	这些 traits 用于查询某种类型的特性，通过这些信息做出进一步的决策。

```c++
#include <type_traits>
#include <iostream>

template <typename T>
void checktype() {
    if (std::is_integral<T>::value) {
        std::cout << "'T' is an integral type.\n";
    }
    else
    {
        std::cout << "`T` is not an integral type.\n";
    }
}

int main() {
    checkType<int>();       // 输出：`T` is an integral type.
    checkType<double>();    // 输出：`T` is not an integral type.
    return 0;
}
```

##### 类型转换（Type Transformations）

​	type traits 还提供了对类型进行变换的能力，称为类型变换（Type Transformations）。常见的类型变换工具包括 `std::remove_const`、`std::add_pointer`、`std::decay` 等.

```c++
#include <type_traits>
#include <iostream>

template <typename T>
void printType() {
    using NonConstT = typename std::remove_const<T>::type;
    std::cout << "Type after removing const.\n";
}

int main() {
    printType<const int>();  // 输出：Type after removing const.
    return 0;
}
```



​	更多使用的还是类型查询的功能。通过和`std::enable_if`组合使用来进一步扩展模板类的多态。

```c++
#include <type_traits>
#include <iostream>

template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type process(T value) {
    std::cout << "Processing integral value: " << value << "\n";
}

int main() {
    process(5);        // 输出：Processing integral value: 5
    // process(5.5);   // 编译错误，浮点类型无法调用此函数
    return 0;
}
```

