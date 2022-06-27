#ifndef ASTCASEBRANCH_H_
#define ASTCASEBRANCH_H_

#include "ASTNode.h"
#include <memory>

namespace cool {
class ASTCaseBranch : ASTNode {

public:
  virtual ~ASTCaseBranch() {}
};

typedef std::unique_ptr<ASTCaseBranch> ASTCaseBranchPtr;
}
#endif /* ASTCASEBRANCH_H_ */
