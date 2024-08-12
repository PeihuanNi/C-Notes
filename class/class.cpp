#include <iostream>
using namespace std;
 
class Box
{
   protected:
      double width;
};
 
class SmallBox1:Box // SmallBox 是派生类
{
   public:
      void setSmallWidth( double wid );
      double getSmallWidth( void );
};
 
// 子类的成员函数
double SmallBox1::getSmallWidth(void)
{
    return width ;
}
 
void SmallBox1::setSmallWidth( double wid )
{
    width = wid;
}
 
class SmallBox2:Box // SmallBox 是派生类
{
   public:
      void setSmallWidth( double wid );
      double getSmallWidth( void );
};
 
// 子类的成员函数
double SmallBox2::getSmallWidth(void)
{
    return width ;
}
 
void SmallBox2::setSmallWidth( double wid )
{
    width = wid;
}

// 程序的主函数
int main( )
{
   SmallBox1 box1;
   SmallBox2 box2;
 
   // 使用成员函数设置宽度
   box1.setSmallWidth(5.0);
   box2.setSmallWidth(10.0);
   cout << "Width of box : "<< box1.getSmallWidth() <<  " " << box2.getSmallWidth() << endl;
 
   return 0;
}