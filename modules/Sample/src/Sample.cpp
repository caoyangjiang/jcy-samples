// Copyright 2018 Caoyang Jiang

#include "Jcy/Sample/Sample.h"

WINDOWS_DISABLE_ALL_WARNING
#include <iostream>
WINDOWS_ENABLE_ALL_WARNING

namespace jcy
{
Sample::Sample()
{
}

Sample::~Sample()
{
}

void Sample::PrintSomething() const
{
  std::cout << "you passed the test!" << std::endl;
}

}  // namespace jcy
