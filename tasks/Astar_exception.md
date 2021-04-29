# Week 9 - 异常

本周我们需要完成A*单源最短路算法，**请在`Algorithms/AStarShortestPaths.h`中定义模板类`AStarShortestPaths`**，并继承自`ShortestPaths`。

## 不符合规约的情况

在上周，我们提到，利用static_assert，我们可以检查传入的模板参数是否符合条件，以此在编译期拒绝掉不符合规约的情况。

然而，有一些不符合规约的情况，是难以或者无法在编译期检查出来的。此时，我们就要利用异常。

我们上周实现的Bellman Ford就是一个这样的例子。如果输入的图中存在从起点可达的负环，那么算法的更新就无法停止。

所以，我们要修改上周的代码，在检测到负环时，通过`throw`抛出一个异常。

## A*算法

除了Dijkstra和Bellman Ford算法之外，还有一种单源最短路算法，叫作A*算法。

A*算法又被称为Best-First Algorithm。它的特点是，我们除了知道每条边的权重之外，还有一个评估函数$ h$，$ h(x)$表示我们对$ x$到终点的距离的（上）估计（overestimation）。因此，$ h$需满足$ h(t) = 0$，$ h(p) \leq cost(p, q) + h(q)$。

借助这个函数，我们可以进行和Dijkstra类似的搜索。只不过，我们直接是按照从起点出发的路程的顺序进行遍历。现在，既然有了到终点的估值，我们就可以用$\text{起点到当前点的路程}+\text{当前点到终点路程的估计值}$ 来作为遍历的顺序。

`AStarShortestPaths`需要支持两种构造方式，第一种是和Dijkstra、Bellman Ford完全一致的构造方式。（为了兼容父类）此时，你可以认为$h$总返回`TValue()`。

第二个构造函数额外接受一个用户给定的$Int\rightarrow TValue$的估值函数。因为在实际情况中，启发式函数$ h$可能开销很大，因此我们需要尽可能地减少对其的调用。我们也会通过判断其被调用次数（在某种情况下是否和图的大小是线性）来判断你的A*算法实现是否正确。

````c++
AStarShortestPaths(const TGraph *graph, int source);
AStarShortestPaths(const TGraph *graph, int source, const std::function<TValue(int)>& f);
````

### 注意：

如果存在两个点$p_1, p_2$满足$ g(p_1) + h(p_1) = g(p_2) + h(p_2)$，那么，我们应该先遍历$ g$较大的那个点（因为它对应的$ h$较小，可以认为估计的误差更小）。