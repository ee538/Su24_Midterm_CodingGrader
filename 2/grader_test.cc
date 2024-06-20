#include <iostream>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "q.h"
using ::testing::ElementsAreArray;

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(MyVector, PushBackAndPopBack) {
  MyVector v;
  v.push_back(1);
  EXPECT_EQ(v.size(), 1);
  EXPECT_EQ(v.pop_back(), 1);
  EXPECT_EQ(v.size(), 0);
  EXPECT_EQ(v.get_error(), ErrorCode::kNoError);
}

TEST(MyVector, MultiplePushBackAndPopBack) {
  MyVector v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);

  EXPECT_EQ(v.pop_back(), 4);
  EXPECT_EQ(v.size(), 3);

  auto actual = v.ConvertToStdVector();
  EXPECT_THAT(actual, ElementsAreArray({1, 2, 3}));
  EXPECT_EQ(v.get_error(), ErrorCode::kNoError);
}

//-----------------------------------------------------------------------------
TEST(MyVector, PushFrontAndPopFront) {
  MyVector v;
  v.push_front(1);
  EXPECT_EQ(v.size(), 1);
  EXPECT_EQ(v.pop_front(), 1);
  EXPECT_EQ(v.size(), 0);
  EXPECT_EQ(v.get_error(), ErrorCode::kNoError);
}

TEST(MyVector, MultiplePushFrontAndPopFront) {
  MyVector v;
  v.push_front(1);
  v.push_front(2);
  v.push_front(3);
  v.push_front(4);

  EXPECT_EQ(v.pop_front(), 4);
  EXPECT_EQ(v.size(), 3);

  auto actual = v.ConvertToStdVector();
  EXPECT_THAT(actual, ElementsAreArray({3, 2, 1}));
  EXPECT_EQ(v.get_error(), ErrorCode::kNoError);
}

//-----------------------------------------------------------------------------
TEST(MyVector, InsertInvalidIndex) {
  MyVector v;
  v.insert(5, 2);

  EXPECT_EQ(v.size(), 0);
  EXPECT_EQ(v.get_error(), ErrorCode::kIndexError);
}

TEST(MyVector, InsertValidIndexMiddle) {
  MyVector v;
  v.push_back(0);
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  v.insert(5, 2);

  EXPECT_THAT(v.ConvertToStdVector(), ElementsAreArray({0, 1, 2, 5, 3}));
  EXPECT_EQ(v.get_error(), ErrorCode::kNoError);
}

TEST(MyVector, InsertValidIndexAfterFront) {
  MyVector v;
  v.push_back(0);
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  v.insert(5, 0);

  EXPECT_THAT(v.ConvertToStdVector(), ElementsAreArray({0, 5, 1, 2, 3}));
  EXPECT_EQ(v.get_error(), ErrorCode::kNoError);
}

TEST(MyVector, InsertValidIndexFront) {
  MyVector v;
  v.push_back(0);
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  v.insert(5, -1);

  EXPECT_THAT(v.ConvertToStdVector(), ElementsAreArray({5, 0, 1, 2, 3}));
  EXPECT_EQ(v.get_error(), ErrorCode::kNoError);
}

TEST(MyVector, InsertValidIndexBack) {
  MyVector v;
  v.push_back(0);
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  v.insert(5, 3);

  EXPECT_THAT(v.ConvertToStdVector(), ElementsAreArray({0, 1, 2, 3, 5}));
  EXPECT_EQ(v.get_error(), ErrorCode::kNoError);
}
//-----------------------------------------------------------------------------
TEST(MyVector, FindNonExisting) {
  MyVector v;
  v.push_back(0);
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  EXPECT_EQ(v.find(5), -1);
  EXPECT_EQ(v.get_error(), ErrorCode::kNotFound);
}

TEST(MyVector, FindMiddle) {
  MyVector v;
  v.push_back(0);
  v.push_back(1);
  v.push_back(2);
  v.push_back(2);
  v.push_back(3);

  EXPECT_EQ(v.find(2), 2);
  EXPECT_EQ(v.get_error(), ErrorCode::kNoError);
}

TEST(MyVector, FindBack) {
  MyVector v;
  v.push_back(0);
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  EXPECT_EQ(v.find(3), 3);
  EXPECT_EQ(v.get_error(), ErrorCode::kNoError);
}

TEST(MyVector, FindFront) {
  MyVector v;
  v.push_back(0);
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  EXPECT_EQ(v.find(0), 0);
  EXPECT_EQ(v.get_error(), ErrorCode::kNoError);
}
//-----------------------------------------------------------------------------

TEST(MyVector, AtNonExisting) {
  MyVector v;
  v.push_back(0);
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  EXPECT_EQ(v.at(5), -1);
  EXPECT_EQ(v.get_error(), ErrorCode::kIndexError);
}
TEST(MyVector, AtFront) {
  MyVector v;
  v.push_back(0);
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  EXPECT_EQ(v.at(0), 0);
  EXPECT_EQ(v.get_error(), ErrorCode::kNoError);
}
TEST(MyVector, AtMiddle) {
  MyVector v;
  v.push_back(0);
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  EXPECT_EQ(v.at(2), 2);
  EXPECT_EQ(v.get_error(), ErrorCode::kNoError);
}

TEST(MyVector, AtBack) {
  MyVector v;
  v.push_back(0);
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  EXPECT_EQ(v.at(3), 3);
  EXPECT_EQ(v.get_error(), ErrorCode::kNoError);
}

//-----------------------------------------------------------------------------
TEST(MyVector, InsertEmpty) {
  MyVector v;
  v.insert(1, 0);

  EXPECT_EQ(v.at(0), -1);
  EXPECT_EQ(v.get_error(), ErrorCode::kIndexError);
}

TEST(MyVector, InsertEmptyWithMinus1) {
  MyVector v;
  v.insert(1, -1);

  EXPECT_THAT(v.ConvertToStdVector(), ElementsAreArray({1}));

  EXPECT_EQ(v.get_error(), ErrorCode::kNoError);
}

TEST(MyVector, InsertTwice) {
  MyVector v;
  v.insert(1, -1);
  EXPECT_EQ(v.at(0), 1);
  EXPECT_EQ(v.get_error(), ErrorCode::kNoError);

  v.insert(2, 0);
  EXPECT_EQ(v.at(1), 2);
  EXPECT_EQ(v.get_error(), ErrorCode::kNoError);
}

TEST(MyVector, InsertBeforeHead) {
  MyVector v;

  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.insert(0, -1);

  EXPECT_THAT(v.ConvertToStdVector(), ElementsAreArray({0, 1, 2, 3}));

  EXPECT_EQ(v.get_error(), ErrorCode::kNoError);
}

TEST(MyVector, InsertAtEnd) {
  MyVector v;
  v.push_back(0);
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.insert(4, 3);

  EXPECT_THAT(v.ConvertToStdVector(), ElementsAreArray({0, 1, 2, 3, 4}));

  EXPECT_EQ(v.get_error(), ErrorCode::kNoError);
}

TEST(MyVector, InsertAtMiddle) {
  MyVector v;
  v.push_back(0);
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.insert(5, 2);

  EXPECT_THAT(v.ConvertToStdVector(), ElementsAreArray({0, 1, 2, 5, 3}));

  EXPECT_EQ(v.get_error(), ErrorCode::kNoError);
}

TEST(MyVector, InsertAtOutside) {
  MyVector v;
  v.push_back(0);
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  v.insert(5, 12);
  EXPECT_EQ(v.get_error(), ErrorCode::kIndexError);

  EXPECT_THAT(v.ConvertToStdVector(), ElementsAreArray({0, 1, 2, 3}));
  EXPECT_EQ(v.get_error(), ErrorCode::kNoError);
}