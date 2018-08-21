// Copyright 2018 Caoyang Jiang

#include <experimental/filesystem>
#include <iostream>

int main()
{
  auto add = [](int x, int y) { return x + y; };
  std::apply(add, std::make_tuple(1, 2));

  std::string path = "/Users/caoyang";
  for (auto& p : std::experimental::filesystem::directory_iterator(path))
    std::cout << p << std::endl;
}
