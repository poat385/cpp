#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stdexcept>

template <typename VertexType, typename WeightType = int>
class Graph {
public:
    // Добавление ребра между вершинами `from` и `to` с весом `weight` (по умолчанию 1)
    void addEdge(const VertexType& from, const VertexType& to, WeightType weight = 1) {
        adjacencyList[from].push_back({to, weight});

    }

    // Удаление ребра между вершинами `from` и `to`
    void removeEdge(const VertexType& from, const VertexType& to) {
        auto it = adjacencyList.find(from);
        if (it == adjacencyList.end()) {
            throw std::invalid_argument("Vertex 'from' not found");
        }

        auto& edges = it->second;
        auto edgeIt = std::find_if(edges.begin(), edges.end(),
            [&to](const auto& edge) { return edge.first == to; });

        if (edgeIt == edges.end()) {
            throw std::invalid_argument("Edge not found");
        }

        edges.erase(edgeIt);
    }

    // Проверка наличия ребра между вершинами
    bool hasEdge(const VertexType& from, const VertexType& to) const {
        auto it = adjacencyList.find(from);
        if (it == adjacencyList.end()) {
            return false;
        }

        const auto& edges = it->second;
        return std::find_if(edges.begin(), edges.end(),
            [&to](const auto& edge) { return edge.first == to; }) != edges.end();
    }

    void printGraph() const {
        for (const auto& [vertex, edges] : adjacencyList) {
            std::cout << vertex << " -> ";
            for (const auto& [to, weight] : edges) {
                std::cout << "(" << to << ", " << weight << ") ";
            }
            std::cout << std::endl;
        }
    }

private:
    std::unordered_map<VertexType, std::vector<std::pair<VertexType, WeightType>>> adjacencyList;
};

int main() {
    // Пример использования
    Graph<std::string, int> graph;

    // Добавляем рёбра
    graph.addEdge("A", "B", 5);
    graph.addEdge("A", "C", 3);
    graph.addEdge("B", "D", 2);
    graph.addEdge("C", "D", 7);

    // Выводим граф
    std::cout << "Graph after adding edges:\n";
    graph.printGraph();

    // Проверяем наличие ребра
    std::cout << "\nEdge from A to B exists: " << std::boolalpha << graph.hasEdge("A", "B") << std::endl;
    std::cout << "Edge from B to A exists: " << std::boolalpha << graph.hasEdge("B", "A") << std::endl;

    // Удаляем ребро
    graph.removeEdge("A", "B");
    std::cout << "\nGraph after removing edge A -> B:\n";
    graph.printGraph();

    return 0;
}