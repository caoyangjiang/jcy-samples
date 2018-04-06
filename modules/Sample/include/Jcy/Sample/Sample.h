// Copyright 2018 Caoyang Jiang

#ifndef MODULES_SAMPLE_INCLUDE_JCY_SAMPLE_SAMPLE_H_
#define MODULES_SAMPLE_INCLUDE_JCY_SAMPLE_SAMPLE_H_

namespace jcy
{
class Sample
{
 public:
  Sample();
  ~Sample();

  /**
   * @brief      Prints a mysterious message
   */
  SAMPLE_DLL
  void PrintSomething() const;
};

}  // namespace jcy

#endif  // MODULES_SAMPLE_INCLUDE_JCY_SAMPLE_SAMPLE_H_
