import serial
import time
#相关学习链接https://blog.csdn.net/pengneng123/article/details/129727811
#https://blog.csdn.net/hao_ding/article/details/9255171
#https://blog.csdn.net/qq_44785318/article/details/112883755

class Arduino:
    #初始化
    def __init__(self):
        #打开串口0， 传输速率9600字节每秒，8N1，连接超时1秒   使用USB连接串行口
        self.obj = serial.Serial("/dev/ttyUSB0", 9600, timeout=1)
        print("Arduino Connected")

    def left(self):
       #Serial.write() 发送的是字节 向串口写数据（写二进制数据到串口。）
       #b：此参数表示bytes类型, 直接发送字符串会报错 必须要在前面加入b，表示以bytes形式像串口写入数据
        self.obj.write(b'1')

    def right(self):
        self.obj.write(b'2')


if __name__ == "__main__":
    obj = Arduino()
    obj.left()
    # 推迟执行5s
    time.sleep(5)
    obj.right()

    

