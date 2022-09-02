# QT地图插件开发 
![image](../doc/doc_res/freekmap.png)
`` 通过QtPositioning模块，提供定位机制、地图和导航技术、位置搜索等功能的QML和C++的API。
``
## 操作步骤
#### 1. 实现地图服务插件的创建  
![image](../doc/doc_res/createdmapserver.png)
继承QGeoServiceProviderFactory实例化服务工厂
#### 2.实现虚函数接口
![image](../doc/doc_res/20220902125553.png)
这里先实现地图的显示
#### 3.创建瓦片引擎和地图
![image](../doc/doc_res/tilemap.png)
在瓦片引擎中设置地图属性，缓存等
![image](../doc/doc_res/20220902130328.png)
比较重要的是地图瓦片的获取
![image](../doc/doc_res/TileFecth.png)
这里要实现重写getTileImage获取瓦片image
URL获取需要各家的瓦片地图获取API
![image](../doc/doc_res/getimage.png)
#### 4.创建瓦片回复类
![image](../doc/doc_res/TiledMapreply.png)
![image](../doc/doc_res/20220902131746.png)
![image](../doc/doc_res/TileFecth.png)