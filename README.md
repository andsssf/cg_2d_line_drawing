# 2D Line Drawing

计算机图形学 二维画线图元生成

实现了以下算法：

- 直线 DDA 算法 (Line_DDA.cpp)
- 直线中点算法  (Line_MP.cpp)
- 圆弧中点算法  (Circle_MP.cpp)

项目使用 VS Code 开发，cmake构建，编译器使用g++。基于glew、freeglut库。

构建完成后需要动态链接库 `freeglut.dll` `glew32.dll` `glu32.dll` 与程序在同一目录下才可运行。
