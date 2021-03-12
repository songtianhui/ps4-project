#ifndef EDGE_H
#define EDGE_H

class Edge {
private:
    int source;
    int destination;
public:
    Edge(int source, int destination);

    ~Edge();

public:
    int GetSource() const;

    int GetDestination() const;
};

#endif
