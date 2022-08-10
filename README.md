# VITIS_HLS2022_DFT
Xilinx暑期课程2022-DFT
## 总体思路
首先完成DFT运算的原型设计，之对其进行优化，对比加速后设计在运算速度上的提升。
## 原型设计
采用PP4FPGA教材中的原型。复杂度为O(n^2)。
## 加速设计
加速主要思路分为消除三角函数运算，流水线化和数组优化。
### 消除三角函数运算
由于DFT的点数为固定值1024，所以在运算时用到的所有三角函数值都是固定的。因此，可以提前将三角函数值计算好，并保存在ROM中，运算过程中直接读取，这样会节约计算三角函数消耗的时间。
###流水线化
经过分析后可以发现，在资源足够多的情况下，整个DFT计算的过程可以完全流水线化。具体过程为：
#### 流水级设置
定义数组temp_real[1024]和temp_imag[1024]存储临时数据，且temp_real[0]和temp_imag[0]分别初始化为输入数据的第一个实部和虚部。temp_real和temp_imag中的每个元素都为一个流水级。
#### 流水级工作
假设当前正在计算下标为i的输出，则流水级j执行的工作为：读取下标为[(i*j)%1024]的正余弦常数值，
### 数组优化
在HLS代码中，存储三角函数值的数组和其他在函数内声明的数组都需要在同意时钟周期接受多次访问，因此，这里使用array_partition的宏汇编指令将这些数组完全拆分。
## 硬件设置
