#ifndef ASTASSIGN_H_
#define ASTASSIGN_H_

#include "ASTExpression.h"
#include "ASTVar.h"

#include <memory>

namespace cool {
class ASTAssign : public ASTNode {

public:
  virtual ~ASTAssign() {}
  ASTAssign(ASTVarPtr var, ASTExpressionPtr expr): _var(std::move(var)), _expr(std::move(expr)) {}

private:
  ASTVarPtr _var;
  ASTExpressionPtr _expr;

};

typedef std::unique_ptr<ASTAssign> ASTAssignPtr;
}
#endif /* ASTASSIGN_H_ */
