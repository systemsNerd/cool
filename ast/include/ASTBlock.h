#ifndef ASTBLOCK_H_
#define ASTBLOCK_H_

#include "ASTNode.h"
#include "ASTExpression.h"

#include <memory>

namespace cool {
class ASTBlock : public ASTNode {

public:
  virtual ~ASTBlock() {}

  void ASTBlockAddExpression(ASTExpressionPtr expr) {
    _expressions.push_back(std::move(expr));
  }

private:
  std::vector<ASTExpressionPtr> _expressions;
};

typedef std::unique_ptr<ASTBlock> ASTBlockPtr;
}
#endif /* ASTBLOCK_H_ */
