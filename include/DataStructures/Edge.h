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

Edge::Edge(int source, int destination){
  source = source;
  destination = destination;
}

Edge::~Edge(){

}

int Edge::GetSource() const {
  return source;
}

int Edge::GetDestination() const {
  return destination;
}

#endif
