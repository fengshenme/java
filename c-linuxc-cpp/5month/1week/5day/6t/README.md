## 停车管理系统

- 表设计
  1. 管理员表(id, 管理员账号, 密码, 管理员手机号, 注册时间, 逻辑删除, 权限等级) // 时间有限不做注册功能
  2. 停车表(id, 车牌, 卡号, 入车时间, 出车时间, 消费单价, 逻辑删除, 停车位)
  3. 用户表(id,车牌, 卡号, 用户手机号, 卡上余额, 逻辑删除, 充值记录, 消费记录)


姓名 谭威峰 gz2067 2020.1.15
停车管理系统 彭龙

- 设计目标
  1. 为小区,酒店设计的停车管理系统 
  2. 提升停车管理效率

- 功能描述
  1. 刷卡入库出库
  2. 业主自住选择停车位
  3. 提供天气预报和时间校准
  4. 为业主办理停车卡, 充值
  5. 业主停车后提供视频安防等功能
- 设计方案
      1. 采用c++ 语言进行程序设计
      2. 使用linux软件平台, soc使用三星arm处理器
      3. 读卡模块, 视频模块,
- 系统框架流程

- 心得体会
   1. 数据库的使用
   2. 串口的使用
   3. 视频的使用
   4. 对最近所学的知识的整合 



---

http://wthrcdn.etouch.cn/weather_mini?city=北京 //天气api
http://quan.suning.com/getSysTime.do  // 北京时间api

功能点分析
=======================
   (1)把C语言写的读取卡号代码融入QT工程
         思路：参考摄像头V4L2代码融入QT工程(一模一样的思路)
   (2)如何判断第一次刷卡还是第二次刷卡
         思路一：刷卡成功之后，调用select语句去查询表格中是否有这个卡号
                有卡号 --》说明现在是第二次刷卡，出车
                没有卡号 --》说明现在是第一次刷卡，入车
                温馨提醒：不能用exec()的返回值去判断查询是否成功
         思路二：卡号字段修饰成unique(唯一性)
                 刷卡成功，直接插入卡号到表格中
                 插入成功 --》说明现在是第一次刷卡，入车
                 插入不成功 --》说明现在是第二次刷卡，出车


