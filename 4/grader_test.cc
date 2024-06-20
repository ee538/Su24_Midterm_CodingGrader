#include <iostream>
#include <vector>

#include "q.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
using ::testing::ElementsAreArray;
//-----------------------------------------------------------------------------s
template <class T> void PrintCollection(T &input) {
  std::cout << "{ ";
  unsigned int count = 0;
  for (auto n : input) {
    count++;
    std::cout << n;
    if (count < input.size())
      std::cout << ", ";
  }
  std::cout << " }" << std::endl;
}
//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
using namespace std;

// Test the store method with non-zero and zero values
TEST(PlayerScoresTest, StoreMethod) {
  vector<int> scores = {10, 0, 0, 20, 30};
  PlayerScores player;
  player.store(scores);

  vector<int> expectedEfficientVector = {10, 0, 0, 20, 30};
  vector<int> resultVector = player.convertToVector();

  ASSERT_EQ(resultVector, expectedEfficientVector);
}

// Test calculateCompoundScore with two vectors of the same size
TEST(PlayerScoresTest, CalculateCompoundScore) {
  vector<int> scores1 = {10, 0, 0, 20, 1};
  vector<int> scores2 = {0, 15, 0, 5, 2};

  PlayerScores player1, player2;
  player1.store(scores1);
  player2.store(scores2);

  int compoundScore = player1.calculateCompoundScore(player2);
  ASSERT_EQ(compoundScore, 53);
}

// Test with empty vectors
TEST(PlayerScoresTest, EmptyVectors) {
  vector<int> scores1 = {};
  vector<int> scores2 = {};

  PlayerScores player1, player2;
  player1.store(scores1);
  player2.store(scores2);

  int compoundScore = player1.calculateCompoundScore(player2);
  ASSERT_EQ(compoundScore, 0);
}

// Test with vectors containing only zeros
TEST(PlayerScoresTest, OnlyZeroVectors) {
  vector<int> scores1 = {0, 0, 0};
  vector<int> scores2 = {0, 0, 0};

  PlayerScores player1, player2;
  player1.store(scores1);
  player2.store(scores2);

  int compoundScore = player1.calculateCompoundScore(player2);
  ASSERT_EQ(compoundScore, 0);
}

// Test with large vectors to ensure performance is reasonable
TEST(PlayerScoresTest, LargeVectors) {
  vector<int> scores1(100000, 1); // 100,000 ones
  vector<int> scores2(100000, 2); // 100,000 twos

  PlayerScores player1, player2;
  player1.store(scores1);
  player2.store(scores2);

  int compoundScore = player1.calculateCompoundScore(player2);
  ASSERT_EQ(compoundScore, 300000);
}

// Test the convertToVector method with non-zero and zero values
TEST(PlayerScoresTest, ConvertToVector) {
  vector<int> scores = {10, 0, 0, 20, 30};
  PlayerScores player;
  player.store(scores);

  vector<int> resultVector = player.convertToVector();
  ASSERT_EQ(resultVector, scores);
}

// Test convertToVector with an empty vector
TEST(PlayerScoresTest, ConvertToVectorEmpty) {
  vector<int> scores = {};
  PlayerScores player;
  player.store(scores);

  vector<int> resultVector = player.convertToVector();
  ASSERT_EQ(resultVector, scores);
}

// Test convertToVector with a vector containing only zeros
TEST(PlayerScoresTest, ConvertToVectorOnlyZeros) {
  vector<int> scores = {0, 0, 0};
  PlayerScores player;
  player.store(scores);

  vector<int> resultVector = player.convertToVector();
  ASSERT_EQ(resultVector, scores);
}

// Test convertToVector with a mix of non-zero and zero values
TEST(PlayerScoresTest, ConvertToVectorMixed) {
  vector<int> scores = {1, 0, 3, 0, 0, 5};
  PlayerScores player;
  player.store(scores);

  vector<int> resultVector = player.convertToVector();
  ASSERT_EQ(resultVector, scores);
}

// Test convertToVector with large vector to ensure performance
TEST(PlayerScoresTest, ConvertToVectorLarge) {
  vector<int> scores(100000, 0); // 100,000 zeros
  scores[5000] = 1;
  scores[99999] = 2;

  PlayerScores player;
  player.store(scores);

  vector<int> resultVector = player.convertToVector();
  ASSERT_EQ(resultVector, scores);
}
