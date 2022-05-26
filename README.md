# Bidirectional Weighted Graph

## This graph uses a vector of linkedlists

<ul>
  <li>The vertices of the vector are the linkedlist objects in the vector and contain an id and string of data</li>
  <li>The edges of the graph are the nodes in the linkedlist and contain an id of the vertex and a weight</li>
</ul>

### Methods

<ul>
  <li><b>getNumVertices:</b> returns the graph's size/# of linkedlists/vertices</li>
  <li><b>getNumEdges:</b> returns a count of the edges created.  Edges are incremeted and decremented as they are built or deleted</li>
  <li><b>addVertex:</b> adds a linkedlist object/vertex to the graph/vector of linkedlist objects</li>
  <li><b>addEdge:</b> adds a node to two linkedlists in the graph based on their ids and gives each the same weight</li>
  <li><b>breadthFirstTraversal:</b>  traverses by finding vertices and edges by id with BFS algorithm.  The queue is displayed for each cycle.</li>
  <li><b>printGraph:</b> displayes the graph as a vector of linked lists</li>
  <li><b>removeEdge:</b> removes a node in two linkedlists based on their ids by searching for the vertex/linkedlist object they are a part of</li>
  <li><b>getEdgeWeight:</b> gets the weight of two edges, found using their ids</li>
  <li><b>depthFirstTraversal:</b> Searches with DFS algorithm by finding vertices, adding unvisited vertices to a stack, displays stack for each cycle</li>
  <li><b>edgExists:</b> used by other methods to find if an edge exists before returning its weight</li>
  <li><b>isEmpty:</b> returns the size of the graph vector</li>
  <li><b>findSmallest:</b> used by depthFirstTraversal method to find the smallest weighted path by searching through a linkedlists connections' weights</li>
  <li><b>hasVisited:</b> returns a boolean to be used in BFS and DFS traversals based on if a node has been visited already</li>
  <li><b>verticesExist:</b> another helper that determines if two vertices exist prior to being used in addEdge</li>
  <li><b>edgeExists:</b> determines if an edge exists between two vertices so this can be used in getEdgeWeight</li>
</ul>

### Improvements to Work On...

#### This graph uses a lot of linear search to find the vertices within the graph and then the edges within the linked list.  A better approach I'd like to try next is to try and use a hash table.

