#ifndef ASTBINAROPERATOR_H_
#define ASTBINAROPERATOR_H_

#include "ASTNode.h"
#include "ASTExpression.h"

#include <memory>

namespace cool {
class ASTBinarOperator : public ASTNode {

public:
  virtual ~ASTBinarOperator() {}
  ASTBinarOperator(ASTExpressionPtr left,
                   ASTExpressionPtr right,
                   const std::string &op) : 
                   _left(std::move(left)),
                   _right(std::move(right)),
                   _operator(op) {}
                                                  
                                                  

private:
  ASTExpressionPtr _left;
  ASTExpressionPtr _right;
  std::string _operator;
  // TODO it may be good to create an enumeration
};

typedef std::unique_ptr<ASTBinarOperator> ASTBinarOperatorPtr;
}
#endif /* ASTBINAROPERATOR_H_ */
