//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"

using boost::filesystem::unique_path;
using boost::filesystem::current_path;
using boost::filesystem::create_directories;
using boost::filesystem::create_directory;
using boost::filesystem::remove_all;


path TreeTestCase::ph;
std::string TreeTestCase::file1_ph;
std::string TreeTestCase::file2_ph;
std::vector<std::string> TreeTestCase::tree1;
std::vector<std::string> TreeTestCase::tree2;
std::vector<std::string> TreeTestCase::tree3;


void TreeTestCase::SetUp() {
    ph = unique_path();
    create_directories(ph.string());
    create_directory(ph.string() + "/A");
    create_directories(ph.string() + "/B/C");

    file1_ph = ph.string() + "/file1.txt";
    file2_ph = ph.string() + "/B/file2.cpp";

    std::ofstream ofs1(file1_ph);
    ofs1.close();
    std::ofstream ofs2(file2_ph);
    ofs2.close();

    tree1 = {"A", "B", "B/C"};
    tree2 = {"A", "B", "B/C", "B/file2.cpp", "file1.txt"};
    tree3 = {"B", "B/file2.cpp", "file1.txt"};
}

void TreeTestCase::TearDown() {
    remove_all(ph.string());
    file1_ph = "";
    file2_ph = "";
    tree1 = {};
    tree2 = {};
    tree3 = {};
}


std::vector<std::string> TreeTestCase::get_names(FileNode f) {
    std::vector<FileNode> children = f.children;
    std::vector<std::string> ans;
    ans.reserve(children.size());
    for (auto& el : children) {
        ans.push_back(el.name);
        if (!el.children.empty()) {
            for (auto& c : el.children)
                ans.push_back(el.name + "/" + c.name);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

std::vector<std::string> TreeTestCase::get_filtered_names() {
    FileNode f = GetTree(ph.string(), false);
    FilterEmptyNodes(f, ph.string());
    return get_names(GetTree(ph.string(), false));
}

TEST_F(TreeTestCase, ExceptionsAssertion) {
    EXPECT_THROW(GetTree("./try", true), std::invalid_argument);
    EXPECT_THROW(GetTree(file1_ph, true), std::invalid_argument);
}

TEST_F(TreeTestCase, OnlyDirectories) {
    EXPECT_EQ(get_names(GetTree(ph.string(), true)), tree1);
}

TEST_F(TreeTestCase, WithFiles) {
    EXPECT_EQ(get_names(GetTree(ph.string(), false)), tree2);
}

TEST_F(TreeTestCase, FilterEmptyDirs) {
    EXPECT_EQ(get_filtered_names(), tree3);
}

TEST_F(TreeTestCase, FileNodeEquality) {
    EXPECT_TRUE(GetTree(ph.string(), true) == GetTree(ph.string(), true));
}