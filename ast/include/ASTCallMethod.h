#ifndef ASTCALLMETHOD_H_
#define ASTCALLMETHOD_H_

#include "ASTNode.h"
#include "ASTExpression.h"
#include <memory>

// TODO what is this used for
namespace cool {
class ASTCallMethod : public ASTNode {

public:
  virtual ~ASTCallMethod() {}
  
private:
  std::string _name;
  std::vector<ASTExpressionPtr> _params;
};

typedef std::unique_ptr<ASTCallMethod> ASTCallMethodPtr;
}
#endif /* ASTCALLMETHOD_H_ */
