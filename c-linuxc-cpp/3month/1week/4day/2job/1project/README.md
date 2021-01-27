# 电子相册

1. ## 应用：日常图片显示,广告机前期,基础~

    1.1 扫描目录下文件

     - 递归检索出的图片数据存储到内核链表中
     - 定义大结构体,节点基本构成
     - 数据域
        - 文件存储绝对路径
        - 文件名
        - 文件最后修改时间(也是图片创建时间)
        - 文件大小
     - 指针域
        - 引用的内核链表的指针小结构体 来定位上下
     - 增加滑动效果,由上往下, 由下往上,由左往右, 由右往左,百叶窗显示
        - 功能已完成(11-07)
        - 整合已完成(11-08)
        - 集成已完成
     - 音频播放
        - 功能未完成
        - 整合未完成
        - 集成未测试
     - 视频播放
        - 功能未完成
        - 整合未完成
        - 集成未测试

    1.2 第一步定义一个图片结构体
     - 字体显示设置
        - gb2312编码显示
        - utf8编码转换为gb2312显示
     - 图片切换功能
        - 排序功能的链表函数封装
        - 图片名进行排序
        - 文件大小进行排序
        - 其他属性进行排序
     - 更多的图片切换效果