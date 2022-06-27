#ifndef ASTPROGRAM_H_
#define ASTPROGRAM_H_

#include "ASTNode.h"
#include "ASTClass.h"

#include <memory>
#include <vector>

namespace cool {
class ASTProgram : public ASTNode {

public:
  virtual ~ASTProgram() {}
  
  void addClass(std::unique_ptr<ASTClass> C) {
    classes.push_back(std::move(C));
  }

private:
  std::vector<std::unique_ptr<ASTClass>> classes;
};

typedef std::unique_ptr<ASTProgram> ASTProgramPtr;
}
#endif /* ASTPROGRAM_H_ */
