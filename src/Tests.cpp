#include <gtest/gtest.h>
#include <random>
#include <ctime>
#include <set>
#include <string>

#include "Tree.h"
#include "Vector.h"
#include "Priority_queue.h"

// ---------------------- Vector ----------------------

class VectorTest : public::testing::Test{
protected:
    Vector<double>* v_double;
    Vector<std::string>* v_string;
    Vector<int>* v_mil;

    void SetUp() override {
        v_double = new Vector<double>;
        v_string = new Vector<std::string>;
        v_mil    = new Vector<int>;
    }
    void TearDown() override {
        delete v_double;
        delete v_string;
        delete v_mil;
    }
};

// ----------------- Vector Double Test -----------------

TEST_F(VectorTest, Vector_Double_Test) {
    int size_answers[4]    = {0, 1, 2, 3};
    bool empty_answers[4]  = {true, false, false, false};
    double back_answers[3] = {2.0, -2.0, 0.0};

    int size_results[4];
    bool empty_results[4];
    double back_results[4];

    size_results[0] = v_double->Size();
    empty_results[0] = v_double->Empty();

    for (int i = 0; i < 3; i++){
        v_double->PushBack(back_answers[i]);
        size_results[i+1] = v_double->Size();
        empty_results[i+1] = v_double->Empty();
        back_results[i] = v_double->Back();
    }
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(size_results[i], size_answers[i]);
        EXPECT_EQ(empty_results[i], empty_answers[i]);
        if (i != 3){
            EXPECT_EQ(back_results[i], back_answers[i]);
            //EXPECT_EQ(v_double[i], back_answers[i]);
        }
    }
}

// ----------------- Vector String Test -----------------

TEST_F(VectorTest, Vector_String_Test) {
    int size_answers[4]         = {0, 1, 2, 3};
    bool empty_answers[4]       = {true, false, false, false};
    std::string back_answers[3] = {"abc", "bac", "cab1"};

    int size_results[4];
    bool empty_results[4];
    std::string back_results[4];

    size_results[0] = v_string->Size();
    empty_results[0] = v_string->Empty();

    for (int i = 0; i < 3; i++){
        v_string->PushBack(back_answers[i]);
        size_results[i+1] = v_string->Size();
        empty_results[i+1] = v_string->Empty();
        back_results[i] = v_string->Back();
    }
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(size_results[i], size_answers[i]);
        EXPECT_EQ(empty_results[i], empty_answers[i]);
        if (i != 3){
            EXPECT_EQ(back_results[i], back_answers[i]);
          //  EXPECT_EQ(v_string[i], back_answers[i]);
        }
    }
}

// ----------------- Vector million Test ----------------

TEST_F(VectorTest, Vector_Million_Test) {  
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 10000);
        
    std::vector<int> mas;
    for (int i = 0; i < 1000000; i++){
        mas.push_back(dist(gen));
    }

    clock_t start = clock();    
    for (int i = 0; i < 1000000; i++) {
        v_mil->PushBack(mas[i]);
    }
    
    clock_t end = clock();
    double time = ((double)(end - start))/CLOCKS_PER_SEC;
    
    ASSERT_TRUE(time < 1);
}

// ----------------------------------------------------
// ----------------------------------------------------


// ---------------------- Vector ----------------------


class TreeTest : public::testing::Test{
protected:
    Tree<double>* tree1;
    Tree<int>* tree2;
    std::set<int>* set2;
    
    void SetUp() override {
        tree1 = new Tree<double>;
        tree2 = new Tree<int>;
        set2 = new std::set<int>;
    }
    
    void TearDown() override {
        delete tree1;
        delete tree2;
        delete set2;
    }
};
    
// ---------------------- Tree test ------------------------
    
TEST_F(TreeTest, TreeTest) {
    int correct_answers[3] = {4, 0, 5};
    int program_answers[3];
    Node<double>* root = nullptr;
    
    root = tree1->Insert(root, 2.0);
    root = tree1->Insert(root, 3.0);
    root = tree1->Insert(root, 10.0);
    root = tree1->Insert(root, 1.0);
    root = tree1->Insert(root, 1.5);
    root = tree1->Pop(root, 3.0);
           
    program_answers[0] = tree1->NumberOfSegmentElements(root, 1.0, 31.0);
    program_answers[1] = tree1->NumberOfSegmentElements(root, 60.0, 90.0);

    Tree<double> tree_add;


    Node<double>* root1 = nullptr;
    root1 = tree_add.Insert(root1, 2.0);
    root1 = tree_add.Insert(root1, 3.0);
    root1 = tree_add.Insert(root1, 1.0);

    root = tree1->Insert(root, 30.0);
    root = tree1->Insert(root, 40.0);
    
    program_answers[2] = tree1->NumberOfSegmentElements(root, 1, 30);
    
    for(int i = 0; i < 3; i++){
        EXPECT_EQ(program_answers[i], correct_answers[i]);
    }
}
    
 // ---------------------- Tree time test ----------------------
    
 TEST_F(TreeTest, TimeTest) {
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 10000);
    
    Node<int>* root = nullptr;
    const int N = 1000000;
    
    std::vector<int> mas;
    for (int i = 0; i < N; i++){
        mas.push_back(dist(gen));
    }
    
    clock_t start = clock();
    
    for (int i = 0; i < N; i++) {
        root = tree2->Insert(root, mas[i]);
    }
    
    clock_t end = clock();
    double tree_time = ((double)(end - start))/CLOCKS_PER_SEC;
    
    
    start = clock();
    for (int i = 0; i < N; i++) {
        set2->insert(mas[i]);
    }    
    end = clock();
    double set_time = ((double)(end - start))/CLOCKS_PER_SEC;
    
    std::cout << tree_time << "  " << set_time << "\n";
    ASSERT_TRUE(tree_time <= set_time*7);
}

// ----------------------------------------------------
// ----------------------------------------------------
// ------------------ Priority Queue ------------------

class PriorityQueueTest : public::testing::Test{
protected:
    PriorityQueue<double>* q_double;
    PriorityQueue<std::string>* q_string;
    PriorityQueue<int>* q_mil;
    
    void SetUp() override {
        q_double = new PriorityQueue<double>;
        q_string = new PriorityQueue<std::string>;
        q_mil    = new PriorityQueue<int>;
    }
    void TearDown() override {
        delete q_double;
        delete q_string;
        delete q_mil;
    }
};

TEST_F(PriorityQueueTest, Priority_Queue_double_Test) {
    int size_answers[6]    = {0, 1, 2, 3, 4, 5};
    bool empty_answers[6]  = {true, false, false, false, false, false};
    double adds[5]    = {2.0, -2.0, 0.0, 4.0, -10.0};
    double top_answers[5] = {2.0, 2.0, 2.0, 4.0, 4.0};


    int size_results[6];
    bool empty_results[6];
    double top_results[6];

    size_results[0] = q_double->Size();
    empty_results[0] = q_double->Empty();


    for (int i = 0; i < 5; i++){
        q_double->Push(adds[i]);
        size_results[i+1] = q_double->Size();
        empty_results[i+1] = q_double->Empty();
        top_results[i] = q_double->Top()->value;
    }
    

    for (int i = 0; i < 6; i++) {
        EXPECT_EQ(size_results[i], size_answers[i]);
        EXPECT_EQ(empty_results[i], empty_answers[i]);
    }

    EXPECT_EQ(q_double->Contains(4.0), true);
    q_double->Pop(4.0);
    EXPECT_EQ(q_double->Contains(4.0), false);
    EXPECT_EQ(q_double->Contains(-2.0), true);
    q_double->Pop(-2.0);
    EXPECT_EQ(q_double->Contains(-2.0), false);

    EXPECT_EQ(q_double->Contains(2.0), true);
    q_double->PopTop();
    EXPECT_EQ(q_double->Contains(2.0), false);

    EXPECT_EQ(q_double->Find(-10.0)->value, -10.0);
    EXPECT_EQ(q_double->Find(0.0)->value, 0.0);

    PriorityQueue<double> add_q;
    add_q.Push(10.0);
    add_q.Push(0.0);

    q_double->Merge(add_q); // replace: q_double = q_double + add_q
    

    EXPECT_EQ(q_double->Size(), 4);
    EXPECT_EQ(q_double->Find(10.0)->value, 10.0);
    EXPECT_EQ(q_double->Empty(), false);

    q_double->Clear();
    EXPECT_EQ(q_double->Size(), 0);
    EXPECT_EQ(q_double->Empty(), true);
    
}

TEST_F(PriorityQueueTest, Priority_Queue_string_Test) {
    int size_answers[6]    = {0, 1, 2, 3, 4, 5};
    bool empty_answers[6]  = {true, false, false, false, false, false};
    std::string adds[5]    = {"Never", "Marry", "A", "Railroad", "Man"};
    std::string  top_answers[5] = {"Never", "Marry", "Marry", "Railroad", "Railroad"};


    int size_results[6];
    bool empty_results[6];
    std::string  top_results[6];

    size_results[0] = q_string->Size();
    empty_results[0] = q_string->Empty();


    for (int i = 0; i < 5; i++){
        q_string->Push(adds[i]);
        size_results[i+1] = q_string->Size();
        empty_results[i+1] = q_string->Empty();
        top_results[i] = q_string->Top()->value;
    }

    for (int i = 0; i < 6; i++) {
        EXPECT_EQ(size_results[i], size_answers[i]);
        EXPECT_EQ(empty_results[i], empty_answers[i]);
    }
    EXPECT_EQ(q_string->Contains("A"), true);
    q_string->Pop("A");
    EXPECT_EQ(q_string->Contains("A"), false);
    EXPECT_EQ(q_string->Contains("Marry"), true);
    q_string->Pop("Marry");
    EXPECT_EQ(q_string->Contains("Marry"), false);

    EXPECT_EQ(q_string->Contains("Railroad"), true);
    q_string->PopTop();
    EXPECT_EQ(q_string->Contains("Railroad"), false);

    EXPECT_EQ(q_string->Find("Man")->value, "Man");
    EXPECT_EQ(q_string->Find("Never")->value, "Never");

    PriorityQueue<std::string> add_q;
    add_q.Push("Golden");
    add_q.Push("Brown");
    add_q.Push("Brown");

    q_string->Merge(add_q);

    EXPECT_EQ(q_string->Size(), 5);
    EXPECT_EQ(q_string->Find("Golden")->value, "Golden");
    EXPECT_EQ(q_string->Find("Brown")->value, "Brown");
    EXPECT_EQ(q_string->Empty(), false);

    q_string->Clear();
    EXPECT_EQ(q_string->Size(), 0);
    EXPECT_EQ(q_string->Empty(), true);
}
        
TEST_F(PriorityQueueTest, Priority_Queue_Million_Test) {  
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 10000);
        
    std::vector<int> mas;
    for (int i = 0; i < 1000000; i++){
        mas.push_back(dist(gen));
    }

    clock_t start = clock();    
    for (int i = 0; i < 1000000; i++) {
        q_mil->Push(mas[i]);
    }
    
    clock_t end = clock();
    double time = ((double)(end - start))/CLOCKS_PER_SEC;
    
    ASSERT_TRUE(time < 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);   
    return RUN_ALL_TESTS();
}