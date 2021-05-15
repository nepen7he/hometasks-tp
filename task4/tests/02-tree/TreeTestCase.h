//
// Created by akhtyamovpavel on 5/1/20.
//


#pragma once

#include <gtest/gtest.h>
#include <boost/filesystem/path.hpp>
#include "Tree.h"
using boost::filesystem::path;

class TreeTestCase : public ::testing::Test {
public:
    static path ph;
    static std::string file1_ph;
    static std::string file2_ph;
    static std::vector<std::string> tree1;
    static std::vector<std::string> tree2;
    static std::vector<std::string> tree3;
public:
    void SetUp() override;
    void TearDown() override;
    std::vector<std::string> get_names(FileNode);
    std::vector<std::string> get_filtered_names();
};


