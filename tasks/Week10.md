# Week 10 - 异常

本周我们需要实现对异常的支持，在`include/Exceptions/GLException`中已经定义了`GLException`，**请在`include/Exceptions`中定义`NegCycleException`**，并继承自`GLException`。

## 不符合规约的情况

在上周，我们提到，利用`static_assert`，我们可以检查传入的模板参数是否符合某些约束条件（C++20中将引入concept以简化代码写法），以此在编译期拒绝掉不符合规约的情况。

然而，有一些不符合规约的情况，是难以或者无法在编译期检查出来的。此时，我们就要利用异常。

我们前两周实现的Bellman Ford和Floyd都是这样的例子。如果输入的图中存在负环（在Bellman Ford中还需要从起点可达），那么算法的更新就无法停止或者返回的结果没有意义。

所以，我们要修改上周的代码，在检测到负环时，通过`throw`抛出一个类型为`NegCycleException`的异常。

由于负环难以定义，所以抛出的异常中不需要包含负环。但为了方便潜在的用户debug，异常中需包含当前正在运行的算法名（`Bellman-Ford`或`Floyd`）。（这样，如果用户在运行一个非常复杂的算法时遇到异常，他就可以通过异常中的信息，确定异常发生在哪个函数的内部）

你throw的异常中可以包含任意你觉得可能有助于debug的信息，我们只会通过`operator<<(std::ostream&, const GLException&)`对结果进行评判。

