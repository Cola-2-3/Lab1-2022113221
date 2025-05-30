#ifndef LAB1_H
#define LAB1_H

// 假设的结构体定义（根据 lab1.c 调整）
typedef struct Edge {
    int to;
    struct Edge* next;
} Edge;

typedef struct {
    char word[50];
    Edge* head;
} Node;

// 全局变量声明
extern Node graph[1000]; // 假设最大节点数为 1000，调整大小
extern int nodeCount;
extern double pageRank[1000];

// 函数声明
int findNodeIndex(const char* word);
void addNode(const char* word);
void addEdge(int from, int to);
void buildGraph(const char* text);
void showDirectedGraph();
char* queryBridgeWords(const char* word1, const char* word2);
char* generateNewText(const char* input);
char* calcShortestPath(const char* word1, const char* word2);
void calPageRank();
char* randomWalk();
void debug();

#endif