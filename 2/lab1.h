// lab1.h
#ifndef LAB1_H
#define LAB1_H

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50
#define INF 999999

// 结构体定义
typedef struct Edge {
    int to;
    int weight;
    struct Edge* next;
} Edge;

typedef struct Node {
    char word[MAX_WORD_LENGTH];
    Edge* head;
} Node;

// 全局变量声明
extern Node graph[MAX_WORDS];
extern int nodeCount;
extern double pageRank[MAX_WORDS];

// 函数声明
int findNodeIndex(const char* word);
int addNode(const char* word); // 修正为返回 int
void addEdge(int from, int to);
void buildGraph(const char* text);
void showDirectedGraph(void);
char* queryBridgeWords(const char* word1, const char* word2);
char* generateNewText(const char* inputText);
char* calcShortestPath(const char* word1, const char* word2);
double calPageRank(const char* word); // 修正为返回 double 并接受参数
char* randomWalk(void);
void debug(void);

#endif