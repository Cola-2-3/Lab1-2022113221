#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "lab1.h" // 使用 lab1.h 而非 lab1.c

// 初始化测试用图
void setup_graph() {
    nodeCount = 0; // 重置图
    buildGraph("The scientist carefully analyzed the data wrote a detailed report and shared the report with the team but the team requested more data so the scientist analyzed it again");
}

// 测试用例 1：两单词存在，有桥接词
void test_bridge_words_exist() {
    setup_graph();
    const char* result = queryBridgeWords("shared", "report");
    CU_ASSERT_STRING_EQUAL(result, "The bridge words from shared to report are: the");
}

// 测试用例 2：两单词存在，无桥接词
void test_no_bridge_words() {
    setup_graph();
    const char* result = queryBridgeWords("the", "report");
    CU_ASSERT_STRING_EQUAL(result, "No bridge words from given words!");
}

// 测试用例 3：word1 不在图中
void test_word1_not_in_graph() {
    setup_graph();
    const char* result = queryBridgeWords("unknown", "the");
    CU_ASSERT_STRING_EQUAL(result, "No unknown or the in the graph!");
}

// 测试用例 4：两单词均不在图中
void test_neither_word_in_graph() {
    setup_graph();
    const char* result = queryBridgeWords("unknown1", "unknown2");
    CU_ASSERT_STRING_EQUAL(result, "No unknown1 or unknown2 in the graph!");
}

// 主函数运行测试
int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("queryBridgeWords_suite", NULL, NULL);
    CU_add_test(suite, "test_bridge_words_exist", test_bridge_words_exist);
    CU_add_test(suite, "test_no_bridge_words", test_no_bridge_words);
    CU_add_test(suite, "test_word1_not_in_graph", test_word1_not_in_graph);
    CU_add_test(suite, "test_neither_word_in_graph", test_neither_word_in_graph);
    
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}