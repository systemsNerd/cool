#ifndef ASTCASE_H_
#define ASTCASE_H_

#include "ASTNode.h"
#include <memory>

namespace cool {
class ASTCase : public ASTNode {

public:
  virtual ~ASTCase() {}
};

typedef std::unique_ptr<ASTCase> ASTCasePtr;
}
#endif /* ASTCASE_H_ */
