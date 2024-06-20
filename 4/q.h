#include <iostream>
#include <map>
#include <vector>

// Create a class PlayerScores that stores the scores of players in a team for
// various games in an efficient way. We expect many zero scores. To be
// efficient, we only store the non-zero scores.

// Example:
// vector<int> scores1 = {10, 0, 0, 20, 1};
// vector<int> scores2 = {0, 15, 0, 5, 2};

// PlayerScores player1, player2;
// player1.store(scores1);
// player2.store(scores2);

// int compoundScore = player1.calculateCompoundScore(player2);

// Output:
// Compound Score = 10+0 + 0+15 + 0+0 + 20+5 + 1+2 = 53

class PlayerScores {
public:
  // Stores the given inefficient scores in an efficient way.
  // That means it only stores the non-zero values.
  void store(const std::vector<int> &vector);

  // Calculates the sum of the other efficient vector with this efficient
  // vector.
  // Assume that the other vector is the same size as this vector.
  int calculateCompoundScore(PlayerScores &otherPlayerScores);

  // Converts the efficient scores to an inefficient vector, i.e. the zero
  // values are back.
  std::vector<int> convertToVector();


public:
  std::map<int, int> efficientScores;

private:
  int originalSize;
};
