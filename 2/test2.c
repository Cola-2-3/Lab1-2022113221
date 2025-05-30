// test2.c
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "lab1.h"

// 初始化测试套件
int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

// 设置图结构（用于测试用例 1、3、4）
void setup_graph(void) {
    nodeCount = 0; // 重置图
    // 添加节点和边：the -> shared -> report
    int the_idx = addNode("the");
    int shared_idx = addNode("shared");
    int report_idx = addNode("report");
    addEdge(the_idx, shared_idx);  // the -> shared
    addEdge(shared_idx, report_idx);  // shared -> report
}

// 设置图结构（用于测试用例 2：无路径）
void setup_graph_no_path(void) {
    nodeCount = 0; // 重置图
    // 添加节点：shared, report, 但无边连接
    int shared_idx = addNode("shared");
    int report_idx = addNode("report");
    // 不添加 shared -> report 的边
    // 可添加无关边以确保图非空，例如：
    int dummy_idx = addNode("dummy");
    addEdge(shared_idx, dummy_idx);  // shared -> dummy
}

// 测试用例 1：单词不在图中
void test_word_not_in_graph(void) {
    setup_graph();
    const char* result = calcShortestPath("unknown", "the");
    CU_ASSERT_STRING_EQUAL(result, "No unknown or the in graph!");
}

// 测试用例 2：单词存在但无路径
void test_no_path(void) {
    setup_graph_no_path(); // 使用无路径图
    const char* result = calcShortestPath("shared", "report");
    CU_ASSERT_STRING_EQUAL(result, "Words are not connected.");
}

// 测试用例 3：有路径，更新距离
void test_path_with_update(void) {
    setup_graph();
    const char* result = calcShortestPath("the", "report");
    CU_ASSERT_STRING_EQUAL(result, "Path: the -> shared -> report | Number of steps: 2");
}

// 测试用例 4：有路径，无需更新距离
void test_path_no_update(void) {
    setup_graph();
    const char* result = calcShortestPath("the", "shared");
    CU_ASSERT_STRING_EQUAL(result, "Path: the -> shared | Number of steps: 1");
}

// 主函数
int main(void) {
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    CU_pSuite suite = CU_add_suite("CalcShortestPath_Test_Suite", init_suite, clean_suite);
    if (suite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(suite, "Test Word Not In Graph", test_word_not_in_graph)) ||
        (NULL == CU_add_test(suite, "Test No Path", test_no_path)) ||
        (NULL == CU_add_test(suite, "Test Path With Update", test_path_with_update)) ||
        (NULL == CU_add_test(suite, "Test Path No Update", test_path_no_update))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}