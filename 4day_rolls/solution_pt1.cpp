#include <vector>
#include <iostream>
#include <fstream>

enum class symbols: char {
    ROLL = '@',
    NO_ROLL = '.'
};

bool operator==(char c, symbols s) {
    return static_cast<char>(s) == c;
}

bool operator==(symbols s, char c) {
    return c == s;
}

void peek_cell(std::vector<std::string>& field, int line, int column, int& counter) {
  char pos_char = field.at(line).at(column);

  if (pos_char == symbols::ROLL) {  
    int temp_counter = 0;

    for (int line_area = line - 1; line_area <= line + 1; line_area++) {
      if (line_area < 0 || line_area >= (int)field.size()) continue;

      for (int column_area = column - 1; column_area <= column + 1; column_area++) {
        if (column_area < 0 || column_area >= (int)field.at(line_area).size()) continue;
        if (line_area == line && column_area == column) continue;

        char now_pos = field.at(line_area).at(column_area);
        if (now_pos == symbols::ROLL) {  
          temp_counter++;
        }
      }
    }

    if (temp_counter < 4) {
      counter++;
    }
  }
}

int main(void) {
  std::vector<std::string> field = {};
  std::ifstream fd("input.txt");

  if (!fd.is_open()) {
    std::cerr << "failing to read input" << "\n";
    return -1;
  }

  std::string temp_buff;
  int unicounter = 0;

  while (std::getline(fd, temp_buff)) {
    field.push_back(temp_buff);
  }

  for (int i = 0; i < (int)field.size(); i++) {
    for (int j = 0; j < (int)field.at(i).size(); j++) {
      peek_cell(field, i, j, unicounter);
    }
  }

  std::cout << unicounter << "\n";
  fd.close();
  return 0;
}
