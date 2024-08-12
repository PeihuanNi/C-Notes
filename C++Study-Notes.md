# :notebook_with_decorative_cover: C++ Study Notes  Learning from [RUNOOB](https://www.runoob.com/cplusplus/[C++ 教程 | 菜鸟教程](https://www.runoob.com/cplusplus/))

## 数据类型

### 数据类型都是常见的`int`，`char`，`float`之类的。`typedef`可以类似于c语言的`define`，比如`int8`数据类型在c++中的定义是：`typedef signed char int8_k;`，这就会导致，以`int8_k`存下来的数据，实际上是字符串型的。

```c++
#include <iostream>

using namespace std;

int main(){
    int8_t a = 65;
    int8_t b = 1;
    signed char a_c = 65;
    signed char b_c = 1;
    int8_t c = a + b;
    signed char c_c = a_c + b_c;
    cout << c << "," << c_c << endl;
    return 0;
}
```

输出是`B,B`

所以要想把`c`当作`int`型输出，需要做这项修改

```c++
cout << static_cast<int>(c) << "," << c_c << endl;
```

输出`66,B`

`static_cast<datatype>(var)`是静态数据类型转换

还有动态类型数据转换

```c++
class Base {};
class Derived : public Base {};
Base* ptr_base = new Derived;
Derived* ptr_derived = dynamic_cast<Derived*>(ptr_base); // 将基类指针转换为派生类指针
```

- [ ] 这个动态类型类型数据转换还没搞明白干啥的

___

### 有一个比较特殊的数据类型`enum`，称之为**枚举类型**，他的作用是把一个数据可能出现的值全部枚举出来，定义的格式是这样的

```c++
enum 枚举名{ 
     标识符[=整型常数], 
     标识符[=整型常数], 
... 
    标识符[=整型常数]
} 枚举变量;
```

如果枚举没有初始化, 即省掉``=整型常数``时, 则从第一个标识符开始，枚举变量自动赋值为0，每个自动加1

```c++
enum color { red, green, blue } c;
c = blue;
```

这时`cout << c << endl`会输出`2`

如果

```c++
enum color { red, green=5, blue } a, c;
a = red;
c = blue;
out << a << ',' << c << endl;
```

就会输出`0, 6`，就是一开始还是0，但是`green=5`，所以`blue += 1`就输出`6`了

## 变量类型

### 变量声明

`extern`是一个变量声明的关键词，他向编译器保证他声明的变量以给定的名称和类型存在。这样在编译的时候，不需要知道这个变量具体细节的情况下也可以完成编译

- `file1.cpp`

  ```c++
  #include <iostream>
  
  using namespace std;
  
  extern int a;
  
  int main(){
      cout << a << endl;
      return 0;
  }
  ```
- `file2.cpp`
  
  ```c++
  #include <iostream>
  
  using namespace std;
  
  int a = 1;
  ```

把两个文件一起编译`g++ -o extern file1.cpp file2.cpp`，就会输出1

如果只编译``g++ -o extern file1.cpp`，那么就会报错

```shell
Undefined symbols for architecture arm64:
  "_a", referenced from:
      _main in vartype-e82412.o
ld: symbol(s) not found for architecture arm64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
```

## C++变量作用域

一般有三个地方可以声明变量

- 在函数或一个代码块内部声明的变量，称为**局部变量**。
- 在函数参数的定义中声明的变量，称为**形式参数**。
- 在所有函数外部声明的变量，称为**全局变量**。

其中在局部变量里面还有几种作用域形式

- **局部作用域**：在函数内部声明的变量具有局部作用域，它们只能在函数内部访问。局部变量在函数每次被调用时被创建，在函数执行完后被销毁。
- **块作用域**：在代码块内部声明的变量具有块作用域，它们只能在代码块内部访问。块作用域变量在代码块每次被执行时被创建，在代码块执行完后被销毁。
- **类作用域**：在类内部声明的变量具有类作用域，它们可以被类的所有成员函数访问。类作用域变量的生命周期与类的生命周期相同。

块作用域不太熟悉，写代码做个实验

```c++
#include <iostream>

int main(){
    int a = 1;
    {
        int a = 2;
        std::cout << a << std::endl;
    }
    std::cout << a << std::endl;
}
```

输出

```shell
2
1
```

也就是说，在`{}`（即代码块）里的变量也是局部的，和外面的变量定义互不影响

当全局变量和局部变量定义的情况下，全变量不影响局部变量

```c++
#include <iostream>

int b = 3;
int main(){
    int a = 1;
    {
        int a = 2;
        int b = 2;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
    }
    std::cout << b << std::endl;
    std::cout << a << std::endl;
}
```

输出

```shell
2
2
3
1
```

___

```c++
#include <iostream>

int b = 3;
int main(){
    {
        std::cout << b << std::endl;
    }
    std::cout << b << std::endl;
}
```

输出

```shell
3
3
```

- **注意，局部变量声明时不会自动初始化，全局变量才会自动初始化**

- [ ] **目前还没学到类是什么，先扔一份待办**

## 修饰符类型

### 类型限定符
| 类型 | 描述 |
| ------------ | :----------------------------------------------------------: |
| volatile    | 修饰符 **volatile** 告诉该变量的值可能会被程序以外的因素改变，如硬件或其他线程。。 |
| const        | **const ** 定义常量，表示该变量的值不能被修改。              |
| restrict     | 由 **restrict** 修饰的指针是唯一一种访问它所指向的对象的方式 |
| mutable      | 表示类中的成员变量可以在 const 成员函数中被修改。            |
| static       | 用于定义静态变量，表示该变量的作用域仅限于**当前文件或当前函数内**，不会被其他文件或函数访问。 |
| ~~register~~ | ~~用于定义寄存器变量，表示该变量被频繁使用，可以存储在CPU的寄存器中，以提高程序的运行效率。~~（已被弃用，因为现代编译器会自动决定哪个变量放在cpu寄存器中） |

- [x] **~~mutable这条没看懂~~(下面是解释)**

```c++
class Example {
public:
    int get_value() const {
        return value_; // const 关键字表示该成员函数不会修改对象中的数据成员
    }
    void set_value(int value) const {
        value_ = value; // mutable 关键字允许在 const 成员函数中修改成员变量
    }
private:
    mutable int value_;
};
// 意思就是，用const修饰的函数时说明这个函数不会修改这个变量
// 而mutable关键字声明的函数允许在const函数里修改变量
```

## 运算符

- c++支持按位运算
- `&`给出变量的地址（同时也是按位与，这个编译器会自动识别，因为一个是一元一个是二元操作符），`*`会指向一个变量，这点和c语言是一样的

## 循环和判断语句



- 循环控制语句 
  | 语句 | 描述 |
  | ------------- | :----------------------------------------------------------: |
  | break 语句    | 终止 **loop** 或 **switch** 语句，程序流将继续执行紧接着 loop 或 switch 的下一条语句。 |
  | continue 语句 | 引起循环跳过主体的剩余部分，立即重新开始测试条件。           |


- `switch case`语句，具体写法是这样的

  ```c++
  switch(expression){
      case constant-expression:
         statement(s);
         break; // 可选的
      case constant-expression:
         statement(s);
         break; // 可选的
    
      // 您可以有任意数量的 case 语句
      default: // 可选的
         statement(s);
  }
  ```

## C++函数

### 函数声明

函数**声明**会告诉编译器函数名称及如何调用函数。函数的实际主体**可以单独定义**。

函数声明包括以下几个部分：

```
return_type function_name( parameter list );
```

针对上面定义的函数 `max()`，以下是函数声明：

```
int max(int num1, int num2);
```

在函数声明中，**参数的名称并不重要**，只有参数的类型是必需的，因此下面也是有效的声明：

```
int max(int, int);
```

当在一个源文件中定义函数且在另一个文件中调用函数时，函数声明是必需的。在这种情况下，应该在调用函数的文件顶部声明函数。**（似乎加不加extern都可以）**

### 函数参数

| 调用类型 |                             描述                             |
| :------- | :----------------------------------------------------------: |
| 传值调用 | 该方法把参数的实际值赋值给函数的形式参数。在这种情况下，**修改函数内的形式参数对实际参数没有影响**。 |
| 指针调用 | 该方法把参数的地址赋值给形式参数。在函数内，该地址用于访问调用中要用到的实际参数。这意味着，**修改形式参数会影响实际参数**。 |
| 引用调用 | 该方法把参数的引用赋值给形式参数。在函数内，该引用用于访问调用中要用到的实际参数。这意味着，**修改形式参数会影响实际参数**。 |

- [x] ~~**引用调用不太懂，留一个待办**~~ [引用](#13)

___

**C++同样支持像python那样的形参的默认值**，比如在函数定义时有

```c++
void func(int a, int b=20) {expressions};
```
那么在使用时
```c++
func(a);
```
就可以了，如果还是使用
```c++
func(a, b)
```
那么还是会按照`b`的实际值来。**注意**，在**声明**时再给赋默认值也可以。

## C++数字
### 数学运算库`cmath`

| 序号 | 函数 & 描述                                                  |
| ---- | :----------------------------------------------------------- |
| 1    | **double cos(double);** 该函数返回弧度角（double 型）的余弦。 |
| 2    | **double sin(double);** 该函数返回弧度角（double 型）的正弦。 |
| 3    | **double tan(double);** 该函数返回弧度角（double 型）的正切。 |
| 4    | **double log(double);** 该函数返回参数的自然对数。           |
| 5    | **double pow(double, double);** 假设第一个参数为 x，第二个参数为 y，则该函数返回 x 的 y 次方。 |
| 6    | **double hypot(double, double);** 该函数返回两个参数的平方总和的平方根，也就是说，参数为一个直角三角形的两个直角边，函数会返回斜边的长度。 |
| 7    | **double sqrt(double);** 该函数返回参数的平方根。            |
| 8    | **int abs(int);** 该函数返回整数的绝对值。                   |
| 9    | **double fabs(double);** 该函数返回任意一个浮点数的绝对值。  |
| 10   | **double floor(double);** 该函数返回一个小于或等于传入参数的最大整数。 |

经过测试，再调用这些函数时，他们的输入数据类型和返回数据类型都会自动识别出来，不一定就是doubule只能传入double，也可以传入int，int不一定输出int，也可以输出double

## 随机数

C++生成的是伪随机，有两个相关的函数

随机数相关的头文件是`# include <srdlib.h>`，或者`#include <cstdlib>`

- `void srand(unsigned int seed);`。他的作用是设置随机种子
- `int rand(void);`，即返回一个随机整数

如果不在`rand()`之前设置随机种子的话，那么每次程序运行时生成的随机数都是相同的，比如

```c++
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    for (int i=0; i<10; i++) cout << rand() << endl;
  	return 0;
}
```

每次程序运行的结果都是相同的：

```shell
16807
282475249
1622650073
984943658
1144108930
470211272
101027544
1457850878
1458777923
2007237709
```

一般想让每次运行时的随机数不同，会使用当前的系统时间来设置随机种子，比如：

```c++
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main(){
    srand(static_cast<uint>(time(NULL)));
  	// 还有一种强制类型转换的方法
  	// srand((unsigned) time(NULL));
    for (int i=0; i<10; i++){
        cout << rand() << endl;
    }
    return 0;
}
```

## C++数组

c++的数组和c语言的没什么区别，可以不用过于关注

**似乎数组最好是在初始化的时候才能方便的赋值，比如**

```c++
// 可行的写法是这样的,其他的数会被初始化为0
int var[50] = {0, 1, 2};
// 会报错的写法
int var[50];
var = {0, 1, 3};
```

这应该是因为在定义了之后，`var`就已经不再是一个简单的变量名了，而是一个**地址**，那么当然地址不能被修改了

## C++字符串

### C语言风格的字符串

字符串是一个使用`null ('\0')`结尾的字符数组：

```c++
char str[] = {'e', 'x' 'a', 'm', 'p', 'l', 'e', '\0'};
```
或者
```c++
char str[] = "example"
```

事实上，在现在的编译器中，结尾的`'\0'`并不重要，因为编译器会自动在字符串的结尾加上`'\0'`

下面是常用的字符串函数，需要`#include <cstring>`

| 函数 |  目的                                                  |
| ---- | :----------------------------------------------------------- |
|  `strcpy(s1,s2);`     |  复制字符串 s2 到字符串 s1。              |
|   `strcat(s1,s2);`    |  连接字符串 s2 到字符串 s1 的末尾。连接字符串也可以用 **+** 号，例如: `string str1 = "runoob"; string str2 = "google"; string str = str1 + str2;` |
|  `strlen(s1);`         |  返回字符串 s1 的长度。                       |
|  `strcmp(s1,s2);`     |  如果 s1 和 s2 是相同的，则返回 0；如果 s1<s2 则返回值小于 0；如果 s1>s2 则返回值大于 0。 |
|  `strchr(s1,ch);`     |  返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。 |
|   `strstr(s1,s2);`    |  返回一个指针，指向字符串 s1 中字符串 s2 的第一次出现的位置。 |

这个`strchr(s1,ch);`和`strstr(s1,s2);`还是挺有意思的，能省很多事

### C++的string类

`string`类支持上面提到的所有操作（不过用的不是上面的那些函数）

用一段简单的代码来举例

```c++
#include <iostream>
#include <string>
 
using namespace std;
 
int main ()
{
   string str1 = "runoob";
   string str2 = "google";
   string str3;
   int  len ;
 
   // 复制 str1 到 str3
   str3 = str1;
   cout << "str3 : " << str3 << endl;
 
   // 连接 str1 和 str2
   str3 = str1 + str2;
   cout << "str1 + str2 : " << str3 << endl;
 
   // 连接后，str3 的总长度
   len = str3.size();
   cout << "str3.size() :  " << len << endl;
 
   return 0;
}
```

`str1, str2, str3`都是`string`这个类的，他们都有类似`string.size()`的size对象，这点和python其实挺像的

## C++指针

使用`type *ptr_name`来声明一个名叫`ptr_name`的指向`type`类型数据的指针

`*addr`是取出地址的值，`&var`是获取值的地址

### 空指针

在初始化一个指针时，如果还不需要让这个指针直到某一个具体的地址，那么最好给这个指针初始化为`int *ptr = NULL;`。这样做的好处是，可以通过判断语句来看这个指针是不是一个有用的指针，比如：

```c++
if (ptr){
  expression1;
} else {
  expression2;
}
```

这样可以防止操作一个没有意义的指针。

总而言之初始化暂时用不到的指针为`NULL`是一个不错的编程习惯

### 指针和数组

```C++
int* ptr = NULL;
int var[50];
ptr = var;
```

那么`ptr`就指向`var`这个数组的初始地址

`*ptr[idx]`就等价于

## C++引用

引用变量是一个别名，也就是说，它是某个已存在变量的另一个名字。一旦把引用初始化为某个变量，就可以使用该引用名称或变量名称来指向变量。

`type& quote = var;`

引用和指针有几个区别：

- 没有空引用
- 这个引用一旦指向一个对象，就不能再指到另一个对象
- 创建时必须初始化

### 引用的作用

对比一下下面的两个代码

#### 代码1

```c++
#include <iostream>
using namespace std;
void swap(int& x, int& y);

int main(){
    int A = 200;
    int B = 100;
    swap(A, B);
    cout << A << ", " << B << endl;
    return 0;
}

//这种写法就相当于 int& x = A; int& y = B;
void swap(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}
```

输出`100, 200`

#### 代码2

```c++
#include <iostream>
using namespace std;
void swap(int x, int y);

int main(){
    int A = 200;
    int B = 100;
    swap(A, B);
    cout << A << ", " << B << endl;
    return 0;
}

void swap(int x, int y){
    int temp = x;
    x = y;
    y = temp;
}
```

输出`200, 100`

所以差别就在于，使用引用的写法（或者把地址传进去），也就是引用调用（传值调用）才能够改变原本的值，而直接传值调用，是没法改变原本的值的，因为他改变的只是形参的值

## C++的基本输入输出

### C++的标准输入输出

- `cout`，使用 `>>`
- `cin`，使用 `<<`
- `cerr`，标准错误流，非缓冲输出，即每个流插入到cerr中都会立即输出
- `clog`，标准日志流，缓冲输出，意思是每一个流插入到clog时都会先存储在缓冲区，直到缓冲区填满或刷新时才会输出

## C++结构体

### 结构体定义

```c++
struct type_name {
member_type1 member_name1;
member_type2 member_name2;
member_type3 member_name3;
...
...
} object_names;
```

举例

```c++
struct Books
{
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book;
```

### 访问结构成员

```c++
#include <iostream>
#include <cstring>

int main(){
    struct Books
    {
        char title[50];
        char author[50];
        int id; 
    };

    Books books;
    strcpy(books.title, "C++");
    strcpy(books.author, "runbbo");
    books.id = 0;

    std::cout << books.title << "\n" << books.author << "\n" << books.id << std::endl;
    return 0;
}
```

### 结构作为函数参数

```c++
#include <iostream>
#include <cstring>

void struct_func(struct Books books);// 这里的struct关键词不能省，否则编译器会报错error: unknown type name 'Books'

struct Books
    {
        char title[50];
        char author[50];
        int id; 
    };

int main(){
    Books books;
    books.id = 2;
    struct_func(books);
    return 0;
}

void struct_func(struct Books books){ //这里的struct关键词也同样不能省
    std::cout << books.id << std::endl;
}
```

### 指向结构体的指针

定义方法

```c++
struct StructName *struct_ptr;
```

使用举例

```c++
Books book1;
struct Books *book1_ptr = &book1;// 注意这个必须要有&，结构体和数组不一样
std::cout << book1_ptr->id << std::endl;//必须使用 -> 来用指针访问结构体的成员
```

### `typedef`关键字

```c++
#include <iostream>
#include <cstring>
// 使用typedef可以把这个结构体定义成一个新的数据类型，这样就不需要再写struct关键字了
typedef struct Books
    {
        char title[50];
        char author[50];
        int id; 
    }Books;

void struct_func(Books books);//跟之前的比较就能看出来这个不需要struct关键字了

int main(){
		Books books;
    books.id = 2;
    struct_func(books);
    return 0;
}

void struct_func(Books books){
    std::cout << books.id << std::endl;
}
```

## `vector`容器

C++ 中的 `vector` 是一种序列容器，可以在运行时动态地插入和删除元素。

`vector` 是基于数组的数据结构，但它可以自动管理内存，这意味着不需要手动分配和释放内存。

**基本特性:**

- **动态大小**：`vector` 的大小可以根据需要自动增长和缩小。
- **连续存储**：`vector` 中的元素在内存中是连续存储的，这使得访问元素非常快速。
- **可迭代**：`vector` 可以被迭代，可以使用循环（如 `for` 循环）来访问它的元素。
- **元素类型**：`vector` 可以存储任何类型的元素，包括内置类型、对象、指针等

`vector`在头文件**`vector`**中，**注意不是`cvector`！！！**

创建一个`vector`类型的变量：

```c++
std::vector<type> name;// 注意，vector是std空间中的元素，在使用时必须说明是在std空间中的
```

创建时指定初始大小和初始值：

```c++
std::vector<int> myVector(5); // 创建一个包含 5 个整数的 vector，每个值都为默认值（0）
std::vector<int> myVector(5, 10); // 创建一个包含 5 个整数的 vector，每个值都为 10
```

或：

```c++
std::vector<int> myVector; // 默认初始化一个空的 vector
std::vector<int> myVector = {1, 2, 3, 4}; // 初始化一个包含元素的 vector
```

### 添加元素

```c++
myVector.push_back(7); // 将整数 7 添加到 vector 的末尾
```

### 访问元素

直接加索引和调用at的方法都可以

```c++
int x = myVector[0]; // 获取第一个元素
int y = myVector.at(1); // 获取第二个元素
```

### 获取大小

```c++
int size = myVector.size(); // 获取 vector 中的元素数量
```

### 删除元素

```c++
myVector.erase(myVector.begin() + 2); // 删除第三个元素
```

### 清空`vector`

```c++
myVector.clear();
```

### 补充关于`vector.beign()`和`vector.end()`

`vector.begin()`和`vector.end()` 是 C++ 标准模板库（STL）中 std::vector 类的一个成员函数。它返回一个**迭代器**，指向 std::vector 容器中第一个元素。如果 vector 是空的，begin() 返回的迭代器与 end() 返回的迭代器相同。

**迭代器（Iterator）**是一种**类似于指针（不是指针）**的对象，它用于遍历容器中的元素。通过迭代器，你可以访问和操作容器中的元素，就像用指针操作数组元素一样。

```c++
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};//创建一个vector

    // 使用迭代器遍历 vector
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
      	// 注意it的类型是 std::vector<int>::iterator
      	// 在std::vector<int>：表示一个存储 int 类型元素的vector。
				// ::iterator：表示这个向量的迭代器类型。
        std::cout << *it << " ";  // *it 表示迭代器指向的元素
    }

    std::cout << std::endl;

    return 0;
}
```

C++11 引入了 auto 关键字，可以自动推导迭代器的类型：

```c++
for (auto it = numbers.begin(); it != number.end(); ++it){
  std::cout << *it << std::endl;
}
```

或者使用范围for循环

```c++
for (int num : numbers) {
  	// 这个意思就是说num在numbers里自动迭代
    std::cout << num << std::endl;
}
```

## C++类和对象

### 基本定义
举一个简单的例子：

```c++
#include <iostream>
 
using namespace std;
 
class Box{
   public:						 // 访问修饰符，确定成员的访问属性，分别有 public, private, protected
      double length;   // 长度
      double breadth;  // 宽度
      double height;   // 高度
      // 成员函数声明
      double get(void){
        return length * breadth * height;
      };

      void set( double len, double bre, double hei ){
        length = len;
        breadth = bre;
        height = hei;
      };
};

int main( )
{
   Box Box1;        // 声明 Box1，类型为 Box
   Box Box2;        // 声明 Box2，类型为 Box
   Box Box3;        // 声明 Box3，类型为 Box
   double volume = 0.0;     // 用于存储体积
 
   // box 1 详述
   Box1.height = 5.0; 
   Box1.length = 6.0; 
   Box1.breadth = 7.0;
 
   // box 2 详述
   Box2.height = 10.0;
   Box2.length = 12.0;
   Box2.breadth = 13.0;

   // box 3 详述
   Box3.set(16.0, 8.0, 12.0); 
   // box 1 的体积
   volume = Box1.height * Box1.length * Box1.breadth;
   cout << "Box1 的体积：" << volume <<endl;
 
   // box 2 的体积
   volume = Box2.height * Box2.length * Box2.breadth;
   cout << "Box2 的体积：" << volume <<endl;
 
 
   // box 3 的体积
   volume = Box3.get(); 
   cout << "Box3 的体积：" << volume <<endl;
   
   return 0;
}
```

**注意，private的成员和protected的成员不能使用直接成员访问运算符 (.) 来直接访问**

成员函数既可以在class类内定义，也可以在class外部单独使用范围解析运算符 `::`来定义

```c++
class Box{
  public:
  	double length;
  	double breadth;
  	double height;
  	double get(void);
  	void set(double len, double bre, double hei);
  private:
};

double Box::get(void){
		return length * breadth * height;
};

void Box::set( double len, double bre, double hei ){
    length = len;
    breadth = bre;
    height = hei;
};
```

### 类访问修饰符

数据封装可以防止函数直接访问类类型的内部成员。类成员的访问限制是通过在类主体内部对各个区域标记 **public、private、protected** 来指定的。关键字 **public、private、protected** 称为访问修饰符。

一个类可以有多个 public、protected 或 private 标记区域。每个标记区域在下一个标记区域开始之前或者在遇到类主体结束右括号之前都是有效的。**成员和类的默认访问修饰符是 private。**

```c++
class Base {
 
   public:
 
  // 公有成员
 
   protected:
 
  // 受保护成员
 
   private:
 
  // 私有成员
 
};
```

#### `public`

`public`的修饰符修饰的成员可以不使用任何成员函数来访问

```c++
#include <iostream>
 
using namespace std;
 
class Line
{
   public:
      double length;
      void setLength( double len );
      double getLength( void );
};
 
// 成员函数定义
double Line::getLength(void)
{
    return length ;
}
 
void Line::setLength( double len )
{
    length = len;
}
 
// 程序的主函数
int main( )
{
   Line line;
 
   // 设置长度
   line.setLength(6.0); 
   cout << "Length of line : " << line.getLength() <<endl;
 
   // 不使用成员函数设置长度
   line.length = 10.0; // OK: 因为 length 是公有的
   cout << "Length of line : " << line.length <<endl;
   return 0;
}
```

#### `private`

私有变量或者函数是不可访问的，一般来说会在`private`定义变量，在`public`定义函数这样在外部也可以调用这些函数

```c++
#include <iostream>
 
using namespace std;
 
class Box
{
   public:
      double length;
      void setWidth( double wid );
      double getWidth( void );
 
   private:
      double width;
};
 
// 成员函数定义
double Box::getWidth(void)
{
    return width ;
}
 
void Box::setWidth( double wid )
{
    width = wid;
}
 
// 程序的主函数
int main( )
{
   Box box;
 
   // 不使用成员函数设置长度
   box.length = 10.0; // OK: 因为 length 是公有的
   cout << "Length of box : " << box.length <<endl;
 
   // 不使用成员函数设置宽度
   // box.width = 10.0; // Error: 因为 width 是私有的，编译器会报错
   box.setWidth(10.0);  // 使用成员函数设置宽度
   cout << "Width of box : " << box.getWidth() <<endl;
 
   return 0;
}
```

#### `protected`

`protected`和`private`基本相同，区别在于，`protected`的成员在子类中也是可以访问的

```c++
#include <iostream>
using namespace std;
 
class Box
{
   protected:
      double width;
};
 
class SmallBox:Box // SmallBox 是派生类
{
   public:
      void setSmallWidth( double wid );
      double getSmallWidth( void );
};
 
// 子类的成员函数
double SmallBox::getSmallWidth(void)
{
    return width ;
}
 
void SmallBox::setSmallWidth( double wid )
{
    width = wid;
}
 
// 程序的主函数
int main( )
{
   SmallBox box;
 
   // 使用成员函数设置宽度
   box.setSmallWidth(5.0);
   cout << "Width of box : "<< box.getSmallWidth() << endl;
 
   return 0;
}
```

#### 继承

