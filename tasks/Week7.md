# Week 7 - 构造/析构函数

> 从Week7起，BFS类和DFS类中的`FindFirstVertex`函数名称修改为`TryFindFirstVertex`，请在合并代码时做出对应的修改。

本周我们需要完成Dijkstra单源最短路算法，**请在`Algorithms/DijkstraShortestPaths.h`中定义模板类`DijkstraShortestPaths`**。在`Algorithms/ShortestPaths.h`中定义了一个单源最短路基类，你的实现需要继承这个基类。

单源最短路类是一个模板类，接受两个参数：

- `TGraph`：图的类型（是一个模板参数），保证只会出现`WeightedGraph`和`UndirectedWeightedGraph`。
- `TValue`：权重的类型，不知道会出现什么。（但你可以假设它有默认构造函数，`operator+`和比较运算符，且默认构造函数返回的是`operator+`下的幺元。）

这个模板类具有以下成员：

1. 构造函数和析构函数
   - 构造函数接受一个指向对应类型图的指针和一个起点编号
   - 析构函数是一个虚函数，负责释放申请的资源（注意不能删除图，因为图的生命周期显然超过这个类的对象）
2. `bool HasPathTo(int)`：返回从起点开始是否存在一条到达终点的路径。
3. `std::optional<TValue> TryGetDistanceTo(int)`：返回从起点到达终点的最短路径权重，如果不存在路径返回空，起点的距离定义为`TValue`类型的默认值`TValue()`（例如`int()`表示0）。
4. `std::optional<std::vector<int>> TryGetShortestPathTo(int)`：返回从起点到达终点的一条最短路径上所有点的编号（包含起点和终点），如果不存在返回空，如果存在多条返回任意一条。

测试数据保证图中不存在负权边且图不会在程序运行过程的中途被摧毁，因此这个模板类可以按照如下方式实现：

1. （Eager）在构造函数中完成所有数值的计算。
2. （Lazy，不推荐）在构造函数中存储信息，然后每次调用再计算答案，以此方法实现如果进行多次重复运算很可能导致超时。
    - 当然，你也可以在计算完之后，将计算结果都保存下来，下次需要的时候就可以直接返回。

思考题一：如下所示，如果图在程序运行过程中被摧毁了，有什么方法保证程序的正确性？

```c++
#include <DataStructures/WeightedGraph.h>
#include <Algorithms/DijkstraShortestPaths.h>

int main() {
  WeightedGraph<int> *g = new WeightedGraph<int>();
  g->AddVertex(1), g->AddVertex(2);
  g->AddEdge(1, 2, 100);
  
  ShortestPaths<WeightedGraph, int>
    *p = new DijkstraShortestPaths<WeightedGraph, int>(g, 1);
  delete g; // 注意这里，g被先手动摧毁了
  // 先销毁图的操作不符合对象的生命周期关系
  // 但是你没有办法防止用这个库的人这么写代码

  // 有什么方法能够防止任意实现下一行都不会出错？
  cout << p->TryGetDistanceTo(2).value_or(114514) << endl;
  delete p;
  return 0;
}
```

思考题二：在`ShortestPaths`里，我们需要传入两个模板参数，太麻烦了，有没有办法只传入一个模板参数（比如有权图的类型）？如果只传入有权图的类型（比如`WeightedGraph<int>`），我们要怎么从传入的这个类型中“萃取”出`int`？

（事实上，STL的很多模板都用了这个技巧，比如`sort`，传入的仅仅是两个迭代器，但它能够得到迭代器“指向”的对象的类型。）