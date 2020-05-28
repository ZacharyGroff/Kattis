package graph

import (
	"errors"
	"fmt"
	"strings"
)

type Node struct {
	value string
	edges []*Node
}

type UndirectedGraph struct {
	vertices []*Node
}

func NewUndirectedGraph() *UndirectedGraph {
	var vertices []*Node
	return &UndirectedGraph{
		vertices: vertices,
	}
}

func (g *UndirectedGraph) AddVertex(value string) error {
	var edges []*Node
	node := Node{
		value: value,
		edges: edges,
	}

	_, err := find(g.vertices, value)
	if err == nil {
		return errors.New("vertex already exists in graph")
	}

	g.vertices = append(g.vertices, &node)

	return nil
}

func (g *UndirectedGraph) RemoveVertex(value string) error {
	indexOf, err := findIndex(g.vertices, value)
	if err != nil {
		return err
	}
	g.vertices = append(g.vertices[:indexOf], g.vertices[indexOf+1:]...)

	for _, vertex := range g.vertices {
		index, err := findIndex(vertex.edges, value)
		if err == nil {
			vertex.edges = append(vertex.edges[:index], vertex.edges[index+1:]...)
		}
	}

	return nil
}

func (g *UndirectedGraph) AddEdge(value1, value2 string) error {
	node1, err := find(g.vertices, value1)
	if err != nil {
		return err
	}
	node2, err := find(g.vertices, value2)
	if err != nil {
		return err
	}

	_, err = find(node1.edges, value2)
	if err == nil {
		return errors.New("edge already exists")
	}

	_, err = find(node2.edges, value1)
	if err == nil {
		return errors.New("edge already exists")
	}

	node1.edges = append(node1.edges, node2)
	node2.edges = append(node2.edges, node1)
	return nil
}

func (g *UndirectedGraph) RemoveEdge(value1, value2 string) error {
	node1, err := find(g.vertices, value1)
	if err != nil {
		return err
	}
	node2, err := find(g.vertices, value2)
	if err != nil {
		return err
	}

	index1, err := findIndex(node1.edges, value2)
	if err != nil {
		return errors.New("edge does not exist")
	}

	index2, err := findIndex(node2.edges, value1)
	if err != nil {
		return errors.New("edge does not exist")
	}

	node1.edges = append(node1.edges[:index1], node1.edges[index1+1:]...)
	node2.edges = append(node2.edges[:index2], node2.edges[index2+1:]...)

	return nil
}

func Dfs(node *Node, action func(string), visited *[]*Node) {
	if node == nil {
		return
	}

	action(node.value)
	*visited = append(*visited, node)

	for _, child := range node.edges {
		_, err := findIndex(*visited, child.value)
		if err != nil {
			Dfs(child, action, visited)
		}
	}
}

func Bfs(node *Node, action func(string)) {
	marked := []*Node{node}
	toVisit := []*Node{node}

	for len(toVisit) > 0 {
		action(toVisit[0].value)
		for _, node := range toVisit[0].edges {
			_, err := findIndex(marked, node.value)
			if err != nil {
				marked = append(marked, node)
				toVisit = append(toVisit, node)
			}
		}
		toVisit = toVisit[1:]
	}

}

func (g *UndirectedGraph) Print() {
	for _, node := range g.vertices {
		fmt.Printf("Node: %s\n", node.value)
		for _, edge := range node.edges {
			fmt.Printf("Edge: %s\t", edge.value)
		}
		fmt.Println()
	}
}

func find(vertices []*Node, value string) (*Node, error) {
	for _, node := range vertices {
		if strings.Compare(node.value, value) == 0 {
			return node, nil
		}
	}

	return &Node{}, errors.New("not found")
}

func findIndex(vertices []*Node, value string) (int, error) {
	for index, node := range vertices {
		if strings.Compare(node.value, value) == 0 {
			return index, nil
		}
	}

	return -1, errors.New("not found")
}
