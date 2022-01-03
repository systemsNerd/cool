/* Copyright (c) 2012-2017 The ANTLR Project. All rights reserved.
 * Use of this file is governed by the BSD 3-clause license that
 * can be found in the LICENSE.txt file in the project root.
 */

//
//  main.cpp
//  antlr4-cpp-demo
//
//  Created by Mike Lischke on 13.03.16.
//

#include <iostream>
#include <experimental/filesystem>
// #include <filesystem>

#include "antlr4-runtime.h"
#include "CoolLexer.h"
#include "CoolParser.h"

using namespace antlrcpptest;
using namespace antlr4;

static void parse(const std::string& filename)
{

  std::ifstream t(filename);
  std::stringstream buffer;
  buffer << t.rdbuf();

  ANTLRInputStream input(buffer);
  CoolLexer lexer(&input);
  CommonTokenStream tokens(&lexer);

  tokens.fill();
  for (auto token : tokens.getTokens())
  {
    std::cout << token->toString() << std::endl;
  }

  CoolParser parser(&tokens);
  tree::ParseTree *tree = parser.program();

  std::cout << tree->toStringTree(&parser) << std::endl;
}

int main(int , const char **) {

  auto path = "../tests/syntactic/";
  for (const auto &entry : std::experimental::filesystem::directory_iterator(path)) {
    std::cout << entry.path() << std::endl;
    parse(entry.path());
  }
    
  return 0;

}
