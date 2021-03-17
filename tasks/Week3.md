# Week3 - 虚函数

请实现下面两个类：

- `DataStructures/UndirectedGraph.h`中定义`UndirectedGraph`类表示无向无权图，无向无权图继承自有向无权图（`Graph`类）
- `DataStructures/UndirectedWeightedGraph.h`中定义`UndirectedWeightedGraph`类表示无向有权图，无向有权图继承自有向有权图（`WeightedGraph`类）

这两个类的所有需要实现的接口都和父类相同，也就是说最优情况下只需要将`AddEdge`、`RemoveEdge`等方法进行重载即可。对一些可能存在歧义的函数我们做出如下约定：

1. 无向图中所有边虽然使用了有向图的数据结构，但是所有边都是没有方向的，也就是说`AddEdge(1, 2)`可以看作是添加了两条有向边，之后执行`AddEdge(2, 1)`时`2->1`这条边已经存在，应该返回`false`。
2. `CountEdges`返回的是无向边的数量。
3. `GetEdges`中，每条无向边可以以任意方向表示，但是不能出现重边（也就是说可以是`{{1, 2}}`，也可以是`{{2, 1}}`，但不能是`{{1, 2}, {2, 1}}`这样的结果）。

注意：测试的时候会使用类似如下的代码测试，如果不定义成虚函数就可能会出问题（大概）：

```c++
int main() {
  Graph *g = new UndirectedGraph(); // pointer to derived class instance
  g->AddVertex(1), g->AddVertex(2), g->AddEdge(1, 2);
  assert(g->GetNeighbors(2)[0] == 1); // undirected edges
}
```