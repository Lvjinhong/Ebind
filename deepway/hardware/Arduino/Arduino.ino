#include<Servo.h> //控制物体的转动并保持:应该是眼镜边缘的触角
Servo x; //声明左边触角实现控制
Servo y; //右边
#学习链接https://www.cnblogs.com/leytton/p/8954658.html
#https://blog.csdn.net/u014421313/article/details/125421394?spm=1001.2101.3001.6650.2&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-2-125421394-blog-130156486.235%5Ev40%5Epc_relevant_anti_vip_base&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-2-125421394-blog-130156486.235%5Ev40%5Epc_relevant_anti_vip_base&utm_relevant_index=5
void setup() {
  // put your setup code here, to run once:
x.attach(2);//设定舵机接口一般为9,10
y.attach(3);
Serial.begin(9600);打开串口通讯,设置传输速率9600字节每秒
x.write(50);//舵机旋转角度0度至180度,左边初始为50度
y.write(102);
}

void loop() {
  // put your main code here, to run repeatedly:

if(Serial.available()>0)//读串口缓存区数据,Serial.available()返回的是缓冲区准确的可读字节数
{
  int inp=Serial.read();//读取串口数据，一次读一个字符，读完后删除已读数据
  if(inp=='1')//1为左
     left();
     
  else if(inp=='2')//2为右
      right();  
}
}

void left()
{
  x.write(0);//转到0度
  delay(500);//等待500毫秒
  x.write(50);
  delay(500);
  
}

void right()
{
  y.write(152);
  delay(500);
  y.write(102);
  delay(500);
}
