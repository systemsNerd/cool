#ifndef ASTEXPRESSION_H_
#define ASTEXPRESSION_H_

#include "ASTNode.h"

#include <iostream>
#include <memory>

namespace cool {
class ASTExpression : ASTNode {

public:
  virtual ~ASTExpression() {}
  ASTExpression() {}
};

typedef std::unique_ptr<ASTExpression> ASTExpressionPtr;
}
#endif /* ASTEXPRESSION_H_ */
